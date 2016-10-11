#include "RNN.hpp"

//Constructeur
RNN::RNN(int size, int *sizeLayers) : seed (NULL), learningRate (LEARNING_RATE), momentum (MOMENTUM), epoch (0), maxEpochs (MAX_EPOCHS), desiredAccuracy (DESIRED_ACCURACY), trainingSetAccuracy(0), validationSetAccuracy(0), generalizationSetAccuracy(0), trainingSetMSE(0), validationSetMSE(0),generalizationSetMSE(0)
{
    LSTM *current, *prevL, *prevNode, *firstInLine;
    seed = new LSTM();
    prevNode=seed;
    for(int i =0; i < sizeLayers[0]-1;++i){                                     //First Line
        current=new LSTM();
        prevNode->setNextNodeInLine(current);                                   //Create back and forth links
        current->setPrevNodeInLine(prevNode);
    }
    firstInLine=current;
    for(int i = 1; i<size; ++i){                                                // Create the n layers after the first one
        prevL=current;
        current= new LSTM();
        current->setPrevLayer(prevL);
        prevL->setNextLayer(current);
        firstInLine=current;
        prevNode=current;
        for(int j = 1; j< sizeLayers[i];++j){
            current = new LSTM();
            current->setNextNodeInLine(prevL);
            prevL->setPrevNodeInLine(current);
            if(current->getNextNodeInLine()->getPrevLayer()!=NULL){
                current->setPrevLayer(current->getNextNodeInLine()->getPrevLayer()->getPrevNodeInLine());
                if(current->getPrevLayer()!=NULL)
                    current->getPrevLayer()->setNextLayer(current);
            }
        }
    }
}

RNN::~RNN() {
    
}


void RNN::setTrainingParameters(double lR, double m) {
    learningRate = lR;
    momentum = m;
}


void RNN::setStoppingConditions(int mEpochs, double dAccuracy) {
    maxEpochs = mEpochs;
    desiredAccuracy = dAccuracy;
}

void RNN::enableLogging(const char* file, int resolution = 1) {
    if(!logFile.is_open()) {
        logFile.open(file, ios::out);

        if(logFile.is_open()) {
            logFile << "Epoch,Training Set Accuracy, Generalization Set Accuracy,Training Set MSE, Generalization Set MSE" << endl;

            loggingEnabled = true;

            logResolution = resolution;
            lastEpochLogged = -resolution;
        }
    }
}

void RNN::trainNetwork( trainingDataSet* tSet ) {
    
    
}


bool RNN::loadWeights(char* inputFilename) {
    
    
    return false;
}

bool RNN::saveWeights(char* outputFilename) {
    
    return false;
}


int* RNN::feedForwardPattern( double* pattern ) {
    feedForward(pattern);
    
    int* results = new int[0];
    
    
    return results;
}

double RNN::getSetAccuracy( std::vector<dataEntry*>& set ) {
    double incorrectResults = 0;
    
    bool correctResultFlag = true;
    
    /*
    *
    *   TODO: for loop comparing clampOutput(outputNeurons[j]) != set[i]->target[j] 
    *               for every output cell
    */
    
    
    if(!correctResultFlag) {
        incorrectResults++;
    }
    
    return 100 - (incorrectResults/set.size() *100);
}


double RNN::getSetMSE( std::vector<dataEntry*>& set ) {
    double mse = 0;

        /*for (int i = 0; i < (int) set.size(); i++) {
                feedForward( set[i]->pattern );

                for( int j = 0; j < nOutput; j++) {
                        mse += pow((outputNeurons[j] - set[i]->target[j]), 2);
                }
        }*/

        return mse/(10 * set.size());       //Switch out 10 with last layer output length
}


void RNN::runTrainingEpoch( std::vector<dataEntry*> trainingSet ) {
    
}


void RNN::backpropagate(double* desiredOutputs) {
    
    
    updateWeights();
}


void RNN::updateWeights() {
    
}


void RNN::feedForward( double* pattern ) {
    
}


int RNN::clampOutput( double x ) {
        if( x < 0.1 ) return 0;
        else if( x > 0.9 ) return 1;
        else return -1;
}

int main(void) {
    srand( (unsigned int) time(0) );

    dataReader d;
    d.loadDataFile("text.csv", 1, 1);
    d.setCreationApproach();
    int layersSize[3] = {10, 5, 2};
    //create neural network
    RNN rnn(3, layersSize);
    
	rnn.setTrainingParameters(0.001, 0.9);    //learning rate and momentum
	rnn.setStoppingConditions(150, 95);  //nb Epochs, %desired accuracy
	rnn.enableLogging("log.csv", 5);     //log every 5 epochs
	
	
    //train neural network on data sets
	for (int i=0; i < d.getNumTrainingSets(); i++ )
	{
		rnn.trainNetwork( d.getTrainingDataSet() );
	}

    //save the weights
    char file[] = "weights.csv";
	rnn.saveWeights(file);


    cout << endl << endl << "Finished training, weights saved to: 'weights.csv'" << endl;
    return 0;
}