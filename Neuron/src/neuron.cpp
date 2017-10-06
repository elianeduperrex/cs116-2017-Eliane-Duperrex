#include "neuron.hpp"
 #include <iostream>
const double tau = 20.0;
const double h = 0.1;
const double R = 20;
const double tau_ref = 2.0;

Neuron::Neuron(const double& memPot, const int& spikeNb) : membrane_potential_(-70) {}

Neuron::~Neuron() {}

Neuron::Neuron() : membrane_potential_(0), spike_number_(0) /*, times_(0) */{}

void Neuron::update(const double& t, const double& input_current) {
		if (!refractory(t)) {
	membrane_potential_ = exp(-h/tau)*membrane_potential_	+ input_current*R*(1-exp(-h/tau));
		} else {
			membrane_potential_ = exp(-h/tau)*membrane_potential_;
		}

}

bool Neuron::refractory(const double& t) const {
	//for the first loop, the vector is empty 
	if (times_.size() != 0) {
		
		return ((t-times_.back()) <= tau_ref);
		
	} else {

	//when there hasn't been any spike, the neuron cannot be refractory
		return false;
	}
}

int Neuron::getTimeSize() const {
	return times_.size();
}

double Neuron::getTimeSpike(const int& i) const {
	return times_[i];
}

void Neuron::addSpikeTime(const double& t) {
	times_.push_back(t);
}

double Neuron::getMembranePotential() const {
	return membrane_potential_;
}

int Neuron::getSpikeNumber() const {
	return spike_number_;
}
void Neuron::setSpikeNumber(const int& number) {
	spike_number_ = number;
}
void Neuron::setMembranePotential(const double& pot) {
	membrane_potential_ = pot;
}
