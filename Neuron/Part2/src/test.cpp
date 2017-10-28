#include <iostream>
#include "network.hpp"
#include "neuron.hpp"
#include <cmath>
#include "gtest/gtest.h"

TEST (NeuronTest, MembranePotential) {
	Neuron neuron1, neuron2;
	neuron1.setInputCurrent(1.0);
	neuron1.update(1);
	EXPECT_NEAR(20.0*(1.0-std::exp(-0.1/20.0)), neuron1.getMembranePotential(), 10e-5);
	neuron1.update(10000);
	EXPECT_GT(10e-3, std::fabs(19.999 - neuron1.getMembranePotential()));
	EXPECT_EQ(0, neuron1.getTimeSize());
	
	neuron2.setInputCurrent(0.0);
	neuron2.update(1);
	EXPECT_EQ(0.0, neuron2.getMembranePotential());
	
}

TEST (NeuronTest, SpikeTime) {
	Neuron neuron;
	neuron.setInputCurrent(1.01);
	for (int i(1000); i < 4000; ++i) {
		neuron.update(1);
	}
	EXPECT_NEAR(192.4, neuron.getTimeSpike(0)*0.1, 10e-5);
	EXPECT_NEAR(286.8, neuron.getTimeSpike(1)*0.1, 10e-5);
	EXPECT_NEAR(381.2, neuron.getTimeSpike(2)*0.1, 10e-5);
	
	Neuron neuron2;
	neuron2.setInputCurrent(1.01);
	neuron2.update(924);
	EXPECT_EQ(0, neuron2.getTimeSize());
	neuron2.update(1);
	EXPECT_EQ(1, neuron2.getTimeSize());
	EXPECT_EQ(0.0, neuron2.getMembranePotential());
	neuron2.update(1868);
	EXPECT_EQ(2, neuron2.getTimeSize());
}

TEST(NeuronTest, Connexion) {
	Neuron neuron1, neuron2;
	int delay(15);
	neuron1.setInputCurrent(1.01);
	for(int i(0); i < 925+delay ; ++i) {
		if(neuron1.update(1)) {
			neuron2.receive(0.1, delay);
			EXPECT_EQ(0.0, neuron1.getMembranePotential());
			EXPECT_EQ(0.0, neuron2.getMembranePotential());
		}
		neuron2.update(1);
	 }
	 
	EXPECT_EQ(0.1, neuron2.getMembranePotential());
}

TEST(NetworkTests, neurons) {
	vector<Neuron> neurons;
	vector<vector<Index> > connexion(1);
	Neuron neuron1,neuron2;
	neuron1.setInputCurrent(1.01);
	neurons.push_back(neuron1);
	neurons.push_back(neuron2);
	connexion[0].push_back(1);
	Network network(neurons, connexion);
	int delay(15);
	for(int i(0); i < 925+delay ; ++i) {
		network.update(1);
	 }
	EXPECT_EQ(0.1, network.getMembranePotentialNeuron(1));
} 
TEST(NetworkTest, Initialisation) {
	 Network networkNeurons;
	 EXPECT_EQ(125, networkNeurons.getNbNeurons());
	 
 }
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}