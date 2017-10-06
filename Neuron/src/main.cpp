#include <iostream>
#include <vector>
#include <fstream>

#include "neuron.hpp"

using namespace std;

const double h = 0.1;

const double tau = 20.0;
const double C = 1;
//membrane resistance
const double R = (tau/C);
const double V_threshold = 20;
//to run the simulation faster
const double n = 1;


int main() {
	Neuron neuron;
	double  simTime(T_SART);
	double input_current_ext(0.0);
	double a, b;
	ofstream entree_donne("times_spike");

	
	cout << "Choose an external current : ";
	cin >> input_current_ext;
	cout << "Choose a time interval: ";
	cin >> a;
	cin >> b;
	cout << "[ " << a << ", " << b << ")" << endl;
	cout << "ou ";
	double input_current;
	cout<<"it " << simTime;
	cout << " V " << neuron.getMembranePotential() << " spike " << neuron.getSpikeNumber() << " ";
	
	cout << " input: " << input_current_ext << endl;
	cout << neuron.getTimeSize() << " ";
	int i(0);
	while (simTime <= T_STOP) {
		//input current = i(t)
		
		if (simTime >= a and simTime < b) {
			
			++i;
			input_current = input_current_ext;
		 
		 } else { 
			
		 	input_current = 0.0;
		 }
		if (neuron.refractory(simTime)) {

			neuron.setMembranePotential(0.0);
		
		} else if (neuron.getMembranePotential() >= V_threshold) {

			 neuron.addSpikeTime(simTime);
			
		}
		if (entree_donne.fail()) {
		cerr << "Erreur ";
	} else {
		entree_donne << neuron.getMembranePotential() << endl;
	}
		neuron.update(simTime+n*h, input_current);
		
		simTime = simTime + n*h;
		
	
	}
	cout << "inpt curr aff " << i << endl;
	cout << neuron.getTimeSize();
	
	
		
	
	if (entree_donne.fail()) {
		cerr << "Erreur ";
	} else {
		entree_donne << "Spike time : " << endl;
		for (int i(0); i < neuron.getTimeSize(); ++i) {
			entree_donne << neuron.getTimeSpike(i) << endl;
		}
		entree_donne.close();
	}
	return 0;
}

