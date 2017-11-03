#include "neuron.hpp"
#include <iostream>
#include <cassert>
#include <random>

//when there hasn't been any spike, the neuron cannot be refractory
Neuron::Neuron() : 	membrane_potential_(0.0), clock_(T_START), 
					isRefract_(false), input_current_(0.0), isExcitatory_(true) {
	for (auto& ind : timeDelayBuffer_) {
		ind = 0.0;
		}
}
Neuron::Neuron(const bool& isExcitatory) : 	membrane_potential_(0.0), clock_(T_START), 
					isRefract_(false), input_current_(0.0), isExcitatory_(isExcitatory) {
	for (auto& ind : timeDelayBuffer_) {
		ind = 0.0;
		}
}

Neuron::~Neuron() {}

//update the membrane potential of the neuron depending on if it is refractory
bool Neuron::update(const step& t, const int& poisson) {
	bool hasSpike(false);
	const step T_STOP_ = clock_ + t;
	while (clock_ < T_STOP_) {
		if (membrane_potential_ >= V_THRESHOLD) {
			addSpikeTime(clock_);
			hasSpike = true;	
			isRefract_ = true;
		}
		isRefractory(clock_); 
		if (!isRefract_) {
			membrane_potential_ = C1*membrane_potential_ + input_current_*C2;
			size_t size(timeDelayBuffer_.size());
			membrane_potential_ += timeDelayBuffer_[clock_%size] + poisson*J;
			
			timeDelayBuffer_[clock_%size] = 0.0;
		} else {
			membrane_potential_ = V_RESET;
		}
		clock_ ++;
	}
	
	return hasSpike;
}

//return if the neuron is refractory
void  Neuron::isRefractory(const step& t) {		
	//for te first loop, the vector is empty 
	if (times_.size() != 0) {		
		isRefract_ = t-times_.back() < TAU_REFRACTORY;	
	} 		
}
//different getters
Index Neuron::getTimeSize() const {
	return times_.size();
}

step Neuron::getTimeSpike(const int& i) const {
	return times_[i];
}

double Neuron::getMembranePotential() const {
	return membrane_potential_;
}
std::vector<step> Neuron::getTimeSpikeTab() const {
	return times_;
}

bool Neuron::isExcitatory() const {
	return isExcitatory_;
}

bool Neuron::getRefractoryState() const {
	return isRefract_;
}


//add a new spike
void Neuron::addSpikeTime(const step& t) {
	times_.push_back(t);
}

//store the times when spikes occured in a file
void Neuron::storeSpikeTime(std::ofstream& file, Index j) const {
	
	if (file.fail()) {
		std::cerr << "Error ";
	} else {
		for (size_t i(0); i < times_.size(); ++i) {
			file << times_[i]*H << '\t' << j << '\n';
		}
	}		
}

//store the potential in a file
void Neuron::storePotentialMembrane(std::ofstream& file) const {
	if (file.fail()) {
			std::cerr << "Error ";
		} else {
			file << membrane_potential_ << std::endl;
		}	
}

void Neuron::setInputCurrent(const double& input) {
	input_current_ = input;
}

void Neuron::receive(const double& j) {
	membrane_potential_ += j;
}

void Neuron::receive(const double& j, const step& t) {
	size_t size(timeDelayBuffer_.size());
	assert((clock_+t)%size < size);
	timeDelayBuffer_[(clock_+t)%size] += j;
}


