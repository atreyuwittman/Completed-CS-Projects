#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

void readData(const string &fileName, vector<double> &set1, vector<double> &set2);
double interpolation(double userInput, const vector<double> &set1, const vector<double> &set2);
bool isOrdered(const vector<double> &set1);
void reorder(vector<double> &set1, vector<double> &set2);
bool isEqual(double num1, double num2);

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
    if(!isOrdered(set1)){
        reorder(set1, set2);
    }
    while(userQuit != "no"){
    cout << set1.size() << ' ' << set2.size() << endl;
    cout << "Enter a flight-path angle: ";
    cin >> userInput;
    cout << "The coefficient is: " << interpolation(userInput, set1, set2) << endl;
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
      cout << "Error opening " << fileName <<endl;
        exit(1);
    
   }
   while(inFS >> angle >> coefficient){
       set1.push_back(angle);
       set2.push_back(coefficient);
   }
   return;
}
double interpolation(double userInput, const vector<double> &set1, const vector<double> &set2){
    double coefficient = 0.0;
    int indexUp = 0;
    int indexDown = 0;
    unsigned int m = 0;
    while(m < set1.size()){
        if(isEqual(set1.at(m), userInput) == true){
            return set2.at(m);
        }
        m++;
    }
    for(unsigned int j = set1.size() - 1; j >= 0; j--){
        if((set1.at(j) - userInput) < 0.0000001){
            indexDown = j;
            break;
        }
    }
    for(unsigned int i = 0; i < set1.size(); i++){
        if((set1.at(i) - userInput) > 0.000001){
            indexUp = i;
            break;
        }
    }

    double fc = set2.at(indexDown);
    double fa = set2.at(indexUp);
    double a = set1.at(indexDown);
    double b = userInput;
    double c = set1.at(indexUp);

    
    
    coefficient = fa + (b - a)/(c - a)*(fc - fa);

    return coefficient;
}
bool isOrdered(const vector<double> &set1){
   for(unsigned int i = 1; i < set1.size(); i++){
       if(set1.at(i) < set1.at(i - 1)){
           return false;
       }
   }
   
    return true;
}
void reorder(vector<double> &set1, vector<double> &set2){
    for(unsigned int i = 0; i < set1.size(); i++){
    for(unsigned int i = 1; i < set1.size(); i++){
        if(set1.at(i) <set1.at(i - 1)){
            swap(set1.at(i - 1), set1.at(i));
            swap(set2.at(i - 1), set2.at(i));
        } 
    }
}
    return;
}
bool isEqual(double num1, double num2){
    return (fabs(num1 - num2) < 10e-6);
}