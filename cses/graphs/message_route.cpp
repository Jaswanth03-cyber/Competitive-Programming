#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ;
    int edges ; 
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    vector<int> distance ;
    vector<int> parent ;
    public:
    graph(int n, int m){
        this->vertices = n ;
        this->edges = m ;
        adjlist.resize(this->vertices) ;
        visited.resize(this->vertices + 1) ;
        fill(visited.begin(), visited.end(), false) ;
        distance.resize(this->vertices + 1) ;
        fill(distance.begin(), distance.end(), 0) ;
        parent.resize(this->vertices + 1) ;
        fill(parent.begin(), parent.end(), -1) ;
    }

    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        adjlist[b-1].push_back(a) ;
    }

    void bfs(int source){
        queue<int> pq ;
        visited[source] = true ;
        pq.push(source) ;
        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;
            for(unsigned int i = 0 ; i < adjlist[top-1].size() ; i++){
                if(!visited[adjlist[top-1][i]]){
                    distance[adjlist[top-1][i]] = distance[top] + 1 ;
                    visited[adjlist[top-1][i]] = true ;
                    pq.push(adjlist[top-1][i]) ;
                    parent[adjlist[top-1][i]] = top ;
                }
            }
        }
    }

    vector<int> path(int n){
        vector<int> final_path ;
        for(int i = n ; i != -1 ; i = parent[i]){
            final_path.push_back(i) ;
        }
        reverse(final_path.begin(), final_path.end()) ;
        return final_path ;
    }

    int distance_source(int source, int n){
        bfs(source) ;
        return distance[n] ;
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

    int distance = g.distance_source(1,n) ;
    vector<int> final_path = g.path(n) ;
    if(distance == 0){
        cout<<"IMPOSSIBLE"<<endl ;
    }
    else{
        cout<<distance+1<<endl ;
        for(unsigned int i = 0 ; i < final_path.size() ; i++){
            cout<<final_path[i]<<" " ;
        }
        cout<<endl ;
    }

    return 0 ;
}