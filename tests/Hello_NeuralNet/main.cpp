#include <stdio.h>
#include "NeuralNetwork/tensor.h"
#include "NeuralNetwork/tensornetwork.h"





int main(int argc, char **argv)
{
	printf("Hello World!\n");
	int depth = 4;
	int networkConfig[] = {1000,2000,3000,4000}; 
	printf("Initializing network\n");
	TensorNetwork network(networkConfig, depth);
	printf("Done!\n");
	return 0;
}
