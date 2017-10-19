#include "network.hpp"
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

Network::Network() {}

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
		neurons_[i] = nullptr;
	}
}

void Network::update(const step& t, std::ofstream& file) {
	assert(neurons_.size() != 0);
	bool spike(false);
	for (size_t i(0); i < neurons_.size(); ++i) {
		spike = false;
		assert(neurons_[i] != nullptr);
		storePotential(i, file);
		spike = neurons_[i]->update(t);
		if (spike) {
			assert(neurons_[i] != nullptr);
			//give to the connected neuron the spike
			for (size_t j(0); j < connexion_[i].size(); ++j) {
				assert(neurons_[connexion_[i][j]] != nullptr);
				neurons_[connexion_[i][j]]-> receive(J, neurons_[i]->getClock() + DELAY);
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

void Network::storePotential(const Index& i, std::ofstream& file) const {
		file << "Neuron " << i+1 << " : potential ";
		neurons_[i]->storePotentialMembrane(file);
}
