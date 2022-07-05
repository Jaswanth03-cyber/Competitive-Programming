# Graphs 

We can represent the graphs in three different ways which are as follows 

## Adjacency List

In the adjacency list representation, each node x in the graph is assigned an adjacency list that consists of nodes to which there is an edge from x. Adjacency lists are the most popular way to represent graphs, and most algorithms can be efficiently implemented using them.

The adjacency list can be in the form of a linked list, a variable sized array or a vector of nodes to which the node being considered is connected to. See the following code here we wrote for undirected graph 

### Code

```c++
#include<iostream>
#include<vector>
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
```

### Output 
```
No of edges in the graph are : 9
vertices that are adjacent to the vertex 1 are : 4 6 2 
vertices that are adjacent to the vertex 2 are : 3 5 4 1 
vertices that are adjacent to the vertex 3 are : 6 2 5 
vertices that are adjacent to the vertex 4 are : 1 5 2 
vertices that are adjacent to the vertex 5 are : 3 4 2 
vertices that are adjacent to the vertex 6 are : 1 3 
---------------------------
No of edges in the graph are : 8
vertices that are adjacent to the vertex 1 are : 4 6 
vertices that are adjacent to the vertex 2 are : 3 5 4 
vertices that are adjacent to the vertex 3 are : 6 2 5 
vertices that are adjacent to the vertex 4 are : 1 5 2 
vertices that are adjacent to the vertex 5 are : 3 4 2 
vertices that are adjacent to the vertex 6 are : 1 3 
---------------------------
There is no edge between 3 and 4 in the graph
No of edges in the graph are : 8
vertices that are adjacent to the vertex 1 are : 4 6 
vertices that are adjacent to the vertex 2 are : 3 5 4 
vertices that are adjacent to the vertex 3 are : 6 2 5 
vertices that are adjacent to the vertex 4 are : 1 5 2 
vertices that are adjacent to the vertex 5 are : 3 4 2 
vertices that are adjacent to the vertex 6 are : 1 3 

```

We can even have the weights for this 

```c++
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

```

```
No of edges in the graph are : 9
Vertices that are adjacent to the 1 vertex and their weights are as follows :( 4 , 10 ) ( 6 , 50 ) ( 2 , 90 ) 
Vertices that are adjacent to the 2 vertex and their weights are as follows :( 3 , 80 ) ( 5 , 70 ) ( 4 , 60 ) ( 1 , 90 ) 
Vertices that are adjacent to the 3 vertex and their weights are as follows :( 6 , 40 ) ( 2 , 80 ) ( 5 , 30 ) 
Vertices that are adjacent to the 4 vertex and their weights are as follows :( 1 , 10 ) ( 5 , 20 ) ( 2 , 60 ) 
Vertices that are adjacent to the 5 vertex and their weights are as follows :( 3 , 30 ) ( 4 , 20 ) ( 2 , 70 ) 
Vertices that are adjacent to the 6 vertex and their weights are as follows :( 1 , 50 ) ( 3 , 40 ) 
---------------------------
No of edges in the graph are : 8
Vertices that are adjacent to the 1 vertex and their weights are as follows :( 4 , 10 ) ( 6 , 50 ) 
Vertices that are adjacent to the 2 vertex and their weights are as follows :( 3 , 80 ) ( 5 , 70 ) ( 4 , 60 ) 
Vertices that are adjacent to the 3 vertex and their weights are as follows :( 6 , 40 ) ( 2 , 80 ) ( 5 , 30 ) 
Vertices that are adjacent to the 4 vertex and their weights are as follows :( 1 , 10 ) ( 5 , 20 ) ( 2 , 60 ) 
Vertices that are adjacent to the 5 vertex and their weights are as follows :( 3 , 30 ) ( 4 , 20 ) ( 2 , 70 ) 
Vertices that are adjacent to the 6 vertex and their weights are as follows :( 1 , 50 ) ( 3 , 40 ) 
---------------------------
There is no edge between 3 and 4 in the graph with weight 10
No of edges in the graph are : 8
Vertices that are adjacent to the 1 vertex and their weights are as follows :( 4 , 10 ) ( 6 , 50 ) 
Vertices that are adjacent to the 2 vertex and their weights are as follows :( 3 , 80 ) ( 5 , 70 ) ( 4 , 60 ) 
Vertices that are adjacent to the 3 vertex and their weights are as follows :( 6 , 40 ) ( 2 , 80 ) ( 5 , 30 ) 
Vertices that are adjacent to the 4 vertex and their weights are as follows :( 1 , 10 ) ( 5 , 20 ) ( 2 , 60 ) 
Vertices that are adjacent to the 5 vertex and their weights are as follows :( 3 , 30 ) ( 4 , 20 ) ( 2 , 70 ) 
Vertices that are adjacent to the 6 vertex and their weights are as follows :( 1 , 50 ) ( 3 , 40 ) 
There is an edge between 3 and 2 but the weight is not 70

```

