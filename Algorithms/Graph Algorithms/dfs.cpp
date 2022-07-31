#include<iostream>
#include<vector>
using namespace std ;
class graph{
    private:
    int vertices ;
    int edges ;
    bool *visited ;            // This is for dfs
    vector<int>* adj ;      // we can even have node in place of int which is a struct containing data and directions if needed
    vector<int> time_in ;
    vector<int> time_out ;
    int dfs_timer  ;
    public:
    graph(int n){
        vertices = n ;
        edges = 0 ;
        adj = new vector<int>[this->vertices] ;
        visited = new bool[this->vertices] ;
        time_in.resize(this->vertices) ;
        time_out.resize(this->vertices) ;
        for(int i = 0 ; i < this->vertices ; i++){
            visited[i] = false ;
            time_in[i] = 0 ;
            time_out[i] = 0 ;
        }
        dfs_timer = 0 ;
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
    DFS begins at a starting node, and proceeds to all other nodes that are reachable from the starting node 
    using the edges of the graph. Depth-first search always follows a single path in the graph as long as it finds new nodes. 
    After this, it returns to previous nodes and begins to explore other parts of the graph. The algorithm keeps track of visited nodes, 
    so that it processes each node only once.
    */
    void dfs(int a){                 // traversal from the vertex taken as input
        if(visited[a-1] == true){
            return ;
        }
        time_in[a-1] = this->dfs_timer  ;
        this->dfs_timer++ ;
        visited[a-1] = true ;
        cout<<a<<" " ;
        for(int i = 0 ; i < adj[a-1].size() ; i++){
            dfs(adj[a-1][i]) ;
        }
        time_out[a-1] = dfs_timer ;
        dfs_timer++ ;
    }
// after every dfs we make all of them back to zero so that for next dfs we can use these 
    void make_visited_false(){
        for(int i = 0 ; i < this->vertices ; i++){
            visited[i] = false ;
        }
    }
    void make_timers_zero(){
        dfs_timer = 0 ;
        for(int i = 0 ; i < this->vertices ; i++){
            time_in[i] = 0 ; 
            time_out[i] = 0 ;
        }
    }
/* 
If we start dfs from vertex a then we will get timers we print that so taking a as argument to reuse the dfs_timer for another
vertex we make_timer_zero when ever we call show timer 
*/
    void show_timer(int a){
        make_timers_zero() ;
        cout<<"Vertices we can reach from vertex "<<a<<" using dfs is : " ;
        dfs(a) ;
        cout<<endl ;
        for(int i = 0 ; i < this->vertices ; i++){
            cout<<"In time when dfs starts for "<<i+1<<" is : "<<time_in[i]<<" and the out time is : "<<time_out[i]<<endl ;
        }
        make_visited_false() ;
        // this for reusing again next as we used dfs here in this function 
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
    /*cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    g.print_adj_vertex(2) ;
    g.print_graph() ;
    cout<<"---------------------------"<<endl ;
    g.remove_edge(1,2) ;
    g.print_adj_vertex(2) ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    g.print_graph() ;
    cout<<"---------------------------"<<endl ;
    g.remove_edge(3,4) ;
    cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
    g.print_graph() ;
    cout<<endl ;

    cout<<"Vertices we can reach from vertex 2 using dfs is : " ;
    g.dfs(2) ;
    cout<<endl ;

    g.make_visited_false() ;         
    as we defined visited in the private once changed to true there also it will change so we will make all false again for next vertex dfs

    cout<<"Vertices we can reach from vertex 1 using dfs is : " ;
    g.dfs(1) ;
    cout<<endl ;

    g.make_visited_false() ; 

    cout<<"Vertices we can reach from vertex 3 using dfs is : " ;
    g.dfs(3) ;
    g.make_visited_false() ;
    cout<<endl ;
    */

    g.show_timer(3)  ;  // shows timers if we do dfs starting from vertex 3

    g.show_timer(2) ;

    g.show_timer(1) ;
                                    
    return 0 ;
}