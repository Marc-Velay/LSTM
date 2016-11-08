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
#define VOCABSIZE 31

using namespace std;

class LSTM{
    
    public:
        LSTM();
        ~LSTM();
        
        void activate(double* pattern);
  
        //Setters
        void setPrevNodeInLine(LSTM *prev);
        void setPrevLayer(LSTM *prev);
        void setNextLayer(LSTM *next);
        void setNextNodeInLine(LSTM *next);
        
  
        //Getters
        LSTM* getPrevNodeInLine();
        LSTM* getPrevLayer();
        LSTM* getNextLayer();
        LSTM* getNextNodeInLine();
        
    private:
        LSTM *prevInLine, *nextInLine, * prevLayer, *nextLayer;
        double *coreVector, *outputVector;
        
        double f (double sum);
        double g (double sum);
        double h (double sum);
        void myTinyFree(LSTM* seed);
        void setCoreVector();
        void setoutputVector();
        double* getCoreVector();
        double* getOutputVector();
    
};