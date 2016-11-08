#include "LSTM.hpp"

//Constructeur
LSTM::LSTM(): prevInLine(NULL), nextInLine(NULL), prevLayer(NULL), nextLayer(NULL)
{
    coreVector.reserve(VOCABSIZE);
    outputVector.reserve(VOCABSIZE);
    prevLayerOutput.reserve(VOCABSIZE);
    for(int i = 0; i < VOCABSIZE; i++) {
      coreVector.push_back(0);
      outputVector.push_back(0);
      prevLayerOutput.push_back(0);
    }
}

//Destructeur
LSTM::~LSTM() {
    if(nextInLine!=NULL)
      nextInLine->~LSTM();
    myTinyFree(this);
}

void LSTM::myTinyFree(LSTM* seed){
  if(seed->prevInLine!=NULL)
      myTinyFree(seed->prevInLine);
  free(seed);
}


void LSTM::activate(){

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

vector<double> LSTM::sigmoidFct(vector<double> input) {
    if(input.size() != 0) {
        for(int i = 0; i < (int)input.size(); i++) {
            input[i] = 1/(1+exp(-input[i]));
        }
    }
    return input;
}

vector<double> LSTM::tanhFct(vector<double> input) {
    if(input.size() != 0) {
        for(int i = 0; i < (int)input.size(); i++) {
            input[i] = (exp(input[i])-exp(-input[i]))/(exp(input[i])+exp(-input[i]));
        }
    }
    return input;
}

vector<double> LSTM::sumVectors(vector<double> vector1, vector<double> vector2) {
    for(int i =0; i < (int)vector1.size(); i++){
        vector1[i] = vector1[i]+vector2[i];
    }
    return vector1;
}

void  LSTM::setCoreVector(vector<double> coreVector) {    
    this->coreVector = coreVector;
}
        
void  LSTM::setoutputVector(vector<double> outputVector) {
    this->outputVector = outputVector;
}
        
void  LSTM::setprevLayerOutput(vector<double> prevLayerOutput) {
    this->prevLayerOutput = prevLayerOutput;
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

vector<double> LSTM::getCoreVector(){
    return this->coreVector;
}

vector<double> LSTM::getOutputVector() {
    return this->outputVector;
}

vector<double> LSTM::getprevLayerOutput() {
    return this->prevLayerOutput;
}
