#ifndef CONSTANT_HPP
#define CONSTANT_HPP
//time conversion
	//time to step t= static_cast<unsigned long>(std::ceil(T/h))
	//step to time T = t*h
//to count time in step
typedef unsigned int step;
//dt
const double H = 0.1;
///Constants specific to the time
const step T_START = 100.0/H;
const step T_STOP = 400.0/H;


//to run the simulation faster
const step N = 1;
 
///Constants specific to the neuron
//time constant
const double TAU = 20.0;
//time constant in which the neuron is refractory
const step TAU_REFRACTORY = 2.0/H;
//capacity of the membrane
const double C = 1.0;
//membrane resistance
const double R = (TAU/C);
//potential threshold
const double V_THRESHOLD = 20.0;
//resset potential
const double V_RESET = 0.0;
//potential extern
const double V_EXT = 2*V_THRESHOLD;

//amplitude between vthr and vreset in mV
const double J = 0.1; 

//delay
const double D = 1.5;
const step DELAY = D/H;

const step BufferSize = ((D/H)+1);

const double C1 = exp(-H/TAU); //constant for ODE
const double C2 = R*(1-exp(-H/TAU));

const int N_EXCITATORY = 100;
const int N_INHIBITORY = 25;
const int N_TOTAL = N_EXCITATORY + N_INHIBITORY; 
const int C_EXCITATORY = 0.1*N_EXCITATORY;
const int C_INHIBITORY = 0.1*N_INHIBITORY;
const int C_TOTAL = C_EXCITATORY + C_INHIBITORY;

//for tab index
typedef unsigned int Index;


#endif
