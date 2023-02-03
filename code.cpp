#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "code.h"
#include <fstream>
#include <stdexcept>

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;



//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the csv file given
//---------------------------------------------------------
void scan(const std::string& file, std::string TextArray[]) 
{
  	//TODO
  	string line="";
	std::ifstream inFS;
	inFS.open(file);
	if (!inFS.is_open()){
    	throw std::invalid_argument("Cannot open file");
	}
	

	for(int i = 0;i<9;i++){
		getline(inFS,line);
		std::istringstream sin(line);
		if (line.empty()){
			throw std::domain_error("File missing data");
		}
		sin >> TextArray[i];
        cout<<TextArray[i];
		if (sin.fail()){
			throw std::domain_error("File contains invalid data (time)");
		}
		line = "";
    }
}
  


//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	//TODO
	//string country [9] = {};
	for(int i=0;i<9;i++){
		ary[i] = "N/A";
	}


}