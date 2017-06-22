#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


class Date
{
 private:
   unsigned day;
   unsigned month;
   std::string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date(){
       day = 1;
       month = 1;
       monthName = "January";
       year = 2000;
   };

   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y){
        month = m;
        monthName = name(month);
        day = d;
        year = y;
        if(month > 12 || month < 1){
            if(month < 1){
                month = 1;
                monthName = name(month);
                
            }
            else if(month > 12){
                month = 12;
                monthName = name(month);
                  
            }
            
        }
        if(day > daysPerMonth(month, year) || day < 1){
                    if(day > daysPerMonth(month, year)){
                    day = daysPerMonth(month, year);
                    cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
                    }
                    else if(day < 1){
                    day = 1;
                    cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
                    }
                }
        
        
        
        
        
        
        
        return;
   }   

   /* parameterized constructor: month name, day, year
 ­      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000 
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y){
        month = number(mn);
        monthName = name(month);
        day = d;
        year = y;
        
        if(monthName == "January" || monthName == "january"){
        }
        else if(monthName == "February" || monthName == "february"){
        }
        else if(monthName == "March" || monthName == "march"){
        }
        else if(monthName == "April" || monthName == "april"){
        }
        else if(monthName == "May" || monthName == "may"){
        }
        else if(monthName == "June" || monthName == "june"){
        }
        else if(monthName == "July" || monthName == "july"){
        }
        else if(monthName == "August" || monthName == "august"){
        }
        else if(monthName == "September" || monthName == "september"){
        }
        else if(monthName == "October" || monthName == "october"){
        }
        else if(monthName == "November" || monthName == "november"){
        }
        else if(monthName == "December" || monthName == "december"){
        }
        else{
            day = 1;
            year = 2000;
            month = 1;
            monthName = "January";
            cout << "Invalid month name: the Date was set to " << month << '/' << day << '/' << year << '.' << endl;
            return;
        }
        if(day > daysPerMonth(month, year) || day < 1){
            if(day > daysPerMonth(month, year)){
                day = daysPerMonth(month, year);
                cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
            }
            else if(day < 1){
                day = 1;
                cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
            }
        }
        
        return;
   }
   /* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const{
       cout << month << '/' << day << '/' << year;
       
       return;
   };

   /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const{
        cout << monthName << ' ' << day << ", " << year;
   }
   /* Add a number of days to one date to get another: 
      this number may be positive or negative.
      Obviously, the new date will be a valid date, 
      accounting for the correct number of days in each month, 
      and for leap years. Gregorian calendar leap year rules
      used no matter how many negative days passed in.
   */
   // Only uncomment the following function (addDays) declaration
   // if you are trying for the extra credit
   // Date addDays(int d) const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const{
     if((y % 4) == 0){
         if((y % 400) == 0){
             if((y % 100) == 0){
                 return false;
             }
         }
     }
     else if((y % 400) == 0){
         if((y % 100) == 0){
             return false;
         }
     }
     else if((y % 4) == 0 || (y % 400) == 0){
         return true;
     }
     return false;
   };


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-­leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const{
        if(m == 1){
           return 31;
       }
        if(m == 2){
           if(isLeap(y) == true){
               return 29;
           }
           else {
               return 28;
           }
       }
       if(m == 3){
           return 31;
       }
       if(m == 4){
           return 30;
       }
       if(m == 5){
           return 31;
       }
       if(m == 6){
           return 30;
       }
       if(m == 7){
           return 31;
       }
       if(m == 8){
           return 31;
       }
       if(m == 9){
           return 30;
       }
       if(m == 10){
           return 31;
       }
       if(m == 11){
           return 30;
       }
       if(m == 12){
           return 31;
       }
       return 0;
    };
   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   std::string name(unsigned m) const{
     if(m == 1){
           return "January";
       }
       if(m == 2){
           return "February";
       }
       if(m == 3){
           return "March";
       }
       if(m == 4){
           return "April";
       }
       if(m == 5){
           return "May";
       }
       if(m == 6){
           return "June";
       }
       if(m == 7){
           return "July";
       }
       if(m == 8){
           return "August";
       }
       if(m == 9){
           return "September";
       }
       if(m == 10){
           return "October";
       }
       if(m == 11){
           return "November";
       }
       if(m == 12){
           return "December";
       }
       return "";
   };

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const std::string &mn) const{
       if(mn == "January" || mn == "january"){
           return 1;
       }
       if(mn == "February" || mn == "february"){
           return 2;
       }
       if(mn == "March" || mn == "march"){
           return 3;
       }
       if(mn == "April" || mn == "april"){
           return 4;
       }
       if(mn == "May" || mn == "may"){
           return 5;
       }
       if(mn == "June" || mn == "june"){
           return 6;
       }
       if(mn == "July" || mn == "july"){
           return 7;
       }
       if(mn == "August" || mn == "august"){
           return 8;
       }
       if(mn == "September" || mn == "september"){
           return 9;
       }
       if(mn == "October" || mn == "october"){
           return 10;
       }
       if(mn == "November" || mn == "november"){
           return 11;
       }
       if(mn == "December" || mn == "december"){
           return 12;
       }
       return 0;
   }
 };
 
Date getDate();

int main() {
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   }
    else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}