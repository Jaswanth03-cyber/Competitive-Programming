#include<bits/stdc++.h>
using namespace std ;

struct edge{
    int from ; 
    int to ;
    int weight ;
    /*
    edge(int a, int b, int value){
        from = a ; 
        to = b ; 
        weight = value ;
    }
    */
};

class graph{
    private:
    int vertices ; 
    int edges ;
    vector<edge> edgelist ;
    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ;
    }
/*
If we use undirected graph than we have to use another method of add edge written down as we have to add edge from both sides 
but for directed no need to add from both sides so second method written can be used for both directed and undirected and also
for that method we also have to define the constructor written in struct as while pushing we are pushing an edge with the values 
initialised so we need the constructor and also there are many ways to add an edge to the vector 
*/
    void addedge(int a, int b, int value){
        edgelist.emplace_back() ;
        edgelist[this->edges].from = a ; 
        edgelist[this->edges].to = b ;
        edgelist[this->edges].weight = value ;
        this->edges++ ;
    }

/*
    void addedge(int a, int b, int value){
        edgelist.push_back(edge(a, b, value)) ;
        //edgelist.push_back(edge(b, a, value)) ; // for a undirected we can think as two directed 
        this->edges++ ;
    }
*/
    void bellmanford(int a){

        vector<bool> visited(this->vertices + 1) ;
        vector<int> distances(this->vertices + 1) ;     // not considering 0th index 
        vector<int> parent(this->vertices + 1) ;
        for(int i = 1 ; i <=this->vertices ; i++){
            distances[i] = 1e5 ;
            visited[i] = false ;
        }
        distances[a] = 0 ;
        parent[a] = -1 ;
        
        for(int i = 1 ; i < this->vertices ; i++){
            for(int j = 0 ; j < edgelist.size() ; j++){
                if((distances[edgelist[j].to]) > (distances[edgelist[j].from] + edgelist[j].weight)){
                    distances[edgelist[j].to] = distances[edgelist[j].from] + edgelist[j].weight ;
                    parent[edgelist[j].to] = edgelist[j].from ;
                    visited[edgelist[j].to] = true ;
                }
            }
        }

        for(int i = 1 ; i <=this->vertices ; i++){
            cout<<"Shortest distance to the vertex "<<i<<" from the vertex "<<a<<" is : " ;
            cout<<distances[i]<<endl ;
        }
        
        for(int i = 1 ; i <= this->vertices ; i++){
            if( distances[i] == 1e5){
                cout<<"There is not path to the vertex "<<i<<" from the vertex "<<a<<endl ;
            }
            else{
                vector<int> path ;
                for(int j = i ; j != -1 ; j = parent[j]){
                    path.push_back(j) ;
                }
                reverse(path.begin(), path.end()) ;
                cout<<"Path to the vertex "<<i<<" from the vertex "<<a<<" is : " ;
                for(int k = 0 ; k < path.size() ; k++){
                    cout<<path[k]<<" " ;
                }
                cout<<endl ;
            }
        }
        int x = -1 ;
        for(int i = 0 ; i < 1 ; i++){
            for(int j = 0 ; j < this->edges ; j++){
                if((distances[edgelist[j].to]) > (distances[edgelist[j].from] + edgelist[j].weight)){
                    distances[edgelist[j].to] =  distances[edgelist[j].from] + edgelist[j].weight ;
                    parent[edgelist[j].to] = edgelist[j].from ;
                    x = edgelist[j].to ;       
                }
            }
        }
        if(x == -1){
            cout<<"There is no negative cycle in the given graph"<<endl ;
        }
        else{
            int y = x ; 
            for(int i = 0 ; i < this->vertices ; i++){
                y = parent[y] ;
            }
            vector<int> path ;
            int cur = y ; 
            for (int cur=y; ; cur=parent[cur]){
                path.push_back (cur);
                if (cur == y && path.size() > 1){
                    break;
                }
            }
            reverse(path.begin(), path.end()) ;
            cout<<"There is negative cycle in the graph and that is as shown :" ;
            for(int i = 0 ; i < path.size() ; i++){
                cout<<path[i]<<" " ;
            }
            cout<<endl ;
        }
    }
};
/*
this is to identify if any negative cycle running one more loop we have stop after n-1 loops, if there is a 
change in the distance for a particular edge that means there is a negative cycle as atmost we can have only n-1 edges
in the path but we are running another loop and checking if so there is a change that means that there is a negative cycle 
*/

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    graph g(5) ;
    g.addedge(1, 2, -1) ;
    g.addedge(1, 3, 4) ;
    g.addedge(2, 3, 3) ;
    g.addedge(2, 4, 2) ;
    g.addedge(4, 2, 1) ;
    g.addedge(4, 3, 5) ;
    g.addedge(2, 5, 2) ;
    g.addedge(5, 4, -3) ;

    g.bellmanford(1) ;



    /*
    graph G(4) ;
    G.addedge(4,1,-1) ;
    G.addedge(1,2,1) ;
    G.addedge(2,3,-1) ;
    G.addedge(3,4,-1) ;
    G.bellmanford(1) ;
    */
    return 0 ; 
}