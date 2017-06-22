#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <cstdlib>

using namespace std;

class GenericGraph{
private:
    struct Vertex{
        string name;
        vector<int> edges; // holds adjacent edge numbers
    };
    struct Edge{
        string name;
        double weight;
        pair<int, int> endpoints; // holds vertex numbers for the two vertices it connects
        bool selected; // does it belong to the most-recently created spanning tree?
    };
    vector<Edge> E;
    vector<Vertex> V;
    int *id, cnt, *sz;
public:
    explicit GenericGraph(const Edge& e) : Edge(&e){}
    bool operator()(const Edge& lhs, const Edge& rhs) const { return lhs.weight < rhs.weight;}
    int loc;
    int vertexValid;
    int edgeValid;
    void UF(int N){
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    void deleteUF()	{
    for(int i = 0; i < E.size(); i++){
        E.at(i).selected = false;
    }
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
		
		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{ 
		id[i] = j; 
		sz[j] += sz[i]; 
	} else	{ 
		id[j] = i; 
		sz[i] += sz[j]; 
	}
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
    GenericGraph(int numVertices, int numEdges){
        E.resize(numEdges);
        V.resize(numVertices);
        UF(numVertices);
    }
    
    int vertex(const string & name2){
            for(int i = 0; i < V.size(); i++){
                if(name2 == V.at(i).name){
                    return -1;
                }
            }
            if(loc > V.size()){
                return -2;
            }
            else{
                V.at(loc).name = name2;
            }
        return 1;
    }
    int edge(const string & name, double weight, const string & v1, const string & v2){
            char v1nameUsed = 'n';
            char v2nameUsed = 'n';
            int edgePairv1 = 0;
            int edgePairv2 = 0;
            for(int i = 0; i < E.size(); i++){
                if(name == E.at(i).name){
                    return -1;
                }
                if(i < V.size()){
                    if(v1 == V.at(i).name){
                        v1nameUsed = 'y';
                        edgePairv1 = i;
                    }
                    if(v2 == V.at(i).name){
                        v1nameUsed = 'y';
                        edgePairv2 = i;
                    }
                }
            }
            for(int i = 0; i < E.size(); i++){
                if(E.at(i).endpoints.first == E.at(loc).endpoints.first && E.at(i).endpoints.second == E.at(loc).endpoints.second){
                    if(E.at(i).endpoints.first == 0 && E.at(i).endpoints.second == 0){
                        break;
                    }
                    else{
                    cout << E.at(i).endpoints.first << "!! ";
                    cout << E.at(loc).endpoints.first << " ";
                    cout << E.at(i).endpoints.second << " !!";
                    cout << E.at(loc).endpoints.second << " ";
                    return -4;
                    }
                }
            }
            if(loc > E.size()){
                return -2;
            }
            if(v1nameUsed != 'y' && v2nameUsed != 'y'){
                return -3;
            }
            else{
                E.at(loc).name = name;
            }
            E.at(loc).weight = weight;
            int p1 = edgePairv1;
            int p2 = edgePairv2;
            E.at(loc).endpoints.first = p1;
            E.at(loc).endpoints.second = p2;
            V.at(edgePairv1).edges.push_back(loc);
            V.at(edgePairv2).edges.push_back(loc);
            
        return 1;
    }
    bool valid(){
        if(vertexValid == 1 && edgeValid == 1){
            return true;
        }
        else{
            return false;
        }
    }
    double NUTs(std::vector<string> & edgeList){
        double totalWeight = 0.0;
        int edgeCount = 0;
        deleteUF();
        UF(V.size());
        for(int i = 0 ; i < V.size(); i++){
            if(edgeCount > E.size() - 1){
                break;
            }
            for(int j = 0; j < V.at(i).edges.size(); j++){
                int u = E.at(V.at(i).edges.at(j)).endpoints.first;
                int v = E.at(V.at(i).edges.at(j)).endpoints.second;
                if(find(u) != find(v)){
                    E.at(V.at(i).edges.at(j)).selected = true;
                    edgeCount++;
                    totalWeight += E.at(V.at(i).edges.at(j)).weight;
                    edgeList.push_back(E.at(V.at(i).edges.at(j)).name);
                    merge(u, v);
                }
                else{
                }
            }
        }
        sort(edgeList.begin(), edgeList.end());
        return totalWeight;
    }
    int treeDetails (const vector<string> & edgeList, vector<vector<string>> & fragments){
        int edgeAmount = 0;
        for(int i = 0; i < edgeList.size(); i++){
            int l = 0;
            for(int j = 0; j < V.size(); j++){
                if(V.at(j).edges.size() > l){
                    if(edgeList.at(i) == E.at(V.at(j).edges.at(l)).name){
                        fragments.resize(edgeAmount + 1);
                        fragments[edgeAmount].push_back(V.at(j).name);
                        int pointA = E.at(V.at(j).edges.at(0)).endpoints.first;
                        int pointB = E.at(V.at(j).edges.at(0)).endpoints.second;
                        for(int k = 0; k < E.size(); k++){
                            if(connected(E.at(k).endpoints.first, pointA) == true || connected(E.at(k).endpoints.second, pointB) == true){
                            if(E.at(k).selected == true){
                                fragments[edgeAmount].push_back(E.at(k).name);
                                }
                            }
                        }
                        edgeAmount++;
                    }
                    l++;
                }
            }
            
        }
        return cnt;
    }
    
    /*double Kruskal ( vector < string > & edgeList ){
        
        priority_queue<Edge, vector<Edge>, GenericGraph> pq;
        /*vector<Edge> temp;
        int mstWeight = 0;
        deleteUF();
        UF(V.size());
        temp.resize(E.size());
        for(int i = 0; i < E.size(); i++){
            temp.at(i) = E.at(i);
        }
        for(int i = 0; i < temp.size(); i++){
            for(int j = i + 1; j < temp.size(); j++){
                if(temp.at(i).weight < temp.at(j).weight){
                    swap(temp.at(i), temp.at(j));
                }
            }
        }
        for(int i = 0; i < temp.size(); i++){
            pq.push(temp.at(i));
        }*/
    /*double Prim ( int root, vector < string > & edgeList ){
        
    }
    double PrimPlus ( vector < string > & edgeList ){
        
    }
    double YAMA ( vector < string > & edgeList ){
        
    }*/
    
};
