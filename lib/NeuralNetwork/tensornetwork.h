//header  file for the TensorNetwork class

#include "tensor.h"

#ifndef TENSOR_NETWORK_H
#define TENSOR_NETWORK_H

//class for convolutional neural network
class TensorNetwork{
	int _depth; //depth of neural network
	int* _layers; //size of each layer of network
	Tensor*** network; //the actual network
	
	public:
		//Constructor
		TensorNetwork(int* layers, int depth);
		//Destructor
		~TensorNetwork();
		
	private:
		//Printing debug messages
		void debug(const char* message);
		void debug(const char* varname, int var);
};

#endif
