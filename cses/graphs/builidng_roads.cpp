#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ;
    int edges ;
    int components ;
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    vector<int> required ;
    public:
    graph(int n, int m){
        this->vertices = n ; 
        this->edges = m ;
        this->components = 0 ;
        adjlist.resize(this->vertices) ;
        visited.resize(n+1);
        fill(visited.begin(), visited.end(), false) ;
    }

    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        adjlist[b-1].push_back(a) ;
    }

    void dfs(int source){
        if(!visited[source]){
            visited[source] = true ;
            for(unsigned int i = 0 ; i < adjlist[source-1].size() ; i++){
                dfs(adjlist[source-1][i]) ;
            }
        }
    }

    void find_components(){
        for(int i = 1 ; i <=this->vertices ; i++){
            if(!visited[i]){
                required.push_back(i) ;
                dfs(i) ;
                this->components++ ;
            }
        }
    }

    vector<int> roads_required(){
        return this->required ;
    }

    int no_of_components(){
        return this->components ;
    }



};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ;
    int m ;
    cin>>n>>m ;
    graph g(n, m) ;

    for(int i = 0 ; i < m ; i++){
        int a ; 
        int b ; 
        cin>>a>>b ; 
        g.addedge(a,b) ;
    }
    g.find_components() ;
    cout<<g.no_of_components()-1<<endl ;
    vector<int> result ;
    result = g.roads_required() ;
    for(unsigned int i = 1 ; i < result.size() ; i++){
        cout<<result[0]<<" "<<result[i]<<endl ;
    }
    return 0 ;
}