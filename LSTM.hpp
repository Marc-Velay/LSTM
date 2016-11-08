#include <cstdio>
#include <iostream>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>


//Constant Defaults!
#define LEARNING_RATE 0.001
#define MOMENTUM 0.9
#define MAX_EPOCHS 1500
#define DESIRED_ACCURACY 90  
#define DESIRED_MSE 0.001 
#define BIAS 1
#define VOCABSIZE 31 //[a..z],.!? <space>

using namespace std;

class LSTM{
    
    public:
        LSTM();
        ~LSTM();
        
        void activate();
  
        //Setters
        void setPrevNodeInLine(LSTM *prev);
        void setPrevLayer(LSTM *prev);
        void setNextLayer(LSTM *next);
        void setNextNodeInLine(LSTM *next);
        void setprevLayerOutput(vector<double> prevLayerOutput);
        void setCoreVector(vector<double> coreVector);
        void setoutputVector(vector<double> outputVector);
  
        //Getters
        LSTM* getPrevNodeInLine();
        LSTM* getPrevLayer();
        LSTM* getNextLayer();
        LSTM* getNextNodeInLine();
        vector<double> getCoreVector();
        vector<double> getOutputVector();
        vector<double> getprevLayerOutput();
        
    private:
        LSTM *prevInLine, *nextInLine, * prevLayer, *nextLayer;
        vector<double> coreVector, outputVector, prevLayerOutput;
        
        double f (double sum);
        double g (double sum);
        double h (double sum);
        vector<double> sigmoidFct(vector<double> input);
        vector<double> tanhFct(vector<double> input);
        vector<double> sumVectors(vector<double> vector1, vector<double> vector2);
        void myTinyFree(LSTM* seed);
    
};