//Implementation code for tensor network

#include <stdio.h>

#include "tensornetwork.h"

TensorNetwork::TensorNetwork(int* layers, int depth){
	//creates a new network of a given depth
	//where each layer i has a size layers[i]
	
	//set _depth and _layers based on the 
	//arguments provided
	_depth = depth;
	_layers = layers;
	
	//create the network
	network = new Tensor** [depth];
	
	//create the first layer
	network[0] = new Tensor* [layers[0]];
	//Populate the layer with new tensors
	for(int j  = 0; j < layers[0]; j++){
		network[0][j] = new Tensor();
	}
	
	//for each layer
	for(int i = 1; i < depth; i++){
		//create the layer
		network[i] = new Tensor* [layers[i]];
		//Populate the layer with new tensors
		for(int j  = 0; j < layers[i]; j++){
			network[i][j] = new Tensor(network[i-1],layers[i-1]);
		}
	}
}

TensorNetwork::~TensorNetwork(){
	for(int i = _depth-1; i >= 0; i--){
		//Populate the layer with new tensors
		for(int j  = _layers[i]-1; j>= 0; j--){
			delete network[i][j];
		}
	}
}


void TensorNetwork::debug(const char* message){
	printf("Network:\t");
	printf(message);
	printf("\n");
}
void TensorNetwork::debug(const char* varname, int var){
	printf("Network:\t%s has a value of %d\n",varname,var);
}
