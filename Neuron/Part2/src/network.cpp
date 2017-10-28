#include "network.hpp"
#include <vector>
#include <cassert>
#include <iostream>
#include <random>
using namespace std;

Network::Network() {
	//initialisation of the network
	bool isExcitatory(true);
	for (int i(0); i < N_TOTAL; ++i) {
		//to set 2500 neurons inibitory
		if (i > N_EXCITATORY) {
			isExcitatory = false;
		}
		Neuron neur(isExcitatory);
		Neuron* neuron(new Neuron (neur));
		assert (neuron != nullptr);
		neurons_.push_back(neuron);
	}
	//connexion_.size() = (neurons_.size());
	assert(neurons_.size() == N_TOTAL);
	connexion_.resize(N_TOTAL);
	//connexion_[0].resize(N_TOTAL);
	for (int i(0); i < connexion_.size() ; ++i) {
		connexion_[i].resize(N_TOTAL);
		//to do only 10% of connexion
		for(int k(0); k < 0.1*N_TOTAL; ++k) {
			std::random_device r;
			std::default_random_engine generator(r());
			int indexConnexion(0);
			
			if (k < 0.1*N_EXCITATORY) {	
				uniform_int_distribution<int> distrib(0,N_EXCITATORY -1);
				indexConnexion = distrib(generator);
			} else {
				uniform_int_distribution<int> distrib(N_EXCITATORY,N_TOTAL -1);
				indexConnexion = distrib(generator);
			}
			assert(indexConnexion < connexion_[i].size());
			connexion_[i][indexConnexion] += 1;
		}
	}
}
void Network::storeConnexion(ofstream& file) {
	file << "Neurons connexions " << endl;
	for (int i(0); i < connexion_.size(); ++i) {
		for (int j(0); j < connexion_[i].size(); ++j) {
			file << connexion_[i][j] << " ";
		}
		file << endl;
	}
}
Network::Network(vector<Neuron> neurons, vector<vector<Index> > connexion) {
	assert(neurons.size() !=0);
	for (size_t i(0); i < neurons.size(); ++i) {
		Neuron* neuro(new Neuron (neurons[i]));
		neurons_.push_back(neuro);
	}
	for (size_t i(0); i < connexion.size() ; ++i) {
		connexion_.push_back(connexion[i]);
		for (size_t j(0); j < connexion[i].size() ; ++j) {
			connexion_[i][j] = (connexion[i][j]);
		}
	}
}

Network::~Network () {
	for (size_t i(0); i < neurons_.size(); ++i) {
		delete neurons_[i];
		//neurons_[i] = nullptr;
	}
}

void Network::update(const step& t) {
	assert(neurons_.size() != 0);
	bool spike(false);
	for (size_t i(0); i < neurons_.size(); ++i) {
		spike = false;
		assert(neurons_[i] != nullptr);
		//storePotential(i, file);
		spike = neurons_[i]->update(t);
		if (spike) {
			assert(neurons_[i] != nullptr);
			//give the spike to the connected neurons
			//in column are the neurons and in ligns are the receveid connexion 
			for (size_t j(0); j < connexion_[i].size(); ++j) {
				assert(neurons_[connexion_[j][i]] != nullptr);
				neurons_[connexion_[j][i]]-> receive(J, DELAY);
			}
		}
	}
}

void Network::storeTimeSpike(std::ofstream& file) const {
	int i(1);
	for (auto& neuron : neurons_) {
		file << "Spike time of neuron " << i << " : " << endl;
		neuron -> storeSpikeTime(file);
		file << endl;
		++i;
	}
}

void Network::setInputCurrentFirst(const double& input_current) {
	neurons_[0]->setInputCurrent(input_current);
	assert(neurons_[0]->getInputCurrent() == input_current);
}

Index Network::getNbNeurons() const {
	return neurons_.size();
}
void Network::storePotential(const Index& i, std::ofstream& file) const {
		file << "Neuron " << i+1 << " : potential ";
		neurons_[i]->storePotentialMembrane(file);
}

double Network::getMembranePotentialNeuron( Index i) {
	return neurons_[i]->getMembranePotential();
}
