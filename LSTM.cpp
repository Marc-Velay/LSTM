#include "LSTM.hpp"

//Constructeur
LSTM::LSTM(): prevInLine(NULL), nextInLine(NULL), prevLayer(NULL), nextLayer(NULL)
{
    
}

//Destructeur
LSTM::~LSTM() {
    
}

//Methode
double LSTM::f(double sum){
    return (2/(1 + exp(-sum))- 1);
}

double LSTM::g(double sum) {
    return 1/(1+exp(-sum));
}

double LSTM::h(double sum){
    return (2/(1 + exp(-sum))- 1);
}

void  LSTM::setCoreValue() {
    this->core = this->actualInput + this->memory;
}
        
void  LSTM::setActualInput(double netInput, double inputGateValue) {
    this->actualInput = netInput*inputGateValue;
}


void  LSTM::setMemory(double forgetGateValue, double previousCore) {
    this->memory = forgetGateValue*previousCore;
}


void  LSTM::setOutputValue(double coreActivationValue, double outputeGateValue) {
    this->output = coreActivationValue*outputeGateValue;
}


void LSTM::setPrevNodeInLine(LSTM *prev) {
    this->prevInLine = prev;
}

void LSTM::setNextNodeInLine(LSTM *next) {
    this->nextInLine = next;
}

void LSTM::setNextLayer(LSTM* next) {
    this->nextLayer = next;
}

void LSTM::setPrevLayer(LSTM* prev) {
    this->prevLayer = prev;
}