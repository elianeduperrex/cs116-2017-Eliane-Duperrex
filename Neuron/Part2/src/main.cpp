#include <iostream>

#include <fstream>
#include <cassert>
#include <time.h>
#include "neuron.hpp"
#include "constant.hpp"
#include "network.hpp"

using namespace std;
//test the connexion between 2 neurons
bool testConnexion();
//test the connexion with buffer
bool testBuffer();
//run the test
void runTest();
//initialise the time interval and the external input current
void initialiser(step& a, step& b, double& current);


int main() {
	clock_t begin = clock();
	step simTime(T_START);
	double input_current_ext(0.0);
	step a, b;
	//file where the data would be collected
	ofstream entree_donne("times_spike.txt");
	ofstream conn("connexion.txt");

	//ask the user to enter data for the time interval and the membrane potential
	initialiser(a, b, input_current_ext);

	
	Network networkNeuron;
	cerr << "Network created " << '\n';
	double input_current(0.0);
	
	//run simulation
	while (simTime <= T_STOP) {
		if (((simTime-T_START)/(double)(T_STOP-T_START)) > 0.1) {
			cerr << " sime"  << (simTime-T_START)/(double)(T_STOP-T_START)*100 << " %" << '\n';
		}
		if (simTime >= a and simTime < b) {
			input_current = input_current_ext;
		} else { 
		 	input_current = 0.0;
		}	
		//networkNeuron.setInputCurrentFirst(input_current);
		networkNeuron.update(N);
		simTime += N;
	}
	//to store the spike times
	networkNeuron.storeTimeSpike(entree_donne);
	//networkNeuron.storeConnexion(conn);
	entree_donne.close();
	conn.close();
	runTest();
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time " << time_spent << endl;
	return 0;
}

void initialiser(step& a, step& b, double& input_current_ext) {
	cout << "Choose an external current: ";
	cin >> input_current_ext;
	double s(0.0), t(0.0);
	do {	
		cout << "Choose a time interval: (a < b), a and b must be positive numbers ";
		cin >> s;
		cin >> t;
		
	} while (s >= t or s < 0.0 or t < 0.0) ;
	a=s/H;
	b=t/H;
	cout << "[a,b] = [" << s << ", " << t << "]" << endl;
}

bool testConnexion () {
	Neuron neur;
	bool result(false);
	/*step time(T_START);
	neur.receive(J, time);
	//creation of a neuron and give it that a neuron connected to it spiked
	//at initialisation the membrane potential is at 0.0 -> the potential varies only with J 
	neur.update(N);
	if (neur.getMembranePotential() == J) {
		result  = true;
	}*/
	return result;
}

bool testBuffer() {
	bool result(false);
	//V change with D
	/*/Neuron neuron1;
	step t(T_START);
	neuron1.receive(J, t + DELAY);
	for (int i(0); i <= DELAY; ++i) {
		neuron1.update(N);
	}	
	
	if (neuron1.getMembranePotential() == J) {
		result = true;
	}	*/
	return result;
}

void runTest() {
	cout << "Connexion test is";
	if (testConnexion()) {
			cout << " passed ";
		} else {
			cout << " failed ";
	}	
	cout << endl;
	cout << "Buffer test is";
	if (testBuffer()) {
			cout << " passed ";
		} else {
			cout << " failed ";
	}	
	cout << endl;
}
