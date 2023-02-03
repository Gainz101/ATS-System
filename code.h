#ifndef CODE_H
#define CODE_H

#include <string>

const unsigned int SIZE = 9; // lines in the data


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the csv file given
//---------------------------------------------------------
void scan(const std::string& file, std::string TextArray[]);



//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[]);





#endif