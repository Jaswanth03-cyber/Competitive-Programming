#include<bits/stdc++.h>
using namespace std ;
typedef pair<int, int> pi ;

class graph{
    private:
    int vertices ;
    int edges ;
    vector<pair<int, int>> *adjlist ;
    vector<vector<bool>> pushed_edge_queue ;
    public:
    graph(int n){
        this->vertices = n ; 
        this->edges = 0 ;
        adjlist = new vector<pair<int, int>>[this->vertices] ;
        pushed_edge_queue.resize(this->vertices) ;
        for(int i = 0 ; i < this->vertices ; i++){
            pushed_edge_queue[i].resize(this->vertices) ;
            fill(pushed_edge_queue[i].begin(), pushed_edge_queue[i].end(), false) ;
        }
    }

    void addedge(int a, int b, int value){
        adjlist[a-1].push_back(make_pair(b, value)) ;
        adjlist[b-1].push_back(make_pair(a,value)) ;
        this->edges++ ;
    }

    void prim(){
        srand(time(0)) ;
        vector<bool> pushed_vertex_tree(this->vertices, false) ;
        vector<int> path ;
        int tree_length = 0  ;
        int node =  rand()%this->vertices + 1 ; // starting at a random node in the graph currently for checking lets take that node to be 1 but length of the tree does not change 
        priority_queue<pi> pq ;
        pq.push(make_pair(0, node-1)) ;
        int index = 0 ;
        while(index != this->vertices){
            while(pushed_vertex_tree[pq.top().second] != false){
                pq.pop() ;
            }
            tree_length = tree_length + pq.top().first  ;
            int one = pq.top().second ;
            path.push_back(one + 1) ;
            pushed_vertex_tree[one] = true ;
            index++ ;
            pq.pop() ;
            for(int i = 0 ; i < adjlist[one].size() ; i++){
                if(!pushed_edge_queue[one][adjlist[one][i].first -1]){
                    pq.push(make_pair(adjlist[one][i].second, adjlist[one][i].first -1)) ;
                    pushed_edge_queue[one][adjlist[one][i].first - 1] = true ;
                    pushed_edge_queue[adjlist[one][i].first - 1][one] = true ;
                }
            }
        }
        cout<<"The order in which the nodes are added to the tree are as follows : " ;
        for(int i = 0 ; i < path.size() ; i++){
            cout<<path[i]<<" " ;
        }
        cout<<" and the length of the tree is : "<<tree_length<<endl ;
    }

    ~graph(){
        delete[] adjlist ;
    }
};
/*
Here pushed_vertex_tree is whether the vertex is pushed or not and pushed_edge_queue is whether the edge is pushed into the queue or not 
basically what we are doing is starting at a random vertex and then adding the maximum edge without forming a cycle 
so first adding all the edges adjacent to the starting random vertex to the priority queue and the random node is added to our tree
so we make it pushed_vertex_tree true as it is pushed into the tree we are pushing only those edges which are not pushed into the 
queue so we are having an if condition for that I have maintained a 2D vector whether an edge is pushed if pushed we make 
pushed_edge_queue true for two values from both of the nodes side so like inside the while loop we had another while loop that is 
because we will have some maximum edges but already both the nodes are included into the tree so we maintained a vector for vertices
whether pushed into the tree or not so we will pop out the top nodes in the heap until we get a vertex which is not in the tree 
and edge connecting is maximum as we need maximum spanning tree 
*/

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    graph g(6) ;
    g.addedge(1,2,3) ;
    g.addedge(1,5,5) ;
    g.addedge(2,5,6) ;
    g.addedge(5,6,2) ;
    g.addedge(6,4,7) ;
    g.addedge(4,3,9) ;
    g.addedge(3,2,5) ;
    g.addedge(3,6,3) ;

    g.prim() ;


    graph G(5) ;
    G.addedge(1,2,1) ;
    G.addedge(2,4,4) ;
    G.addedge(4,5,2) ;
    G.addedge(5,3,6) ;
    G.addedge(5,2,3) ;
    G.addedge(3,2,5) ;
    G.addedge(1,3,7) ;

    G.prim() ;

    graph Gg(9) ;
    Gg.addedge(1,2,4) ;
    Gg.addedge(2,3,8) ;
    Gg.addedge(3,4,7) ;
    Gg.addedge(4,5,9) ;
    Gg.addedge(5,6,10) ;
    Gg.addedge(6,7,2) ;
    Gg.addedge(7,8,1) ;
    Gg.addedge(8,1,8) ;
    Gg.addedge(8,9,7) ;
    Gg.addedge(8,2,11) ;
    Gg.addedge(9,7,6) ;
    Gg.addedge(3,9,2) ;
    Gg.addedge(6,4,14) ;
    Gg.addedge(3,6,4) ;

    Gg.prim() ;
    return 0 ;
}