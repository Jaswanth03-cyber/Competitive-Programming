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
    /*
    This function prints the distance from a vertex given as input to the function to all the other nodes
    remember that this distance will be the shortest distance from that node, we can even change the function 
    in such a way that we can store the shortest distances, if we want.
    */
    void bfs(int a){
        queue<int> q ;
        bool visited[this->vertices] ;
        int distance[this->vertices] ;  // distances from the vertex given as input 
        for(int i = 0 ; i < this->vertices ; i++){
            visited[i] = false ;
            distance[i] = 0 ;
        }
        vector<int> parent(this->vertices) ;           // this is to know for that vertex from which vertex we reached there 
        distance[a-1] = 0 ;     // distance of vertex a from vertex a is 0
        visited[a-1] = true ;   // self vertex have been visited 
        parent[a-1] = -1 ;        // this is the source vertex from which we are starting this does not have any parent so -1 
        q.push(a) ;
        while(!q.empty()){
            int top = q.front() ;
            q.pop() ;
            for(int i = 0 ; i < adj[top-1].size() ; i++){
                if(visited[adj[top-1][i] - 1] == true){
                    continue ;
                }
                visited[adj[top-1][i] - 1] = true ;
                distance[adj[top-1][i] - 1] = distance[top-1] + 1 ;
                parent[adj[top-1][i] - 1] = top - 1 ;                        // noting that adj[top-1][i]-1 came from top-1 as it is adjacent to top-1
                q.push(adj[top-1][i]) ;
            }
        }
        for(int i = 0 ; i < this->vertices ; i++){
            int k = i + 1 ;
            cout<<"The shortest distance from the vertex "<<a<<" to the vertex "<<k<<" is : "<<distance[i]<<endl ;
        }
        // to know the path we can do this 
        for(int i = 0 ; i < this->vertices ; i++){
            if(i + 1 == a){
                cout<<i+1<<" is the source vertex "<<endl ;
            }
            if(!visited[i]){
                cout<<"No Path"<<endl ;
            }
            else{
                vector<int> path ;
                for(int j = i ; j != parent[a-1] ; j = parent[j]){      // loop until we reach the source 
                    path.push_back(j+1);
                }
                reverse(path.begin(), path.end());              // tracing the path 
                cout<<"Path from vertex "<<a<<" to the vertex "<<i+1<<" is as shown : " ;
                for(int k = 0 ; k < path.size() ; k++){
                    cout<<path[k]<<" " ;
                }
                cout<<endl ;
            }
        }
    }
    ~graph(){
        delete[] adj ;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
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
    // cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    // cout<<endl ;
    // g.print_adj_vertex(2) ;
    g.print_graph() ;
    cout<<endl ;

    g.bfs(1) ;
    cout<<endl ;
    // g.remove_edge(1,2) ;

    // g.print_adj_vertex(2) ;
    // cout<<endl ;

    // cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    // cout<<endl ;
    // g.print_graph() ;
    // cout<<endl ;
    g.bfs(3) ;
    cout<<endl ;

    // g.remove_edge(3,4) ;
    // cout<<endl ;
    // cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    // cout<<endl ;
    g.bfs(5) ;
    cout<<endl ;
    return 0 ;
}