//header file for the Tensor class

#ifndef TENSOR_H
#define TENSOR_H


//how quickly tensors respond to changes
//too high: network never finds patterns
//too low: network never learns
#define TENSOR_LEARNING_RATE 0.007

//class for tensor in convolutional nopennetworks
class Tensor{
	
	//weights of connections to tensors
	float*  _weights; 
	
	//references to connected tensors
	Tensor** _inputTensors; 
	
	//number of connected tensors
	int _numInputTensors; 
	
	//net error of tensor
	float _error;
	
	public:
		//value of tensor
		//MAY BE PRIVATE IN THE FUTURE
		float value; 
		
		//Constructor
		Tensor(Tensor** inputTensors, int numInputTensors);
		
		//Special constructor ONLY for the first layer
		Tensor();
		 
		 //Destructor
		~Tensor();
		 
		 //Resets tensor for new round of computation
		void reset();
		
		//Overloads the tensor's value; ideal for 
		//feeding information to the input layer
		void overloadValue(float newValue);
		
		//overloads the tensor's error; ideal for
		//training the network through the output tensors
		void overloadError(float newError);
		
		//generates a value given the values and weights
		//of the input tensors
		float process();
		
		//adjusts weights based on the error value
		//and adds to the error of input neurons
		void train();
	 
	private:
		//Increments the value of the tensor
		void incrementValue(float amount);
		//Increments the error from this tensor
		void incrementError(float error);
		//Adjusts values to make learning easier
		float normalize(float rawValue);
		
		//Aides in printing debug values to stdout
		void debug(const char* message);
		void debug(const char* varname, int var);
};

#endif
