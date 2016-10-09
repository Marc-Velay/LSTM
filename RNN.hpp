#include <cstdio>
#include <iostream>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <math.h>
#include "dataReader.hpp"
#include "LSTM.hpp"

using namespace std;

class RNN {
    
    LSTM* seed;
    
    //learning parameters
	double learningRate;					// adjusts the step size of the weight update	
	double momentum;						// improves performance of stochastic learning

	//epoch counter
	long epoch;
	long maxEpochs;
	
	//accuracy/MSE required
	double desiredAccuracy;
	//accuracy stats per epoch
	double trainingSetAccuracy;
	double validationSetAccuracy;
	double generalizationSetAccuracy;
	double trainingSetMSE;
	double validationSetMSE;
	double generalizationSetMSE;

	//log file handle
	bool loggingEnabled;
	std::fstream logFile;
	int logResolution;
	int lastEpochLogged;
    
    public:
    //Constructeur
        RNN(int size, int* layersSize);
        ~RNN();
    	void setTrainingParameters( double lR, double m);
    	void setStoppingConditions( int mEpochs, double dAccuracy);
    	void enableLogging( const char* filename, int resolution );
    	void trainNetwork( trainingDataSet* tSet );
    	
    	bool loadWeights(char* inputFilename);
        bool saveWeights(char* outputFilename);
        int* feedForwardPattern( double* pattern );
        double getSetAccuracy( std::vector<dataEntry*>& set );
        double getSetMSE( std::vector<dataEntry*>& set );
    	
    private:
    	void runTrainingEpoch( std::vector<dataEntry*> trainingSet );
    	void backpropagate(double* desiredOutputs);
    	void updateWeights();
    	int clampOutput( double x );
        void feedForward( double* pattern );
};