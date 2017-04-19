#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//sigmoid function

double output(double x) {
	return 1.0 / (1.0 + exp(-x));
}

double derivative(double x) {
	return x * (1 - x);
}

//neuron function

double neuronOutput(double inputs[], double weights[], double biasWeight) {
	return output(weights[0] * inputs[0] + weights[1] * inputs[1] + biasWeight);
}

//training function

void train(int loop_number) {
	//input values
	double inputs[4][2] = {
		{0,0},
		{0,1},
		{1,1},
		{1,0}
	};
	//expected results
	double results[] = {0, 1, 0, 1};

	//hiddenNeuron1
	double neuron1Inputs[2];
	double neuron1Weights[2];
	double neuron1Error;
	double neuron1BiasWeight;

	neuron1Weights[0] = (double)rand() / (double)RAND_MAX;
	neuron1Weights[1] = (double)rand() / (double)RAND_MAX;
	neuron1BiasWeight = (double)rand() / (double)RAND_MAX;
	
	//hiddenNeuron2
	double neuron2Inputs[2];
        double neuron2Weights[2];
        double neuron2Error;
        double neuron2BiasWeight;

	neuron2Weights[0] = (double)rand() / (double)RAND_MAX;
        neuron2Weights[1] = (double)rand() / (double)RAND_MAX;
        neuron2BiasWeight = (double)rand() / (double)RAND_MAX;

	//outputNeuron
	double neuron3Inputs[2];
        double neuron3Weights[2];
        double neuron3Error;
        double neuron3BiasWeight;
	
	//generating random weights
	neuron3Weights[0] = (double)rand() / (double)RAND_MAX;
        neuron3Weights[1] = (double)rand() / (double)RAND_MAX;
        neuron3BiasWeight = (double)rand() / (double)RAND_MAX;

	//training loop
	int epoch = 0;
	while(epoch < loop_number) {
		epoch++;
		for(int i = 0; i < 4; i++) {
			//calculate output
			neuron1Inputs[0] = inputs[i][0];
			neuron1Inputs[1] = inputs[i][1];
			neuron2Inputs[0] = inputs[i][0];
			neuron2Inputs[1] = inputs[i][1];
			
			neuron3Inputs[0] = neuronOutput(neuron1Inputs, neuron1Weights, neuron1BiasWeight);
			neuron3Inputs[1] = neuronOutput(neuron2Inputs, neuron2Weights, neuron2BiasWeight);
			double neuron3Output = neuronOutput(neuron3Inputs, neuron3Weights, neuron3BiasWeight);

			printf("%f", inputs[i][0]);
			printf(" xor ");
			printf("%f", inputs[i][1]);
			printf(" = ");
			printf("%f", neuron3Output);
			printf(" (loop n°%d)",epoch);
			printf("\n");

			//adjust weights
			neuron3Error = derivative(neuron3Output) * (results[i] - neuron3Output);
			neuron3Weights[0] += neuron3Error * neuron3Inputs[0];
			neuron3Weights[1] += neuron3Error * neuron3Inputs[1];
			neuron3BiasWeight += neuron3Error;

			neuron1Error = derivative(neuron3Inputs[0]) * neuron3Error * neuron3Weights[0];
			neuron2Error = derivative(neuron3Inputs[1]) * neuron3Error * neuron3Weights[1];

			neuron1Weights[0] += neuron1Error * neuron1Inputs[0];
			neuron1Weights[1] += neuron1Error * neuron1Inputs[1];
			neuron1BiasWeight += neuron1Error;

			neuron2Weights[0] += neuron2Error * neuron2Inputs[0];
			neuron2Weights[1] += neuron2Error * neuron2Inputs[1];
			neuron2BiasWeight += neuron2Error;
		}
	}
}

int main(int argc, char *argv[]) {
  if (argv[1])
    {train(atoi(argv[1]));}
  else
    {printf("Please enter a number of loops \n");}
  return 0;
}