## Adjacency Matrix 

An adjacency matrix is a 2-D array that indicates which edges the graph contains. In an unweighted graph, adj[a][b] = 1 implies that there is an edge between a and b, while adj[a][b] = 0 implies no edge between them. In a weighted graph, adj[a][b] = L can represent an edge of length L between a and b, Here we wrote a code for undirected graph as shown 

### Code

```c++
#include<iostream>
#include<vector>
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

```

### Output 
```
No of edges in the graph are : 9
Vertices that are adjacent to vertex 1 are as follows : 2 4 6 
Vertices that are adjacent to vertex 2 are as follows : 1 3 4 5 
Vertices that are adjacent to vertex 3 are as follows : 2 5 6 
Vertices that are adjacent to vertex 4 are as follows : 1 2 5 
Vertices that are adjacent to vertex 5 are as follows : 2 3 4 
Vertices that are adjacent to vertex 6 are as follows : 1 3 
---------------------------
No of edges in the graph are : 8
Vertices that are adjacent to vertex 1 are as follows : 4 6 
Vertices that are adjacent to vertex 2 are as follows : 3 4 5 
Vertices that are adjacent to vertex 3 are as follows : 2 5 6 
Vertices that are adjacent to vertex 4 are as follows : 1 2 5 
Vertices that are adjacent to vertex 5 are as follows : 2 3 4 
Vertices that are adjacent to vertex 6 are as follows : 1 3 
---------------------------
There is no edge to remove 
No of edges in the graph are : 8
Vertices that are adjacent to vertex 1 are as follows : 4 6 
Vertices that are adjacent to vertex 2 are as follows : 3 4 5 
Vertices that are adjacent to vertex 3 are as follows : 2 5 6 
Vertices that are adjacent to vertex 4 are as follows : 1 2 5 
Vertices that are adjacent to vertex 5 are as follows : 2 3 4 
Vertices that are adjacent to vertex 6 are as follows : 1 3 

```

## Edge List 

An edge list contains all the edges of a graph. This is a convenient way to represent a graph if the algorithm processes all edges of a graph and it is not required to find edges that start at a given node. Edges can be represented explicitly as structs, or as pairs storing the nodes they are connected to, as structs 


There are basically two types of graph traversals namely BFS and DFS 

## Breadth First Search (BFS)

Breadth-first search (BFS) visits the nodes in increasing order of their distance from the starting node. Thus, we can calculate the distance from the starting node to all other nodes using breadth-first search. Here distance implies the number of edges to be traversed to go from one node to the next. Breadth-first search goes through the nodes one level after another. First the search explores the nodes whose distance from the starting node is 1, then the nodes whose distance is 2, and so on. This process continues until all nodes have been visited.

Breadth First Search can be implemented using a queue. When the search reaches a node, all the nodes which are connected to this node by an edge and which haven't been visited are added into the queue. The search then proceeds to the next element of the queue, till all the nodes have been visited. In the following implementation we will be using the template class queue provided in the C++ STL, however you can use the queue we have seen in the earlier lecture as well. The following data structures will be required and the time complexity of depth-first search is O(n+ m) where n is the number of vertices and m is the number of edges, because the algorithm processes each vertex  and edge once :

### Code 
```c++
#include<iostream>
#include<vector>
#include<queue>
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
        distance[a-1] = 0 ;     // distance of vertex a from vertex a is 0
        visited[a-1] = true ;   // self vertex have been visited 
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
                q.push(adj[top-1][i]) ;
            }
        }
        for(int i = 0 ; i < this->vertices ; i++){
            int k = i + 1 ;
            cout<<"The shortest distance from the vertex "<<a<<" to the vertex "<<k<<" is : "<<distance[i]<<endl ;
        }
    }
    ~graph(){
        delete[] adj ;
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

```

### Output 

