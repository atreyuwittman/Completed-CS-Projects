#include <iostream>
#include "GenericTree1.ccp"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    //cout << argc;
    if(argc == 2)
    {
        ifstream inFS;
        double rootD;
        double parentD;
        double newValD;
        string rootS;
        string parentS;
        string newValS;
        
        ifstream myFile (argv[argc - 1]);
        
        if(argc == 2)
        {
            char type = 'n';
            
            if ( myFile.is_open() )
            {
                //cout << endl << argc;
                myFile >> type;
                if(type == 'd' || type == 'D')
                {
                    //cout << endl << argc;
                    myFile >> rootD;
                    GenericTree<double> t(rootD);
                    while(myFile >>newValD)
                    {
                        myFile >> parentD;
                        //cout << newValD << parentD;
                        t.insert(newValD, parentD);
                    }
                    
                    t.print_Tree();
                    cout << endl;
                    int highest = t.set_height();
                    t.print_Tree();
                
                   cout << "The maximum height = " << highest << endl;
                }
                else if(type == 's' || type == 'S')
                {
                    //cout << endl << argc;
                    myFile >> rootS;
                    GenericTree<string> t(rootS);
                    while(myFile >>newValS)
                    {
                        myFile >> parentS;
                        //cout << newValD << parentD;
                        t.insert(newValS, parentS);
                    }
                    
                    t.print_Tree();
                    cout << endl;
                    int highest = t.set_height();
                    t.print_Tree();
                
                   cout << "The maximum height = " << highest << endl;
                }
            }
        }
    
    
    
    
    
    
    //     char type = 'n';
    //     string holdS = "";
        
    //     istringstream ss;
    // 	string inp;
    	
    //     if(myFile.is_open())
    //     {
    //         getline(myFile, inp);
    //         ss >> type;
    //         if(type == 'd' || type == 'D')
    //         {
    //             double root_val = 0;
    //             double new_val = 0.0;
    //             double parent_val = 0.0;
                
    //             ss >> root_val;
                
    //             GenericTree<double> t(root_val);
                
    //             ss.clear();
    //             while(getline(myFile, inp) )
    //             {
    //             	ss.clear();
    //             	ss.str(inp);
                	
    //             	if(!ss.eof())
    //             	{
    //             	    ss >> new_val;
    //             	    ss >> parent_val;
    //             	    t.insert(new_val, parent_val);
    //             	}
    //             }
                
    //             t.print_Tree();
    //             int highest = t.set_height();
    //             t.print_Tree();
                
    //             cout << "The maximum height = " << highest << endl;
            
    //         }
            
    //     }
        
    }

}
