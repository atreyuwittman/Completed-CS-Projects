#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void readData(const string &fileName, vector<double> &set1, vector<double> &set2);
// double interpolation(double userInput, const vector<double> &set1, const vector<double> &set2);

int main() {
    vector<double> set1;
    vector<double> set2;
    string fileName;
    string userQuit = "yes";
    double userInput = 0;
    cout << "Enter name of input data file:";
    cin >> fileName;
    cout << endl;
    cout << endl;
    readData(fileName, set1, set2);
    while(userQuit != "no"){
    cout << "Enter a flight-path angle: ";
    cin >> userInput;
    for(unsigned int i = 0; i < set2.size(); i++){
        cout << set2.at(i) << endl;
    }
  //  cout << "The coefficient is: " << interpolation(userInput, set1, set2);
    cout << "Enter another angle?";
    cin >> userQuit;
    }
    
    
    
    
    return 0;
}

void readData(const string &fileName, vector<double> &set1, vector<double> &set2){
     ifstream inFS;
     double angle = 0.0;
     double coefficient=0.0;
   inFS.open(fileName.c_str());
   
   if(!inFS) {
      string file = "no";
      cout << "Error opening " << fileName <<endl;
        exit(1);
    
   }
   while(inFS >> angle >> coefficient){
       set1.push_back(angle);
       set2.push_back(coefficient);
   }
   return;
}

/*double interpolation(double userInput, const vector<double> &set1, const vector<double> &set2){

    for(unsigned int i = 0; i < set1.size(); i++){
        if(set1.at(i) == userInput){
            cout << set2.at(i);
            return set2.at(i);
        }
    }
    double coefficient = 0;
    double a = 0;
    double b = 0;
    for(unsigned int j = 1; j < set1.size(); j++){
        if(!(set1.at(j) < userInput)){
            a = set2.at(j - 1);
            break;
        }
    }
    for(unsigned int k = 1; k < set1.size(); k++){
        if(!(set1.at(k) > userInput)){
            coefficient = set2.at(k - 1);
            break;
        }
        
    }
    
    
    coefficient = (a) + (b - a)/(coefficient - a)*((coefficient) - (a));
    return coefficient;
}*/