``` 
vertices that are adjacent to the vertex 1 are : 4 6 2 
vertices that are adjacent to the vertex 2 are : 3 5 4 1 
vertices that are adjacent to the vertex 3 are : 6 2 5 
vertices that are adjacent to the vertex 4 are : 1 5 2 
vertices that are adjacent to the vertex 5 are : 3 4 2 
vertices that are adjacent to the vertex 6 are : 1 3 

The shortest distance from the vertex 1 to the vertex 1 is : 0
The shortest distance from the vertex 1 to the vertex 2 is : 1
The shortest distance from the vertex 1 to the vertex 3 is : 2
The shortest distance from the vertex 1 to the vertex 4 is : 1
The shortest distance from the vertex 1 to the vertex 5 is : 2
The shortest distance from the vertex 1 to the vertex 6 is : 1

The shortest distance from the vertex 3 to the vertex 1 is : 2
The shortest distance from the vertex 3 to the vertex 2 is : 1
The shortest distance from the vertex 3 to the vertex 3 is : 0
The shortest distance from the vertex 3 to the vertex 4 is : 2
The shortest distance from the vertex 3 to the vertex 5 is : 1
The shortest distance from the vertex 3 to the vertex 6 is : 1

The shortest distance from the vertex 5 to the vertex 1 is : 2
The shortest distance from the vertex 5 to the vertex 2 is : 1
The shortest distance from the vertex 5 to the vertex 3 is : 1
The shortest distance from the vertex 5 to the vertex 4 is : 1
The shortest distance from the vertex 5 to the vertex 5 is : 0
The shortest distance from the vertex 5 to the vertex 6 is : 2

```

## Depth First Search (DFS)

DFS begins at a starting node, and proceeds to all other nodes that are reachable from the starting node using the edges of the graph. Depth-first search always follows a single path in the graph as long as it finds new nodes. After this, it returns to previous nodes and begins to explore other parts of the graph. The algorithm keeps track of visited nodes, so that it processes each node only once.

DFS algorithm can be implemented using stack or by using a recursive function and the time complexity of depth-first search is O(n+ m) where n is the number of vertices and m is the number of edges, because the algorithm processes each node and edge once.

### Code 

```c++

#include<iostream>
#include<vector>
using namespace std ;
class graph{
    private:
    int vertices ;
    int edges ;
    bool *visited ;            // This is for dfs
    vector<int>* adj ;      // we can even have node in place of int which is a struct containing data and directions if needed
    public:
    graph(int n){
        vertices = n ;
        edges = 0 ;
        adj = new vector<int>[this->vertices] ;
        visited = new bool[this->vertices] ;
        for(int i = 0 ; i < this->vertices ; i++){
            visited[i] = false ;
        }
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
    /*cout<<"No of edges in the graph are : "<<g.getedges()<<endl ;
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
    cout<<endl ;
    */
    cout<<"Vertices we can reach from vertex 2 using dfs is : " ;
    g.dfs(2) ;
    cout<<endl ;

    g.make_visited_false() ;          
    // as we defined visited in the private once changed to true there also it will change so we will make all false again for next vertex dfs

    cout<<"Vertices we can reach from vertex 1 using dfs is : " ;
    g.dfs(1) ;
    cout<<endl ;

    g.make_visited_false() ;

    cout<<"Vertices we can reach from vertex 3 using dfs is : " ;
    g.dfs(3) ;
    cout<<endl ;
                                    
    return 0 ;
}

```

### Output 

```
Vertices we can reach from vertex 2 using dfs is : 2 3 6 1 4 5 
Vertices we can reach from vertex 1 using dfs is : 1 4 5 3 6 2 
Vertices we can reach from vertex 3 using dfs is : 3 6 1 4 5 2 

```


## Directed Graph Class using Adjacency List 


### Code 
```c++

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

```

### Output 

