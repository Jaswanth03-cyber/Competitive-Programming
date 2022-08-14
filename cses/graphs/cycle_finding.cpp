#include<bits/stdc++.h>
using namespace std ;

const long long MAX = 1e12 ;
struct edge{
    int from ; 
    int to ;
    long long weight ;
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
    void addedge(int a, int b, long long value){
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
        vector<long long> distances(this->vertices + 1) ;     // not considering 0th index 
        vector<int> parent(this->vertices + 1) ;
        for(int i = 1 ; i <=this->vertices ; i++){
            distances[i] = MAX ;
            visited[i] = false ;
        }
        distances[a] = 0 ;
        parent[a] = -1 ;
        
        for(int i = 1 ; i < this->vertices ; i++){
            for(unsigned int j = 0 ; j < edgelist.size() ; j++){
                if((distances[edgelist[j].to]) > (distances[edgelist[j].from] + edgelist[j].weight)){
                    distances[edgelist[j].to] = distances[edgelist[j].from] + edgelist[j].weight ;
                    parent[edgelist[j].to] = edgelist[j].from ;
                    visited[edgelist[j].to] = true ;
                }
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
            cout<<"NO"<<endl ;
        }
        else{
            cout<<"YES"<<endl ;
            int y = x ; 
            for(int i = 0 ; i < this->vertices ; i++){
                y = parent[y] ;
            }
            vector<int> path ;
            for (int cur=y; ; cur=parent[cur]){
                path.push_back (cur);
                if (cur == y && path.size() > 1){
                    break;
                }
            }
            reverse(path.begin(), path.end()) ;
            for(unsigned int i = 0 ; i < path.size() ; i++){
                cout<<path[i]<<" " ;
            }
            cout<<endl ;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ;
    int m ;
    cin>>n>>m ;

    graph g(n) ;

    for(int i = 0 ; i < m ; i++){
        int a ; 
        int b ;
        long long weight ;
        cin>>a>>b>>weight ;
        g.addedge(a, b, weight) ;
    }
    g.bellmanford(1) ;
    return 0 ; 
}