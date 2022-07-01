#include<iostream>
#include<vector>
using namespace std ;
/*
I guess for directed while adding an edge just add for one add for the source edge but not for the destination
If u want to go for more than pair then we have tuple
*/
class graph{
    private:
    int vertices ;
    int edges ;
    vector<pair<int, int>>* adj ; // we can even have node in place of int which is a struct containing data and directions if needed
    public:
    graph(int n){
        vertices = n ;
        edges = 0 ;
        adj = new vector<pair<int, int>>[n] ;           // first item in the pair is node it is connected to and second is the weight of the edge
    }
    int getedges(){
        return this->edges ;
    }
    int getvertices(){
        return this->vertices ;
    }
    void addedge(int u, int v, int weight){
        adj[u-1].push_back(make_pair(v, weight)) ;       // assuming vertices start from 1,2,3...
        adj[v-1].emplace_back(u, weight) ;           // we can even have directional edge with different weights 
        edges++ ;
    }
    void print_adj_vertex(int i){
        cout<<"Vertices that are adjacent to the "<<i<<" vertex and their weights are as follows :" ;
        for(auto j = adj[i-1].begin() ; j != adj[i-1].end() ; j++){
            cout<<"( "<<j->first<<" , "<<j->second<<" ) " ;
        }
        cout<<endl ;
        return ;
    }
    void print_graph(){
        for(auto i = 1 ; i <= this->vertices ; i++){
            print_adj_vertex(i) ;
        }
    }
    void remove_edge(int u, int v, int weight){
        for(auto i = adj[u-1].begin(); i != adj[u-1].end(); i++){
            if((i->first == v)){
                if(i->second == weight){
                    adj[u-1].erase(i) ;
                    break ;
                }
                else{
                    cout<<"There is an edge between "<<u<<" and "<<v<<" but the weight is not "<<weight<<endl ;
                    return ;
                }
            }
            if((i == adj[u-1].end() -1) && (i->first != v) && (i->second != weight)){
                cout<<"There is no edge between "<<u<<" and "<<v<<" in the graph"<<" with weight "<<weight<<endl ;
                return ;
            }
        }
        for(auto i = adj[v-1].begin(); i != adj[v-1].end(); i++){
            if((i->first == u)){
                if(i->second == weight){
                    adj[v-1].erase(i) ;
                    break ;
                }
                else{
                    cout<<"There is an edge between "<<u<<" and "<<v<<" but the weight is not "<<weight<<endl ;
                    return ;
                }
            }
            if((i == adj[v-1].end() -1) && (i->first != u) && (i->second != weight)){
                cout<<"There is no edge between "<<u<<" and "<<v<<" in the graph "<<"with weight "<<weight<<endl ;
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
    graph g(6) ;
    g.addedge(1,4,10) ;
    g.addedge(6,1,50) ;
    g.addedge(3,6,40) ;
    g.addedge(3,2,80) ;
    g.addedge(3,5,30) ;
    g.addedge(5,4,20) ;
    g.addedge(2,5,70) ;
    g.addedge(4,2,60) ;
    g.addedge(2,1,90) ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    // g.print_adj_vertex(2) ;
    g.print_graph() ;
    cout<<"---------------------------"<<endl ;
    g.remove_edge(1,2,90) ;
    // g.print_adj_vertex(2) ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    g.print_graph() ;
    cout<<"---------------------------"<<endl ;
    g.remove_edge(3,4,10) ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    g.print_graph() ;
    g.remove_edge(3,2,70) ;
    return 0 ;
}