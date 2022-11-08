#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
class graph{
    private:
    int vertices ;
    int edges ;
    bool *visited ;
    vector<int>* adj ;      // we can even have node in place of int which is a struct containing data and directions if needed
    public:
    graph(int n){
        vertices = n ;
        edges = 0 ;
        adj = new vector<int>[n] ;
        visited = new bool[this->vertices] ;
        for(int i = 0 ; i < this->vertices ; i++){
            visited[i] = false ;
        }
    }
    void addedge(int u, int v){     // assuming edge is directed from u to v   vertices 
        adj[u-1].push_back(v) ;       // assuming vertices start from 1,2,3...
        // adj[v-1].push_back(u) ;      // as directed from u to v not adding u to adjacency list of v 
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
                if(visit[adj[top-1][i] - 1] == true){
                    continue ;
                }
                visit[adj[top-1][i] - 1] = true ;
                distance[adj[top-1][i] - 1] = distance[top-1] + 1 ;
                q.push(adj[top-1][i]) ;
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
            dfs(adj[a-1][i]) ;
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
    cout<<endl ;
    g.print_graph() ;
    cout<<endl ;

    g.bfs(3) ;
    cout<<endl ; 

    g.remove_edge(1,2) ;
    cout<<endl ;
    g.print_graph() ;
    cout<<endl ;
    g.remove_edge(5,2) ;
    cout<<endl ;
    g.print_graph() ;
    cout<<endl ;

    g.bfs(3) ;
    cout<<endl ;

    cout<<"Vertices we can reach from vertex 1 using dfs is : " ;
    g.dfs(1) ;
    cout<<endl ;
    g.make_visited_false() ;
// as we defined visited in the private once changed to true there also it will change so we will make all false again for next vertex dfs


    cout<<"Vertices we can reach from vertex 3 using dfs is : " ;
    g.dfs(3) ;
    cout<<endl ;
    g.make_visited_false() ;

    cout<<"Vertices we can reach from vertex 6 using dfs is : " ;
    g.dfs(6) ;
    cout<<endl ;
    g.make_visited_false() ;

    return 0 ;
}