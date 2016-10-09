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

using namespace std;

class LSTM{
    
    public:
        LSTM();
        ~LSTM();
        
        //setters
        void setPrevNodeInLine(LSTM *prev);
        void setPrevLayer(LSTM *prev);
        void setNextLayer(LSTM* next);
        void setNextNodeInLine(LSTM *next);
        
    private:
        LSTM *prevInLine, *nextInLine, * prevLayer, *nextLayer;
        double netInput, inputGateValue, forgetGateValue, actualInput, memory, core, outputeGateValue, coreActivationValue, output;
        
        double f (double sum);
        double g (double sum);
        double h (double sum);
        void setCoreValue();
        void setActualInput(double netInput, double inputGateValue);
        void setMemory(double forgetGateValue, double core);
        void setOutputValue(double coreActivationValue, double outputeGateValue);
    
};