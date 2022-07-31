#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ;
    int edges ;
    vector<int> *adjlist ;
    vector<bool> visited ;
    vector<vector<int>> connected_component ;
    int components ;
    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ; 
        adjlist = new vector<int>[n] ;
        visited.resize(n) ;
        fill(visited.begin(), visited.end(), false) ;
        this->components = 0 ;
    }

    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        //adjlist[b-1].push_back(a) ; // even works for undirected too
        this->edges++ ;
    }

    void dfs(int source, vector<int> &comp){
        visited[source-1] = true ; 
        comp.push_back(source) ;
        for(int i = 0 ; i < adjlist[source-1].size() ; i++){
            if(!visited[adjlist[source-1][i] - 1]){
                dfs(adjlist[source-1][i], comp) ;
            }
        }
    }

    void find_components(){
        for(int i = 0 ; i < this->vertices ; i++){
            if(!visited[i]){
                connected_component.emplace_back() ;
                dfs(i+1, connected_component[this->components]) ;
                this->components++ ;
            }
        }
        cout<<"Number of connected components in the graph are "<<this->components<<endl ;
        for(int i = 0 ; i < connected_component.size() ; i++){
            cout<<"Vertices that are present in the "<<i+1<<" component are as follows : " ;
            for(int j =0 ; j < connected_component[i].size() ; j++){
                cout<<connected_component[i][j]<<" " ;
            }
            cout<<endl ;
        }
    }
    ~graph(){
        delete[] adjlist ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    graph g(9) ;
    g.addedge(1,2) ;
    g.addedge(1,3) ;
    g.addedge(3,9) ;
    g.addedge(1,9) ;
    g.addedge(5,6) ;
    g.addedge(6,7) ;
    g.addedge(7,5) ;
    g.addedge(8,4) ;

    g.find_components() ;
    return 0 ;
}