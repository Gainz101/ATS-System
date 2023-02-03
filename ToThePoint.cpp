/******************************************************************************

File: ToThePoint.cpp
Author: ME
Date: 1/22/2023


*******************************************************************************/

#include <iostream>
#include "code.h"
#include <iomanip>  
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>   


using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error;
using std::cerr;

int main()
{
    string fileName = "";  
    string KeyWord="";
    string TextArray[100000];
    int i=0;
    int wordCount =0;
    bool empty=false;

    // TODO: prompt until both the file and the contained data are valid
    while(true){
        try{
            cout<<"Enter file name: ";
            cin >> fileName;
            cout<<"Enter Key Word: ";
            cin >> KeyWord;
            string line="";
            std::ifstream inFS;
            inFS.open(fileName);
            if (!inFS.is_open()){
                throw std::invalid_argument("Cannot open file");
            }

            while(true){
                getline(inFS,line);
                std::istringstream sin(line);
                if (line.empty()){
                    empty=true;
                    continue;//if theres a whitespace empty line then skip over it
                    //throw std::domain_error("File missing data");
                }
                if(empty){
                    cout<<endl;
                    empty=false;
                }
                while(!sin.eof()){//go till end of line
                    sin >> TextArray[i];
                    cout<<TextArray[i]<< " ";
                    int size=TextArray[i].size();
                    if(!((TextArray[i][size-1]>='a' && TextArray[i][size-1]<='z')||(TextArray[i][size-1]>='A' && TextArray[i][size-1]<='Z')||(TextArray[i][size-1]>='0' && TextArray[i][size-1]<='9'))){//if it is a letter
                        TextArray[i].pop_back();
                    }
                    if(!((TextArray[i][0]>='a' && TextArray[i][0]<='z')||(TextArray[i][0]>='A' && TextArray[i][0]<='Z')||(TextArray[i][0]>='0' && TextArray[i][0]<='9'))){//if it is a letter
                        TextArray[i].erase(0,1);
                    }
                    i++;
                    wordCount++;
                } 
                cout<<endl;
                
            

                //cout<<TextArray[i];
                if (sin.fail()){
                    break;
                    //throw std::domain_error("File contains invalid data (time)");
                }
                line = "";
                //cout<<endl;
            }
            break;
        }
        catch(std::invalid_argument &e){
            cout<< "Invalid File: " << e.what() << endl;
        }
        catch(std::domain_error &e){
            cout<< "Invalid File: " << e.what() << endl;
        }
    }
    
   cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
    // TODO: Output results
    if(KeyWord=="nah"){
        cout<<"No Key Word";
    }else{
        int count=0;
        for(int j = 0;j<wordCount;j++){
            if(TextArray[j]== KeyWord){
                count++;
            }
            if(TextArray[j].substr(0, TextArray[j].size()-1)== KeyWord){
                count++;
            }
        }
        cout<< "Count is: "<< count;
    }
    
    /*int place = 1;
    cout<<"Final results!!"<<endl;
    for (unsigned int i = 1;i<10;i++){
        for(unsigned int j = 0;j<9;j++){
            if (rank[j] == i){ 
                if (i == 1){
                    firstPlace = j;
                } 
                cout <<"["<< place <<"]  " << std::fixed<<std::setprecision(2)<< time[j] << " "<<std::left<<std::setw(20)<<name[j] <<"("<<country[j]<<")"<<"  +"<< std::fixed<<std::setprecision(2)<<time[j]-time[firstPlace]<<endl;
                place += 1;
                break;
            }
        }
    } 
    return 0;*/
}
/*
file named grade.txt with names and score for 10 students

//declare, define, initialize the input file stream
ifstream fin("grade.txt");
//set up a parallel array
//name[i], score[i], rank[i]: represent tge sae student's
string name[10] = {};
double score[10] = {};
int rank[10] = {};

if (!fin.is_open()){
    cerr << "cannot open the file"<<endl; cerr is better for outputting error messages but cout works fine
}
unsigned int i = 0;
string line="";
//read the data from the file, the data is storied in name & score
for(i=0;i<10;i++){
    getline(fin,line);
    istringstream sin(line);

    sin>>name[i]>>score[i];
}
cout<<"The original data: "<<endl;
for(i=0; i < 10; i++){
    cout<< name[i] <<"   "<< score[i] << endl;
}
for (i = 0; i<10;i++){
    //compute the rank of the i-th student
    int count = 0;
    for (unsigned int j = 0;j<10;j++){
        if (score[j] < score [i] && j != i){
            count++;
        }
        rank[i] = count + 1;
    }
}
cout << "The sorted data: "<<endl;
for (i=0;i<=10;i++){
    for (unsigned int j = 0; j < 10; j++){
        if (rank[j] == i){
            cout<<name[j]<<"    "<<score[i] << endl;
        }
    }
}
*/