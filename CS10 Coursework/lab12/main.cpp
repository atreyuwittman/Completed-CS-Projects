#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void fillVector(vector<double>& numList) //(3) FIXME - Add Parameter
{
    double userDouble = 0.0;
    cout << "Enter numbers to populate the vector ";
    cout << "(enter any other character to end user input): "; 

    while (cin >> userDouble) {
      //(3) FIXME - Add numbers to vector
      numList.push_back(userDouble);
    }
    cout << endl;

    return;
}

double meanVector(const vector <double> &v) {
    double total = 0;
    int n = 0;
    double mean = 0;
   //(4) FIXME - Calculate mean of vector numbers
   for(unsigned int i = 0; i < v.size(); i++){
       total += v.at(i);
       n++;
   }
   mean = (total / n);
   
   return mean;
}

double varianceVector(double vectorAvg, const vector <double> &v) {
    double diff = 0;
    double total = 0;
    int n = 0;
    double var = 0;
   //(5) FIXME - Calculate variance of vector numbers
   for(unsigned int i = 0; i < v.size(); i++){
       diff = vectorAvg - v.at(i);
       total += pow(diff, 2);
       n++;
   }
   var = (total / n);
   return var;
}

double standardDeviationForVariance(double vectorVariance) {
    double standDev = 0;
   //(6) FIXME - Calculate standard deviation
   standDev = sqrt(vectorVariance);
   return standDev;
}

int main() {
   //(3) FIXME - Declare vector of doubles
   vector<double> numList;
   double avg = 0.0;
   double var = 0.0;
   double stdDev = 0.0;
   unsigned int i = 0;

   //(3) FIXME - Call fillVector() function
    fillVector(numList);
   cout << "You entered: ";
   //(3) FIXME - Print vector values (use i variable)
    while (i < numList.size()){
        cout << numList.at(i) << " ";
        i++;
    }
    cout << endl;    
   //(4) FIXME - Call meanVector() function
    avg = meanVector(numList);
   //(5) FIXME - Call varianceVector() function
    var = varianceVector(avg, numList);
   //(6) FIXME - Call standardDeviationForVariance() function
    stdDev = standardDeviationForVariance(var);
   cout << "The mean is: " << avg << endl;
   cout << "The variance is: " << var << endl;
   cout << "The standard deviation is: " << stdDev << endl;

   return 0;
}