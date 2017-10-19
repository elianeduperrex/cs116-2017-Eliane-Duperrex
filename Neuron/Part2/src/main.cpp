#include <iostream>

#include <fstream>
#include <cassert>

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
	step simTime(T_START);
	double input_current_ext(0.0);
	step a, b;
	//file where the data would be collected
	ofstream entree_donne("times_spike");

	//ask the user to enter data for the time interval and the membrane potential
	initialiser(a, b, input_current_ext);

	//initialisation of the network
	vector<Neuron> neurons;
	Neuron neuron1, neuron2,neuron3;
	neurons.push_back((neuron1));
	neurons.push_back((neuron2));
	neurons.push_back(neuron3);
	vector<vector<Index> > connexion(neurons.size());
	connexion[0].push_back(1);
	connexion[1].push_back(0);
	connexion[0].push_back(2);
	connexion[2].push_back(0);	
	assert(connexion.size() != 0);
	Network networkNeuron(neurons, connexion);
	
	double input_current(0.0);
	
	//run simulation
	while (simTime <= T_STOP) {
		if (simTime >= a and simTime < b) {
			input_current = input_current_ext;
		} else { 
		 	input_current = 0.0;
		}	
		networkNeuron.setInputCurrentFirst(input_current);
		networkNeuron.update(N, entree_donne);
		simTime += N;
	}
	//to store the spike times
	networkNeuron.storeTimeSpike(entree_donne);
	entree_donne.close();
	runTest();
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
	step time(T_START);
	neur.receive(J, time);
	//creation of a neuron and give it that a neuron connected to it spiked
	//at initialisation the membrane potential is at 0.0 -> the potential varies only with J 
	neur.update(N);
	if (neur.getMembranePotential() == J) {
		result  = true;
	}
	return result;
}

bool testBuffer() {
	bool result(false);
	//V change with D
	Neuron neuron1;
	step t(T_START);
	neuron1.receive(J, t + DELAY);
	for (int i(0); i <= DELAY; ++i) {
		neuron1.update(N);
	}	
	
	if (neuron1.getMembranePotential() == J) {
		result = true;
	}	
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
