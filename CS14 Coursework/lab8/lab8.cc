#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "GenericGraph.cc"

using namespace std;

int main(int argc, char* argv[]){
    
    if(argc == 2){
        ifstream inFS;
        string temp = "";
        string fileName = argv[1];
        if(argc == 2){
            int vert = 0;
            int edge = 0;
            string v1;
            string v2;
            int edgeWeight;
            vector<string> edgeList;
            vector<vector<string>> fragments;
            inFS.open(fileName.c_str());
            inFS >> vert;
            inFS >> edge;
            GenericGraph G(vert, edge);
                for(int i = 0; i < vert; i++){
                    inFS >> temp;
                    G.loc = i;
                    G.vertexValid = G.vertex(temp);
                }
                for(int i = 0; i < edge; i++){
                    inFS >> temp;
                    G.loc = i;
                    inFS >> edgeWeight;
                    inFS >> v1;
                    inFS >> v2;
                    G.edgeValid = G.edge(temp, edgeWeight, v1, v2);
                }
                G.valid();
                if(G.valid() == false){
                    return 0;
                }
                cout << "Weight of the tree: " << G.NUTs(edgeList) << endl;
                cout << "Edges in the tree: ";
                for(int i = 0; i < edgeList.size(); i++){
                    cout << edgeList.at(i) << " ";
                }
                cout << endl;
                int frag = G.treeDetails(edgeList, fragments);
                cout << "Number of Fragments in the tree: " << frag << endl;
                for(int i = 0; i < frag - 1; i++){
                    cout << "Fragment: " << i << "contains vertex " << fragments[i][0] << " and the following " << fragments[i].size()-1 << " edges: ";
                    for(int j = 0; j < fragments[i].size()-1; j++){
                        cout << fragments[i][j] << " ";
                    }
                    cout << endl;
                }
        }
    }
    return 0;
}