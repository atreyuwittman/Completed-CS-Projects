#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "GenericTreeClass.cc"

using namespace std;

int main(int argc, char* argv[]){
    if(argc == 2){
        ifstream inFS;
        double rootD;
        double parentD;
        double new_valD;
        string rootS;
        string parentS;
        string new_valS;
        ifstream fileName (argv[1]);
        if(argc == 2){
            char type = 'y';
            if (fileName.is_open()){
                fileName >> type;
                if(type == 'd' || type == 'D'){
                    fileName >> rootD;
                    GenericTree<double> t(rootD);
                    while(fileName >>new_valD){
                        fileName >> parentD;
                        t.insert(new_valD, parentD);
                    }
                    t.print_Tree();
                    cout << endl;
                    int max_height = t.set_height();
                    t.print_Tree();
                    t.dump_hash_table();
                   cout << "Max height = " << max_height << endl;
                   t.hang_left();
                   t.print_Tree();
                }
                else if(type == 's' || type == 'S'){
                    fileName >> rootS;
                    GenericTree<string> t(rootS);
                    while(fileName >>new_valS){
                        fileName >> parentS;
                        t.insert(new_valS, parentS);
                    }
                    t.print_Tree();
                    cout << endl;
                    int max_height = t.set_height();
                    t.print_Tree();
                    t.dump_hash_table();
                   cout << "Max height = " << max_height << endl;
                   t.hang_left();
                   t.print_Tree();
                }
            }
        }
    }
    return 0;
}