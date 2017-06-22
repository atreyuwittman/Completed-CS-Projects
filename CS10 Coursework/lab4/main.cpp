#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string sentence;
    
    
    cout << "Enter text: " << endl;
    getline(cin, sentence);
    cout << "You entered: " << sentence << endl;
    
    //for (int i = 0; i < sentence.size(); i++){
   /* void find_and_replace(string& source, string const& find, string const& replace)
    for(string::size_type int i = 0; (i = sentence.find(find, i)) != string::npos)
    {
        sentence.replace(i, find.length(), replace);
        i += replace.length();
*/
    if (sentence.find("BFF") != string::npos){
        //cout << "BFF: best friend forever" << endl;
       int a = sentence.find("BFF");
       sentence.replace(a, 3, "best friend forever");
       // find_and_replace(sentence, "BFF", "best friend forever");
       }
    if (sentence.find("IDK") != string::npos){
       //cout << "IDK: I don't know" << endl;
        int b = sentence.find("IDK");
        sentence.replace(b, 3, "I don't know");
       //  find_and_replace(sentence, "IDK", "I don't know");  
     }
    if (sentence.find("JK") != string::npos){
       // cout << "JK: just kidding" << endl;
       int c = sentence.find("JK");
       sentence.replace(c, 2, "just kidding");
    // find_and_replace(sentence, "JK", "just kidding");  
    }
    if (sentence.find("TMI") != string::npos){
      //  cout << "TMI: too much information" << endl;
       int d = sentence.find("TMI");
       sentence.replace(d, 3, "too much information");
    // find_and_replace(sentence, "TMI", "too much information");  
    }
    if (sentence.find("TTYL") != string::npos){
       // cout << "TTYL: talk to you later" << endl;
       int e = sentence.find("TTYL");
       sentence.replace(e, 4, "talk to you later");
    //  find_and_replace(sentence, "TTYL", "talk to you later"); 
    }
    if (sentence.find("BFF") != string::npos){
        //cout << "BFF: best friend forever" << endl;
       int a = sentence.find("BFF");
       sentence.replace(a, 3, "best friend forever");
       // find_and_replace(sentence, "BFF", "best friend forever");
       }
    if (sentence.find("IDK") != string::npos){
       //cout << "IDK: I don't know" << endl;
        int b = sentence.find("IDK");
        sentence.replace(b, 3, "I don't know");
       //  find_and_replace(sentence, "IDK", "I don't know");  
     }
    if (sentence.find("JK") != string::npos){
       // cout << "JK: just kidding" << endl;
       int c = sentence.find("JK");
       sentence.replace(c, 2, "just kidding");
    // find_and_replace(sentence, "JK", "just kidding");  
    }
    if (sentence.find("TMI") != string::npos){
      //  cout << "TMI: too much information" << endl;
       int d = sentence.find("TMI");
       sentence.replace(d, 3, "too much information");
    // find_and_replace(sentence, "TMI", "too much information");  
    }
    if (sentence.find("TTYL") != string::npos){
       // cout << "TTYL: talk to you later" << endl;
       int e = sentence.find("TTYL");
       sentence.replace(e, 4, "talk to you later");
    //  find_and_replace(sentence, "TTYL", "talk to you later"); 
    }
  // }

   
    
     
    cout << "Expanded: " << sentence << endl;
    /*for (int i = 0; i <= (sentence.size; i++){

       switch(sentence[i])
       {
        case "BFF":
        sentence[i] = "best friends forever";
        break;
         }
         switch(sentence[i])
       {
        case "TTYL":
        sentence[i] = "talk to you later";
        break;
         }
         switch(sentence[i])
       {
        case "TMI":
        sentence[i] = "too much information";
        break;
         }
         switch(sentence[i])
       {
        case "JK":
        sentence[i] = "just kidding";
        break;
         }
         switch(sentence[i])
       {
        case "IDK":
        sentence[i] = "I don't know";
        break;
         }
      
   }*/
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
    
}