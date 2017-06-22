#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   srand(3333); // Do not change the seed value.
   
   // Declare all necessary variables
    
    int rollNum = 0;
    int rolls = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int eight = 0;
    int nine = 0;
    int ten = 0;
    int eleven = 0;
    int twelve = 0;
   cout << "Enter number of times you want to roll a pair of dice: ";
   cin >> rolls;
   cout << endl;    

   for(int i = 0; i < rolls; i++){
       rollNum = (rand() % 6 + 1);

   if(rollNum ==2){
       two++;
       
   }
   else if(rollNum ==3){
       three++;
       
   }
   else if(rollNum ==4){
       four++;
       
   }
   else if(rollNum ==5){
       five++;
      
   }
   else if(rollNum ==6){
       six++;
       
   }
   else if(rollNum ==7){
       seven++;
      
   }
   else if(rollNum ==8){
       eight++;
     
   }
   else if(rollNum ==9){
       nine++;
      
   }
   else if(rollNum ==10){
       ten++;
  
   }
   else if(rollNum ==11){
       eleven++;
    
   }
   else {
       twelve++;
    
   }
}
   cout << "# of times each score was rolled" << endl;
   cout << "2: " << two << endl;
   cout << "3: " << three << endl;
   cout << "4: " << four << endl;
   cout << "5: " << five << endl;
   cout << "6: " << six << endl;
   cout << "7: " << seven << endl;
   cout << "8: " << eight << endl;
   cout << "9: " << nine << endl;
   cout << "10: " << ten << endl;
   cout << "11: " << eleven << endl;
   cout << "12: " << twelve << endl;

   cout << endl;   
   cout << "Probability of rolling each possible score" << endl;
   cout << "2: " << ((static_cast<double>(two)/rolls)* 100) << "%" << endl;
   cout << "3: " << ((static_cast<double>(three)/rolls)* 100) << "%"  << endl;
   cout << "4: " << ((static_cast<double>(four)/rolls)* 100) << "%"  << endl;
   cout << "5: " << ((static_cast<double>(five)/rolls)* 100) << "%"  << endl;
   cout << "6: " << ((static_cast<double>(six)/rolls)* 100) << "%"  << endl;
   cout << "7: " << ((static_cast<double>(seven)/rolls)* 100) << "%"  << endl;
   cout << "8: " << ((static_cast<double>(eight)/rolls)* 100) << "%"  << endl;
   cout << "9: " << ((static_cast<double>(nine)/rolls)* 100) << "%"  << endl;
   cout << "10: " << ((static_cast<double>(ten)/rolls)* 100) << "%"  << endl;
   cout << "11: " << ((static_cast<double>(eleven)/rolls)* 100) << "%"  << endl;
   cout << "12: " << ((static_cast<double>(twelve)/rolls)* 100) << "%"   << endl;
   
   return 0;
}