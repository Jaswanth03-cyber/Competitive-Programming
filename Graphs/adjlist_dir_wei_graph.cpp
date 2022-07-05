#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
/*
I guess for directed while adding an edge just add for one add for the source edge but not for the destination
If u want to go for more than pair then we have tuple
*/
class graph{
    private:
    int vertices ;
    int edges ;
    bool *visited ;
    vector<pair<int, int>>* adj ; // we can even have node in place of int which is a struct containing data and directions if needed
    public:
    graph(int n){
        vertices = n ;
        edges = 0 ;
        visited = new bool[this->vertices] ;
        adj = new vector<pair<int, int>>[n] ;           // first item in the pair is node it is connected to and second is the weight of the edge
        for(int i = 0 ; i < this->vertices ; i++){
            visited[i] = false ;
        }
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
    /*
    This function prints the distance from a vertex given as input to the function to all the other nodes
    remember that this distance will be the shortest distance from that node, we can even change the function 
    in such a way that we can store the shortest distances, if we want.

    We should not use bfs over here actually but what if we use 
    */
    void bfs(int a){
        queue<int> q ;
        bool visit[this->vertices] ;
        int distance[this->vertices] ;  // distances from the vertex given as input 
        for(int i = 0 ; i < this->vertices ; i++){
            visit[i] = false ;
            distance[i] = 0 ;
        }
        distance[a-1] = 0 ;     // distance of vertex a from vertex a is 0
        visit[a-1] = true ;   // self vertex have been visited 
        q.push(a) ;
        while(!q.empty()){
            int top = q.front() ;
            q.pop() ;
            for(int i = 0 ; i < adj[top-1].size() ; i++){
                if(visit[adj[top-1][i].first - 1] == true){
                    continue ;
                }
                visit[adj[top-1][i].first - 1] = true ;
                distance[adj[top-1][i].first - 1] = distance[top-1] + adj[top-1][i].second ;
                q.push(adj[top-1][i].first) ;
            }
        }
        for(int i = 0 ; i < this->vertices ; i++){
            int k = i + 1 ;
            cout<<"The shortest distance from the vertex "<<a<<" to the vertex "<<k<<" is : "<<distance[i]<<endl ;
        }
    }
    /*
    DFS begins at a starting node, and proceeds to all other nodes that are reachable from the starting node 
    using the edges of the graph. Depth-first search always follows a single path in the graph as long as it finds new nodes. 
    After this, it returns to previous nodes and begins to explore other parts of the graph. The algorithm keeps track of visited nodes, 
    so that it processes each node only once.
    */
    void dfs(int a){                 // traversal from the vertex taken as input
        if(visited[a-1] == true){
            return ;
        }
        visited[a-1] = true ;
        cout<<a<<" " ;
        for(int i = 0 ; i < adj[a-1].size() ; i++){
            dfs(adj[a-1][i].first) ;
        }
    }
    void make_visited_false(){
        for(int i = 0 ; i < this->vertices ; i++){
            visited[i] = false ;
        }
    }
    ~graph(){
        delete[] adj ;
        delete[] visited ;
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
    cout<<endl ;
    // g.print_adj_vertex(2) ;
    g.print_graph() ;
    cout<<endl ;
    g.remove_edge(1,2,90) ;
    cout<<endl ;
    // g.print_adj_vertex(2) ;
    g.remove_edge(3,4,10) ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    cout<<endl ;
    g.print_graph() ;
    cout<<endl ;
    g.remove_edge(3,2,70) ;
    cout<<endl ;

    cout<<"Vertices we can reach from vertex 3 using dfs is : " ;
    g.dfs(3) ;
    cout<<endl ;
    cout<<endl ;

    cout<<"We never use bfs to find the shortest path in directed graph with weights but if we use this is the result :"<<endl ;
    g.bfs(1) ;
    cout<<endl ;

    return 0 ;
}