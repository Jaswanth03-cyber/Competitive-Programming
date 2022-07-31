#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ; 
    int edges ;
    vector<int> *adjlist ;
    vector<char> color ; 
    vector<int> parent ;
    int cycle_end ;
    int cycle_start ;
    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ;
        adjlist = new vector<int>[this->vertices] ;
        color.resize(this->vertices + 1) ;
        parent.resize(this->vertices + 1) ;
        fill(color.begin(), color.end(), 'W') ;
        fill(parent.begin(), parent.end(), -1) ;
        this->cycle_start = -1 ;
        this->cycle_end = -1 ;
    }

    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        this->edges++ ;
    }

    bool dfs(int source){
        if(color[source] == 'W'){
            color[source] = 'G' ;
            for(int i = 0 ; i < adjlist[source-1].size() ; i++){
                if(color[adjlist[source-1][i]] == 'W'){
                    parent[adjlist[source-1][i]] = source ;
                    if(dfs(adjlist[source-1][i])){
                        return true ;
                    }
                }
                else if(color[adjlist[source-1][i]] == 'G'){
                    cycle_start = adjlist[source-1][i] ;
                    cycle_end = source ;
                    return true ;
                }
            }
        }
        color[source] = 'B' ;
        return false ;
    }

    void find_cycle(){
        for(int i = 1 ; i <=this->vertices ; i++){
            if((color[i] == 'W') && (dfs(i))){
                break ;
            }
        }

        if(cycle_start == -1){
            cout<<"Graph is acyclic which means there is no cycle in the graph "<<endl ;
        }
        else{
            vector<int> path ; 
            path.push_back(cycle_start) ;
            for(int i = cycle_end ; i != cycle_start ; i = parent[i]){
                path.push_back(i) ;
            }
            path.push_back(cycle_start) ;
            reverse(path.begin(), path.end()) ;
            cout<<"The graph is not cyclic there is atleast one cycle and we have found one cycle which as shown : " ;
            for(int i = 0 ; i < path.size() ; i++){
                cout<<path[i]<<" " ;
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

    graph g(6) ;
    g.addedge(1,2) ;
    g.addedge(2,3) ;
    g.addedge(3,4) ;
    g.addedge(4,5) ;
    g.addedge(5,6) ;
    g.addedge(6,1) ;
    g.addedge(5,3) ;
    g.addedge(4,2) ;

    g.find_cycle() ;


    graph G(6) ;
    G.addedge(1,2) ;
    G.addedge(2,3) ;
    G.addedge(3,4) ;
    G.addedge(4,5) ;
    G.addedge(5,6) ;

    G.find_cycle() ;

    graph Gg(9) ;
    Gg.addedge(1,2) ;
    Gg.addedge(2,3) ;
    Gg.addedge(3,4) ;
    Gg.addedge(4,5) ;
    Gg.addedge(5,6) ;
    Gg.addedge(6,7) ;
    Gg.addedge(7,8) ;
    Gg.addedge(8,1) ;
    Gg.addedge(8,9) ;
    Gg.addedge(8,2) ;
    Gg.addedge(9,7) ;
    Gg.addedge(3,9) ;
    Gg.addedge(6,4) ;
    Gg.addedge(3,6) ;

    Gg.find_cycle() ;

    return 0 ;
}