```
No of edges in the graph are : 9

vertices that are adjacent to the vertex 1 are : 4 
vertices that are adjacent to the vertex 2 are : 5 1 
vertices that are adjacent to the vertex 3 are : 6 2 5 
vertices that are adjacent to the vertex 4 are : 2 
vertices that are adjacent to the vertex 5 are : 4 
vertices that are adjacent to the vertex 6 are : 1 

The shortest distance from the vertex 3 to the vertex 1 is : 2
The shortest distance from the vertex 3 to the vertex 2 is : 1
The shortest distance from the vertex 3 to the vertex 3 is : 0
The shortest distance from the vertex 3 to the vertex 4 is : 2
The shortest distance from the vertex 3 to the vertex 5 is : 1
The shortest distance from the vertex 3 to the vertex 6 is : 1

There is no edge between 1 and 2 in the graph

vertices that are adjacent to the vertex 1 are : 4 
vertices that are adjacent to the vertex 2 are : 5 1 
vertices that are adjacent to the vertex 3 are : 6 2 5 
vertices that are adjacent to the vertex 4 are : 2 
vertices that are adjacent to the vertex 5 are : 4 
vertices that are adjacent to the vertex 6 are : 1 

There is no edge between 5 and 2 in the graph

vertices that are adjacent to the vertex 1 are : 4 
vertices that are adjacent to the vertex 2 are : 5 1 
vertices that are adjacent to the vertex 3 are : 6 2 5 
vertices that are adjacent to the vertex 4 are : 2 
vertices that are adjacent to the vertex 5 are : 4 
vertices that are adjacent to the vertex 6 are : 1 

The shortest distance from the vertex 3 to the vertex 1 is : 2
The shortest distance from the vertex 3 to the vertex 2 is : 1
The shortest distance from the vertex 3 to the vertex 3 is : 0
The shortest distance from the vertex 3 to the vertex 4 is : 2
The shortest distance from the vertex 3 to the vertex 5 is : 1
The shortest distance from the vertex 3 to the vertex 6 is : 1

Vertices we can reach from vertex 1 using dfs is : 1 4 2 5 
Vertices we can reach from vertex 3 using dfs is : 3 6 1 4 2 5 
Vertices we can reach from vertex 6 using dfs is : 6 1 4 2 5 

```


### Directed Weighted Graph 

We have implemented the graph using adjacency list and also edges have some weight, below is the code 


```c++

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

```




















```

No of edges in the graph are : 9

Vertices that are adjacent to the 1 vertex and their weights are as follows :( 4 , 10 ) ( 6 , 50 ) ( 2 , 90 ) 
Vertices that are adjacent to the 2 vertex and their weights are as follows :( 3 , 80 ) ( 5 , 70 ) ( 4 , 60 ) ( 1 , 90 ) 
Vertices that are adjacent to the 3 vertex and their weights are as follows :( 6 , 40 ) ( 2 , 80 ) ( 5 , 30 ) 
Vertices that are adjacent to the 4 vertex and their weights are as follows :( 1 , 10 ) ( 5 , 20 ) ( 2 , 60 ) 
Vertices that are adjacent to the 5 vertex and their weights are as follows :( 3 , 30 ) ( 4 , 20 ) ( 2 , 70 ) 
Vertices that are adjacent to the 6 vertex and their weights are as follows :( 1 , 50 ) ( 3 , 40 ) 


There is no edge between 3 and 4 in the graph with weight 10
No of edges in the graph are : 8

Vertices that are adjacent to the 1 vertex and their weights are as follows :( 4 , 10 ) ( 6 , 50 ) 
Vertices that are adjacent to the 2 vertex and their weights are as follows :( 3 , 80 ) ( 5 , 70 ) ( 4 , 60 ) 
Vertices that are adjacent to the 3 vertex and their weights are as follows :( 6 , 40 ) ( 2 , 80 ) ( 5 , 30 ) 
Vertices that are adjacent to the 4 vertex and their weights are as follows :( 1 , 10 ) ( 5 , 20 ) ( 2 , 60 ) 
Vertices that are adjacent to the 5 vertex and their weights are as follows :( 3 , 30 ) ( 4 , 20 ) ( 2 , 70 ) 
Vertices that are adjacent to the 6 vertex and their weights are as follows :( 1 , 50 ) ( 3 , 40 ) 

There is an edge between 3 and 2 but the weight is not 70

Vertices we can reach from vertex 3 using dfs is : 3 6 1 4 5 2 

We never use bfs to find the shortest path in directed graph with weights but if we use this is the result :
The shortest distance from the vertex 1 to the vertex 1 is : 0
The shortest distance from the vertex 1 to the vertex 2 is : 70
The shortest distance from the vertex 1 to the vertex 3 is : 90
The shortest distance from the vertex 1 to the vertex 4 is : 10
The shortest distance from the vertex 1 to the vertex 5 is : 30
The shortest distance from the vertex 1 to the vertex 6 is : 50
```




