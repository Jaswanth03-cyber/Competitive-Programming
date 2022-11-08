#include<bits/stdc++.h>
using namespace std ;
class graph{
    private:
    int vertices ;
    int edges ;
    vector<int>* adj ;      // we can even have node in place of int which is a struct containing data and directions if needed
    public:
    graph(int n){
        vertices = n ;
        edges = 0 ;
        adj = new vector<int>[n] ;
    }
    void addedge(int u, int v){     // u,v  vertices 
        adj[u-1].push_back(v) ;       // assuming vertices start from 1,2,3...
        adj[v-1].push_back(u) ;
        edges++ ;
        return ;
    }
    int getvertices(){
        return this->vertices ;
    }
    int getedges(){
        return this->edges ;
    }
    void print_adj_vertex(int j){
        cout<<"vertices that are adjacent to the vertex "<<j<<" are : " ;
        for(auto i = adj[j-1].begin() ; i != adj[j-1].end(); i++){
            cout<<*i<<" " ;
        }
        cout<<endl ;
        return ;
    }
    void print_graph(){
        for(int i = 1 ; i <= this->vertices ; i++){
            print_adj_vertex(i) ;
        }
        return ;
    }
    void remove_edge(int u, int v){
        for(auto i = adj[u-1].begin(); i != adj[u-1].end(); i++){
            if(*i == v){
                adj[u-1].erase(i) ;
                break ;
            }
            if( (i == adj[u-1].end() -1) && (*i != v)){
                cout<<"There is no edge between "<<u<<" and "<<v<<" in the graph"<<endl ;
                return ;
            }
        }
        for(auto i = adj[v-1].begin(); i != adj[v-1].end(); i++){
            if(*i == u){
                adj[v-1].erase(i) ;
                break ;
            }
            if( (i == adj[v-1].end() -1) && (*i != u)){
                cout<<"There is no edge between "<<u<<" and "<<v<<" in the graph"<<endl ;
                return ;
            }
        }
        edges-- ;
        return ;
    }
    ~graph(){
        delete[] adj ;
    }
};
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    graph g(6) ;
    g.addedge(1,4) ;
    g.addedge(6,1) ;
    g.addedge(3,6) ;
    g.addedge(3,2) ;
    g.addedge(3,5) ;
    g.addedge(5,4) ;
    g.addedge(2,5) ;
    g.addedge(4,2) ;
    g.addedge(2,1) ;
    // int a = g.vertices() ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    // g.print_adj_vertex(2) ;
    g.print_graph() ;
    cout<<"---------------------------"<<endl ;
    g.remove_edge(1,2) ;
    // g.print_adj_vertex(2) ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    g.print_graph() ;
    cout<<"---------------------------"<<endl ;
    g.remove_edge(3,4) ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    g.print_graph() ;
    return 0 ;
}