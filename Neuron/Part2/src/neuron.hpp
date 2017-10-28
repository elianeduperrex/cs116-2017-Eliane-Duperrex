/*!A neuron class */
#ifndef NEURON_HPP
#define NEURON_HPP
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
#include "constant.hpp"

class Neuron {
	private :
		
		double membrane_potential_; //!<membrane potential
		
		
		std::vector<step> times_; //!<times when spikes occure
		
		step clock_; //!<specific clock for the neuron
		
		
		bool isRefract_; //!<tell if the neuron is refractory
		
		
		//Index index_; //!<index of the neuron in the network
		
		
		double input_current_; /*!< input current */
		
		bool isExcitatory_; //tells if a neuron is excitatory or inibitory
		
		//to store the time when the neuron will receive the spike from another one with each J
		std::array<double, BufferSize> timeDelayBuffer_;
		//test if the neuron is refractory at time t, if so isRefract_ = true
		void isRefractory(const step& t);
		step poissonGenerator();
	
	public:	
			
		Neuron(); 
		Neuron(const bool& isExcitatory);
		~Neuron();
		
		//getters
		/**
		 * Getter
		 * @return membrane potential
		 * */
		double getMembranePotential() const; 
		/**
		 * Getter
		 * @return total number of spikes
		 *  */
		Index getTimeSize() const; //check to change name
		/**
		 * Getter
		 * @param number of spike
		 * @return a specific spike time
		 * */
		step getTimeSpike(const int& i) const;
		/**
		 * Getter
		 * @return vector of the different times of the spike
		 * */
		std::vector<step> getTimeSpikeTab() const;
		/**
		 * Getter
		 * @return if the neuron is refractory
		 * */
		bool getRefractoryState() const;
		//Index getIndex() const;
		//step getClock() const;
	
		//void setMembranePotential(const double& memb);
		/**
		 * Setter of input current
		 * @param input current
		 * */
		void setInputCurrent(const double& input);
		//void setIsExcitatory(const bool& isExcitatory);
		
		//update the neuron
		/**
		 * Update
		 * @param step
		 * @return if spike or not
		 * */
		bool update(const step& t);
		//when a neuron receive an amplitude J
		/**
		 * neuron receive a spike from another one
		 * @param amplitude
		 * */
		void receive(const double& j);
		//overload of the method, used in network to store the time with the delay and the particular J
		/**
		 * neuron receive a spike with a delay
		 * @param amplitude
		 * @param delay
		 * */
		void receive(const double& j, const step& t);
		
		/**
		 * add a time of a spike in vector times_
		 * @param time of spike
		 * */
		void addSpikeTime(const step& t); //pe mettre en time
		 
		//methods to store data in a file
		/**
		 * store the vector times_ in a file
		 * @param file where we store the data
		 * */
		void storeSpikeTime(std::ofstream& file) const;
		/**
		 * store the membrane potential in a file
		 * @param file where we store the data
		 * */	
		void storePotentialMembrane(std::ofstream& file) const;
		
		
};

#endif


