#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include "dataReader.hpp"

using namespace std;


size_t dataReader::strcpy_s(char *d, size_t n, char const *s)
{
    return snprintf(d, n, "%s", s);
}

dataReader::~dataReader()
{
	//clear data
	for (int i=0; i < (int) data.size(); i++ ) delete data[i];		
	data.clear();		 
}


bool dataReader::loadDataFile( const char* filename)
{
	//clear any previous data
	for (int i=0; i < (int) data.size(); i++ ) delete data[i];		
	data.clear();
	tSet.clear();

	//open file for reading
	fstream inputFile;
	inputFile.open(filename, ios::in);	

	if ( inputFile.is_open() )
	{
		string line = "";
		
		//read data
		while ( !inputFile.eof() )
		{
			getline(inputFile, line);
			
			//process line
			if (line.length() > 0 ) processLine(line);
		}		
		
		//shuffle data
		//random_shuffle(data.begin(), data.end());

		//split data set
		//trainingDataEndIndex = (int) ( 0.6 * data.size() );
		trainingDataEndIndex = (int) ( data.size() );
		//int gSize = (int) ( ceil(0.2 * data.size()) );
		int gSize = (int) ( data.size() );
		//int vSize = (int) ( data.size() - trainingDataEndIndex - gSize );
		int vSize = (int) ( data.size() );
							
		//generalization set
		//for ( int i = trainingDataEndIndex; i < trainingDataEndIndex + gSize; i++ ) tSet.generalizationSet.push_back( data[i] );
		for ( int i = 0; i < trainingDataEndIndex; i++ ) tSet.generalizationSet.push_back( data[i] );
				
		//validation set
		//for ( int i = trainingDataEndIndex + gSize; i < (int) data.size(); i++ ) tSet.validationSet.push_back( data[i] );
		for ( int i = 0; i < (int) data.size(); i++ ) tSet.validationSet.push_back( data[i] );
		
		//print success
		cout << "Input File: " << filename << "\nRead Complete: " << data.size() << " Patterns Loaded"  << endl;

		//close file
		inputFile.close();
		
		return true;
	}
	else 
	{
		cout << "Error Opening Input File: " << filename << endl;
		return false;
	}
}

//Processes a single line from the data file
void dataReader::processLine( string &line )
{
	for(int i = 0; i < int(line.length()-1); i++) {
		data.push_back( new dataEntry( dataReader::toClass(line.at(i)), dataReader::toClass(line.at(i+1))) );
		cout << line.at(i);
	}
	data.push_back( new dataEntry( dataReader::toClass(line.at(line.length()-1)), dataReader::toClass('.')));
	cout << line.at(line.length()-1) << endl;

	for(int i = 0; i < int(data.size()); i++) {
		for(int j = 0; j < int(classList.length()); j++) {
			cout << data[i]->pattern[j];
			cout << ", " << data[i]->target[j] << endl;
		}
	}	
}
//Selects the data set creation approach
void dataReader::setCreationApproach()
{
		creationApproach = STATIC;
		
		//only 1 data set
		numTrainingSets = 1;

}

double* dataReader::toClass(char t) {
	string classList = "abcdefghijklmnopqrstuvwxyz ,.!?";
	double* outputVector = new double[classList.length()+1];
	for(int i = 0; i < int(classList.length()); i++) {
		if(t == classList.at(i)) {
			outputVector[i] = 1;
		} else {
			outputVector[i] = 0;
		}
	}
	return outputVector;
}


//Returns number of data sets created by creation approach
int dataReader::getNumTrainingSets()
{
	return numTrainingSets;
}



//Get data set created by creation approach
trainingDataSet* dataReader::getTrainingDataSet()
{		
	switch ( creationApproach )
	{	
		case STATIC : createStaticDataSet(); break;
	}
	
	return &tSet;
}



//Get all data entries loaded
vector<dataEntry*>& dataReader::getAllDataEntries()
{
	return data;
}



//Create a static data set (all the entries)
void dataReader::createStaticDataSet()
{
	//training set
	for ( int i = 0; i < trainingDataEndIndex; i++ ) tSet.trainingSet.push_back( data[i] );		
}