#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ; 
    int edges ; 
    vector<bool> visited ;
    vector<vector<int>> adjlist ; 
    vector<pair<int, int>> tree_edges ;
    vector<pair<int, int>> back_edges ;
    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ;
        visited.resize(this->vertices) ;
        adjlist.resize(this->vertices) ;
    }
    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        this->edges++ ;
    }

    void dfs(int source){
        if(!visited[source-1]){
            visited[source-1] = true ;
            for(int i = 0 ; i < adjlist[source-1].size() ; i++){
                if(!visited[adjlist[source-1][i] - 1]){
                    tree_edges.push_back(make_pair(source, adjlist[source-1][i])) ;
                    dfs(adjlist[source-1][i]) ;
                }
                else{
                    back_edges.push_back(make_pair(source, adjlist[source-1][i])) ;
                }
            }
        }
    }

    void show_edges(){
        cout<<"There are a total of "<<this->edges<<" edges in the graph "<<endl ;
        cout<<"There are "<<tree_edges.size()<<" and those edges are as follows : " ;
        for(int i = 0 ; i < tree_edges.size() ; i++){
            cout<<"( "<<tree_edges[i].first<<", "<<tree_edges[i].second<<" )"<<" " ;
        }
        cout<<endl ;
        cout<<"There are "<<back_edges.size()<<" back edges and those edges are as follows : " ;
        for(int i = 0 ; i < back_edges.size() ; i++){
            cout<<"( "<<back_edges[i].first<<", "<<back_edges[i].second<<" )"<<" " ;
        }
        cout<<endl ;
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
    g.addedge(6,4) ;
    g.addedge(5,3) ;
    g.addedge(4,2) ;
    g.dfs(1) ;
    g.show_edges() ;
    return 0 ;
}