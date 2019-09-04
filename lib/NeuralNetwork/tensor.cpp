//implementation code for Tensor class
#include <stdio.h>
#include <random>
#include <math.h>


#include "tensor.h"
		
//Constructor
Tensor::Tensor(Tensor** inputTensors, int numInputTensors){
	//Establish connectons to tensors
	_numInputTensors = numInputTensors;
	_inputTensors = inputTensors;
	
	//Reset value, error
	value = 0.0;
	_error = 0.0;
	
	//Initialize the list of weights
	_weights = new float[numInputTensors];
	
	//Create temporaty variables for assigning weights
	float numTensors  = static_cast<float> (numInputTensors);
	
	//Assign random weights to each tensor
	for(int i = 0; i < numInputTensors; i++){
		_weights[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) / numTensors;
	}
}

//Special constructor ONLY for the first layer
Tensor::Tensor(){
	//Reset value, error
	value = 0.0;
	_error = 0.0;
	//No inputs
	_numInputTensors = 0;
}
 
Tensor::~Tensor(){
}
 
void Tensor::reset(){
	value = 0.0;
}

void Tensor::overloadValue(float newValue){
	value = newValue;
}
void Tensor::overloadError(float newError){
	_error = newError;
}
		 
float Tensor::process(){
	//Temporary variable for raw value of this tensor
	float v = 0;
	
	//Add the values of each tensor
	for(int i = 0; i < _numInputTensors; i++){
		v += _inputTensors[i]->value * _weights[i];
	}
	
	//Reset error
	_error = 0.0;
	
	//Normalize v and set the value to v
	value = normalize(v);
	return value;
}
 
void Tensor::train(){
	float sigma = _error*value*(1.0-value);
	for(int i = 0; i < _numInputTensors; i++){
		_inputTensors[i]->incrementError(_weights[i]*sigma);
	}
	//TODO adjust weights
}

void Tensor::incrementValue(float amount){
	value += amount;
}

void Tensor::incrementError(float error){
	_error += error;
}

float Tensor::normalize(float rawValue){
	//TODO convert to a lookup table
	//to increase computational efficiency
	return 1.0/(1.0-exp(rawValue));
}


void Tensor::debug(const char* message){
	printf("Tensor:\t");
	printf(message);
	printf("\n");
}
void Tensor::debug(const char* varname, int var){
	printf("Tensor:\t%s has a value of %d\n",varname,var);
}
