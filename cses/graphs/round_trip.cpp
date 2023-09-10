#include<bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    vector<int> parent ;
    int start ;
    int end ;
    public:
    graph(int n){
        this->vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n) ;
        parent.resize(n) ;
        fill(visited.begin(), visited.end(), false) ;
        fill(parent.begin(), parent.end(), -1) ;
        start = -1 ;
        end = -1 ;
    }
    void add(int a, int b){
        adjlist[a-1].push_back(b) ;
        adjlist[b-1].push_back(a) ;
    }

    bool dfs(int src, int par){
        visited[src-1] = true ;
        int size = adjlist[src-1].size() ;
        for(int i = 0 ; i < size ; i++){
            if(adjlist[src-1][i] == par){
                continue ;
            }
            if(visited[adjlist[src-1][i]-1]){
                start = adjlist[src-1][i] ;
                end = src ;
                return true ;
            }
            parent[adjlist[src-1][i]-1] = src ;
            if(dfs(adjlist[src-1][i], src)){
                return true ;
            }
        }
        return false ;
    }

    void cycle(){
        for(int i = 1 ; i <= this->vertices ; i++){
            if(!visited[i-1] && dfs(i, parent[i-1])){
                break ;
            }
        }

        if(start == -1){
            cout<<"IMPOSSIBLE"<<endl ;
        }
        else{
            vector<int> path ;
            path.push_back(start) ;
            for(int i = end ; i != start ; i = parent[i-1]){
                path.push_back(i) ;
            }
            path.push_back(start) ;
            int size = path.size() ;
            cout<<size<<endl ;
            for(int i = 0 ; i < size ; i++){
                cout<<path[i]<<" " ;
            }
            cout<<endl ;
        }
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    int m = 0 ;
    cin>>m ;
    graph g(n) ;
    int a = 0, b = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>a>>b ;
        g.add(a, b) ;
    }
    g.cycle() ;
    return 0 ;
}