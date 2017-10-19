#include <vector>
#include <iostream>
#include "neuron.hpp"
#include "constant.hpp"

#ifndef NETWORK_HPP
#define NETWORK_HPP
using namespace std;

class Network {
	private :
		vector<Neuron*> neurons_;
		vector<vector<Index> > connexion_;
		
	public :
		Network();
		Network(vector<Neuron> neurons, vector<vector<Index> > connexion) ;
		~Network();
		void setConnexion(const Neuron& neur);
		void update(const step& t, std::ofstream& file);
		
		//method to store the spike time of each neurons
		void storeTimeSpike(std::ofstream& file) const;
		void storePotential(const Index& i, std::ofstream& file) const;
		void setInputCurrentFirst(const double& input_current);
};

#endif
