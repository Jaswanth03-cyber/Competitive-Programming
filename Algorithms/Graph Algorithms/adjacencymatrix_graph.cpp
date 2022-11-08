#include<bits/stdc++.h>
using namespace std ;
class graph{
    private:
    int vertices ;
    int edges ;
    int **weight;
    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ;
        weight = new int*[n] ;
        for(int i = 0 ; i < n ; i++){        // way of allocating dynamic memory for 2D arrays 
            weight[i] = new int[n] ;
        }
        for(int i = 0 ; i < this->vertices ; i++){
            for(int j = 0 ; j < this->vertices ; j++){
                weight[i][j] = 0 ;
            }                  
        } 
    }
    int getedges(){
        return this->edges ;
    }
    int getvertices(){
        return this->vertices ;
    }
    void addedge(int u, int v){
        weight[u-1][v-1] = 1 ;
        weight[v-1][u-1] = 1 ;
        edges++ ;
        return ;                                   // weights can be added instead of 1 too we can also have directed if we have 1 only for [u-1][v-1] but not for [v-1][u-1]
    }
    void remove_edge(int u, int v){
        if((weight[u-1][v-1] == 0) && (weight[v-1][u-1] == 0)){
            cout<<"There is no edge to remove "<<endl ;
            return ;
        }
        else{
            weight[u-1][v-1] = 0 ;
            weight[v-1][u-1] = 0 ;
        }
        edges-- ;
        return ;
    }
    void print_adj_vertices(int j){
        cout<<"Vertices that are adjacent to vertex "<<j<<" are as follows : " ;
        for(int i = 0 ; i < this->vertices ; i++){
            if(weight[j-1][i] == 1){
                cout<<i+1<<" " ;
            }
        }
        cout<<endl ;
        return ;
    }
    void print_graph(){
        for(int i = 1 ; i <= this->vertices ; i++){
            print_adj_vertices(i) ;
        }
        return ;
    }
    ~graph(){
        for(int i = 0 ; i < this->vertices ; i++){
            delete[] weight[i] ;
        }
        delete[] weight ;
    }
};
int main(){
    graph g(6);
    g.addedge(1,4) ;
    g.addedge(6,1) ;
    g.addedge(3,6) ;
    g.addedge(3,2) ;
    g.addedge(3,5) ;
    g.addedge(5,4) ;
    g.addedge(2,5) ;
    g.addedge(4,2) ;
    g.addedge(2,1) ;
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