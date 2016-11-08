#include "LSTM.hpp"

//Constructeur
LSTM::LSTM(): prevInLine(NULL), nextInLine(NULL), prevLayer(NULL), nextLayer(NULL)
{
    coreVector = new double[VOCABSIZE];
    outputVector = new double[VOCABSIZE];
    for(int i = 0; i < VOCABSIZE; i++) {
      coreVector[i]=0;
      outputVector[i]=0;
    }
}

//Destructeur
LSTM::~LSTM() {
    delete[] coreVector;
    delete[] outputVector;
    if(nextInLine!=NULL)
      nextInLine->~LSTM();
    myTinyFree(this);
}

void LSTM::myTinyFree(LSTM* seed){
  if(seed->prevInLine!=NULL)
      myTinyFree(seed->prevInLine);
  free(seed);
}


void LSTM::activate(LSTM* end,double* pattern){
 
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

void  LSTM::setCoreVector() {
    
    //this->coreVector = this->actualInput + this->memory;
}
        
void  LSTM::setoutputVector() {
    //this->actualInput = netInput*inputGateValue;
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
LSTM* LSTM::getPrevNodeInLine() {
    return this->prevInLine;
}

LSTM* LSTM::getNextNodeInLine() {
    return this->nextInLine;
}

LSTM* LSTM::getNextLayer() {
    return this->nextLayer;
}

LSTM* LSTM::getPrevLayer() {
    return this->prevLayer;
}

double* LSTM::getCoreVector(){
    return this->coreVector;
}

double* getOutputVector() {
    return this->outputVector;
}