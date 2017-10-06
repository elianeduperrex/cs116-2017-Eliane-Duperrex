#ifndef NEURON_HPP
#define NEURON_HPP

#include <cmath>
#include <vector>

class Neuron {
	private :
		//membrane potential
		double membrane_potential_;
		
		//number of spikes
		int spike_number_;
		
		//times when spikes occure
		std::vector<double> times_;
		
		//getter and setter and constructor
	
	public:
		Neuron();
		Neuron(const double& memPot, const int& spikeNb);
		~Neuron();
		// setter
		void setMembranePotential(const double& pot);
		void setSpikeNumber(const int& number);
		//getter
		double getMembranePotential() const;	
		int getSpikeNumber() const;
		int getTimeSize() const;
		double getTimeSpike(const int& i) const;
		
		void update(const double& t, const double& input_current);
		void addSpikeTime(const double& t);
		bool refractory(const double& t) const;
		

};

#endif

