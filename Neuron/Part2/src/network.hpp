/*!A network class */
#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <vector>
#include <iostream>
#include "neuron.hpp"
#include "constant.hpp"
#include <array>
using namespace std;

class Network {
		
	public :
		/**
		 * Constructor by default
		 * */
		Network();
		/**
		 * Constructor with initialisation
		 * @param vector<Neuron>
		 * @param vector of connexion
		*/
		Network(const int& excitat_numb, const int& inhibit_numb, 
				const int& excitat_connexion, const int& inhibit_connexion);
		/**
		 * Destructor which delete the vector of pointers on neurons
		 * */
		~Network();
		/**
		 * GETTER
		 * @return total number of neuron
		 * */
		Index getNbNeurons() const;
		/**
		 * GETTER
		 * @return connexion of matrix size
		 * */
		 array<Index, 2> getConnexionMatrixSize() const;
		/**
		 * GETTER
		 * @param index of the neuron we want to have the membrane potential
		 * @return membrane potential of a specific neuron i
		 * */
		double getMembranePotentialNeuron( Index i);
		/**
		 * update the network with updating all the neurons in the vector neurons_ 
		 * if a neuron spike then he transfer his amplitude to all the neurons he is connected to
		 * @param time step
		 * */
		void update(const step& t);
		/**
		 * method to store the spike time of each neurons
		 * @param file where data would be collected
		 * */
		void storeTimeSpike(std::ofstream& file) const;
		/**
		 * method to store the potential of a specific neuron
		 * */
		void storePotential(const Index& i, std::ofstream& file) const;
		void storeConnexion(ofstream& file);
		
		
		private :
	
		vector<Neuron*> neurons_; ///<neurons in the network
		vector<vector<Index> > connexion_; ///< connexions between the neurons
		int poissonGenerator(const double& rate);
		void initialiseNeurons(const int& excitatory_number, const int& inhibitory_number);
		void initialiseConnexion(const int& excitatory_number, const int& inhibitory_number, 
		const int& excitatory_connexion, const int& inhibitory_connexion);
};

#endif
