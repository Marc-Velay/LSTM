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
        void setNextLayer(LSTM *next);
        void setNextNodeInLine(LSTM *next);
        LSTM* getPrevNodeInLine();
        LSTM* getPrevLayer();
        LSTM* getNextLayer();
        LSTM* getNextNodeInLine();
        
    private:
        LSTM *prevInLine, *nextInLine, *prevLayer, *nextLayer;
        double netInput, inputGateValue, forgetGateValue, actualInput, memory, core, outputeGateValue, coreActivationValue, output;
        
        double f (double sum);
        double g (double sum);
        double h (double sum);
        void setCoreValue();
        void setActualInput(double netInput, double inputGateValue);
        void setMemory(double forgetGateValue, double core);
        void setOutputValue(double coreActivationValue, double outputeGateValue);
        void setNetInput(double lastLayerOutput, double lastInLineOutput);
        void setinputGateValue(double lastLayerOutput, double lastInLineOutput, double lastInLineCore);
        void setForgetgateValue(double lastLayerOutput, double lastInLineOutput, double lastInLineCore);
        void setOutputGateValue(double lastLayerOutput, double lastInLineOutput, double core);
        void setCoreActivationValue(double coreValue);

        double getCoreValue();
        double getActualInput();
        double getMemory();
        double getOutputValue();
        double getNetInput();
        double getinputGateValue();
        double getForgetgateValue();
        double getOutputGateValue();
        double getCoreActivationValue();
    
};