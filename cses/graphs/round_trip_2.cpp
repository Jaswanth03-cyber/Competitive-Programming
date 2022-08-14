#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ;
    int edges ;
    vector<vector<int>> adjlist ;
    vector<char> color ;
    int cycle_start ;
    int cycle_end ;
    vector<int> parent ;
    vector<int> cycle_path ;
    public:
    graph(int n, int m){
        this->vertices = n ;
        this->edges = m ;
        adjlist.resize(this->vertices) ;
        color.resize(this->vertices + 1) ;
        fill(color.begin(), color.end(), 'W') ;
        parent.resize(this->vertices + 1) ;
        this->cycle_start = - 1;
        this->cycle_end = -1 ;
    }

    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        // adjlist[b-1].push_back(a) ;
    }

    bool dfs(int source){
        if(color[source] == 'W'){
            color[source] = 'G' ;
            for(unsigned int j = 0 ; j < adjlist[source-1].size() ; j++){
                if(color[adjlist[source-1][j]] == 'W'){
                    parent[adjlist[source-1][j]] = source ;
                    if(dfs(adjlist[source-1][j])){
                        return true ;
                    }
                }
                else if(color[adjlist[source-1][j]] == 'G'){
                    cycle_start = adjlist[source-1][j] ;
                    cycle_end = source ;
                    return true ;
                }
            }
        }
        color[source] = 'B' ;
        return false ;
    }

    void find_cycle(){
        for(int i = this->vertices ; i >= 1 ; i--){
            if((color[i] == 'W') && (dfs(i))){
                break ;
            }
        }

        if(this->cycle_start == -1){
            cout<<"IMPOSSIBLE"<<endl ;
        }
        else{
            cycle_path.push_back(cycle_start) ;
            for(int i = cycle_end ; i != cycle_start ; i = parent[i]){
                cycle_path.push_back(i) ;
            }
            cycle_path.push_back(cycle_start) ;
            reverse(cycle_path.begin(), cycle_path.end()) ;
            cout<<cycle_path.size()<<endl ;
            for(unsigned int i = 0 ; i < cycle_path.size() ; i++){
                cout<<cycle_path[i]<<" " ;
            }
            cout<<endl ;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ;
    int m ;
    cin>>n>>m ;

    graph g(n, m) ;

    for (int i = 0 ; i < m ; i++){
        int a ; 
        int b ;
        cin>>a>>b ;
        g.addedge(a,b) ;
    }
    g.find_cycle() ;
    return 0 ;
}