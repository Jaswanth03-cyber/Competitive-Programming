#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ;
    int edges ; 
    vector<vector<int>> capacity ;
    vector<int> *adjlist ;
    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ;
        capacity.resize(this->vertices + 1) ;     // dummy row so that no confusion with indexes
        for(int i = 0 ; i <= this->vertices ; i++){
            capacity[i].resize(this->vertices) ;
        }
        adjlist = new vector<int>[this->vertices + 1] ;        // extra one for dummy so that no index confusion 
        for(int i = 0 ; i <= this->vertices ; i++){
            for(int j = 0; j <=this->vertices ; j++){
                capacity[i][j] = 0 ;
            }
        }
    }
    void addedge(int a, int b, int weight){
        adjlist[a].push_back(b) ;
        capacity[a][b] = weight ;
        this->edges++ ;
    }

    int dfs(int source, int sink, vector<int>& parent){
        fill(parent.begin(), parent.end(), -1) ;
        parent[source] = -2 ;
        queue<pair<int, int>> pq ;
        pq.push(make_pair(source, 1e5)) ;

        while(!pq.empty()){
            int top = pq.front().first ;
            int flow = pq.front().second ;
            pq.pop() ;
            for(int i = 0 ; i < adjlist[top].size() ; i++){
                if(parent[adjlist[top][i]] == -1 && capacity[top][adjlist[top][i]]){
                    parent[adjlist[top][i]] = top ; 
                    int new_flow = min(flow, capacity[top][adjlist[top][i]]) ;
                    if(adjlist[top][i] == sink){
                        return new_flow ;
                    }
                    pq.push(make_pair(adjlist[top][i], new_flow)) ;
                }
            }
        }
        return 0 ;
    }

    int ford_fulkerson(int source, int sink){
        int flow = 0 ; 
        vector<int> parent(this->vertices  + 1) ;
        int new_flow ;
        new_flow = dfs(source, sink, parent) ;
        while(new_flow != 0){
            flow = flow + new_flow ; 
            int current = sink ; 
            while(current != source){
                int previous = parent[current] ;
                capacity[previous][current] = capacity[previous][current] - new_flow ; 
                capacity[current][previous] = capacity[current][previous] + new_flow ;
            }
        }
        return flow ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    graph g(6) ;
    g.addedge(1,2,7) ;
    g.addedge(1,4,4) ;
    g.addedge(2,3,5) ;
    g.addedge(3,6,8) ;
    g.addedge(5,6,5) ;
    g.addedge(4,5,2) ;
    g.addedge(4,2,3) ;
    g.addedge(2,5,3) ;
    g.addedge(5,3,3) ;

    int flow = g.ford_fulkerson(1,6) ;
    cout<<flow<<endl ;
    return 0 ;
}