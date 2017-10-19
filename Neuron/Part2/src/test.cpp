
#include <iostream>
#include "neuron.hpp"
#include <cmath>
#include "gtest/gtest.h"

TEST (NeuronTest, MembranePotential) {
	Neuron neuron;
	neuron.setInputCurrent(1.0);
	neuron.update(1);
	EXPECT_NEAR(20.0*(1.0-std::exp(-0.1/20.0)), neuron.getMembranePotential(), 10e-5);
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
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
