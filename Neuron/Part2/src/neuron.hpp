#ifndef NEURON_HPP
#define NEURON_HPP
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
#include "constant.hpp"

class Neuron {
	private :
		//membrane potential
		double membrane_potential_;
		
		//times when spikes occure
		std::vector<step> times_;
		
		step clock_;
		
		//tell if the neuron is refractory
		bool isRefract_;
		
		//index of the neuron in the network
		Index index_;
		
		//input current
		double input_current_;
		
		//to store the time when the neuron will receive the spike from another one with each J
		//std::vector<std::vector<double> > timeDelay;
		
		std::array<double, BufferSize> timeDelayBuffer_;
		//test if the neuron is refractory at time t, if so isRefract_ = true
		void isRefractory(const step& t);
	
	public:		
		Neuron();
		~Neuron();
		
		//getters
		double getMembranePotential() const;	
		Index getTimeSize() const;
		step getTimeSpike(const int& i) const;
		std::vector<step> getTimeSpikeTab() const;
		bool getRefractoryState() const;
		Index getIndex() const;
		step getClock() const;
		double getInputCurrent() const;
		void setMembranePotential(const double& memb);
		void setInputCurrent(const double& input);
		//update the neuron
		bool update(const step& t);
		//when a neuron receive an amplitude J
		void receive(const double& j);
		//overload of the method, used in network to store the time with the delay and the particular J
		void receive(const double& j, const step& t);
		
		void addSpikeTime(const step& t);
		
		//methods to store data in a file
		void storeSpikeTime(std::ofstream& file) const;	
		void storePotentialMembrane(std::ofstream& file) const;
		
		
};

#endif


