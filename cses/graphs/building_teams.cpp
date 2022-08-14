#include<bits/stdc++.h> 
using namespace std ;

class graph{
    public:
    int vertices ;
    int edges ;
    vector<vector<int>> adjlist ;
    vector<int> side ;
    public:
    graph(int n, int m){
        this->vertices = n ;
        this->edges = m ;
        adjlist.resize(this->vertices) ;
        side.resize(this->vertices + 1) ;
        fill(side.begin(), side.end(), -1) ;
    }

    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        adjlist[b-1].push_back(a) ; 
    }

    void check_is_bipartite(){
        queue<int> pq ;
        bool is_bipartite = true ;
        for(int i = 1 ; i <= this->vertices ; i++){
            if(side[i] == -1){
                pq.push(i) ;
                side[i] = 0 ;
                while(!pq.empty()){
                    int top = pq.front() ;
                    pq.pop() ;
                    for(unsigned int j = 0 ; j < adjlist[top-1].size() ; j++){
                        if(side[adjlist[top-1][j]] == -1){
                            side[adjlist[top-1][j]] = side[top]^1 ;
                            pq.push(adjlist[top-1][j]) ;
                        }
                        else{
                            if(side[adjlist[top-1][j]] == side[top]){
                                is_bipartite = false ;
                            }
                        }
                    }
                }
            }
        }

        if(is_bipartite){
            for(int i = 1 ; i <=this->vertices ; i++){
                cout<<side[i]+1<<" " ;
            }
            cout<<endl ;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl ;
        }
    }
};


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    int m ;
    cin>>n>>m ;

    graph g(n,m) ;

    for(int i = 0 ; i < m ; i++){
        int a ;
        int b ;
        cin>>a>>b ;
        g.addedge(a,b) ;
    }
    g.check_is_bipartite() ;
    return 0 ;
}