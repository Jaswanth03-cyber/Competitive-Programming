#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ; 
    int edges ; 
    vector<int>* adjlist ; 
    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ; 
        adjlist = new vector<int>[n] ;
    }

    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        adjlist[b-1].push_back(a) ;
        this->edges++ ;
    }

    void is_bipartite(){
        vector<int> side(this->vertices, -1) ;
        bool is_bipartite = true ; 
        queue<int> q ; 

        for(int i = 0 ; i < this->vertices ; i++){
            if(side[i] == -1){
                q.push(i) ;
                side[i] = 0 ; 
                while(!q.empty()){
                    int top = q.front() ;
                    q.pop() ;
                    for(int j = 0 ; j < adjlist[top].size() ; j++){
                        if(side[adjlist[top][j] - 1] == -1){
                            side[adjlist[top][j] - 1] = side[top]^1 ;       // xor operator 
                            q.push(adjlist[top][j] - 1) ;
                        }
                        else{
                            if(side[top] == side[adjlist[top][j] - 1]){
                                is_bipartite = false ;
                            }
                        }
                    }
                }
            }
        }
        if(is_bipartite){
            cout<<"Yes the graph is bipartite and the two sets of the vertices are as follows  "<<endl ;
            cout<<"Vertices in the set 1 are as follows : " ;
            for(int i = 0 ; i < this->vertices ; i++){
                if(side[i] == 0){
                    cout<<i+1<<" " ;
                }
            }
            cout<<endl ;
            cout<<"Vertices in the set 2 are as follows : " ;
            for(int i = 0 ; i < this->vertices ; i++){
                if(side[i] == 1){
                    cout<<i+1<<" " ;
                }
            }
            cout<<endl ;
        }
        else{
            cout<<"The graph is not bipartite "<<endl ;
        }
    }
    ~graph(){
        delete[] adjlist ;
    }
};

/*
Note that here first vertex we assumed it to be in one of the side as we started with first vertex but its our wish
where we want to start the bfs 
*/

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    graph G(3) ;
    G.addedge(1,2) ;
    G.addedge(2,3) ;
    G.addedge(3,1) ;

    G.is_bipartite() ;


    graph g(6) ;
    g.addedge(1,2) ;
    g.addedge(2,3) ;
    g.addedge(3,4) ;
    g.addedge(4,5) ;
    g.addedge(5,6) ;
    g.addedge(6,1) ;

    g.is_bipartite() ;

    graph Gra(9) ;
    Gra.addedge(1,2) ;
    Gra.addedge(2,3) ;
    Gra.addedge(3,4) ;
    Gra.addedge(4,5) ;
    Gra.addedge(5,6) ;
    Gra.addedge(6,7) ;
    Gra.addedge(7,8) ;
    Gra.addedge(8,9) ;
    Gra.addedge(9,1) ;
    Gra.is_bipartite() ;


    graph gra(8) ;

    gra.addedge(1,5) ;
    gra.addedge(2,7) ;
    gra.addedge(3,6) ;
    gra.addedge(4,7) ;
    gra.addedge(3,5) ;
    gra.addedge(3,8) ;

    gra.is_bipartite() ;
    return 0 ; 
}