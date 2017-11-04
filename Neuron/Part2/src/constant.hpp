/*!A constant file */
#ifndef CONSTANT_HPP
#define CONSTANT_HPP

typedef unsigned int step; ///to count time in step
typedef size_t Index; ///for tab index
static constexpr double H = 0.1; //!<time partition

///Constants specific to the time
const step T_START = 100.0/H;
const step T_STOP = 400.0/H;

static const step N = 1; ///to run the simulation faster
				
const double MU_EXT = 2.0; ///potential extern


const double J = 0.1; ///amplitude between vthr and vreset in mV
const double G = 5.0; ///rate
const double J_EXCITATORY = 0.1; 
const double J_INHIBITORY = -G*J_EXCITATORY;

const double D = 1.5; ///delay [ms]
const step DELAY = D/H; ///delay in step
const Index BufferSize = ((D/H)+1); ///size buffer

const int N_EXCITATORY = 10000; ///number of excitatory neuron
const int N_INHIBITORY = 2500; ///number of inhibitory neuron
const int N_TOTAL = N_EXCITATORY + N_INHIBITORY; ///total number
const int C_EXCITATORY = 0.1*N_EXCITATORY; ///number of excitatory connexion (10%)
const int C_INHIBITORY = 0.1*N_INHIBITORY; ///number of inhibitory connexion (10%)
const int C_TOTAL = C_EXCITATORY + C_INHIBITORY; ///total number of connexion

#endif
