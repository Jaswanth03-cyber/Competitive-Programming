#include<bits/stdc++.h>
using namespace std ;

#define MAX_VALUE 1e5  
typedef pair<int, int> pi ; // for priority queue with minimum heap 
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
        adj[v-1].push_back(make_pair(u, weight));           // we can even have directional edge with different weights 
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

    void dikjstra(int a){

        vector<int> distance(this->vertices) ;
        vector<bool> visited(this->vertices) ;
        vector<int> parent(this->vertices) ;

        priority_queue<pi, vector<pi>, greater<pi>> pq ;

        for(int i = 0 ; i < this->vertices ; i++){
            distance[i] = MAX_VALUE ;
            visited[i] = false ;
        }

        parent[a-1] = -1 ; // parent of the source we are taking as -1 
        distance[a-1] = 0 ; // source vertex distance is 0 
        visited[a-1] = true ;
        pq.push(make_pair(0, a-1)) ;      // adding the node to the priority queue as indexes start from 0 we added a-1

        while(!pq.empty()){
            int one = pq.top().second ; 
            int dis = pq.top().first ;
            pq.pop() ;
            if(dis > distance[one]){
                continue ; // this is to ensure that uneccessary processing is not done
            }
            for(int i = 0 ;i < adj[one].size() ; i++){
                if((distance[one] + adj[one][i].second) < (distance[adj[one][i].first - 1])){

                    distance[adj[one][i].first - 1] = distance[one] + adj[one][i].second ;

                    pq.push(make_pair(distance[adj[one][i].first - 1], adj[one][i].first -1)) ;

                    parent[adj[one][i].first - 1] = one  ;

                    visited[adj[one][i].first - 1] = true ;
                }
            }
        }
        for(int i = 0 ; i < this->vertices ; i++){
            cout<<"Shortest distance from the vertex "<<a<<" to the vertex "<<i+1<<" using dijkstra algorithm is : "<<distance[i]<<endl ;
        }
        for(int i = 0 ; i < this->vertices ; i++){
            cout<<"The shortest path from the source vertex "<<a<<" to the vertex "<<i+1<<" is : " ;
            if(!visited[i]){
                cout<<"No path from the source vertex to the vertex "<<i+1<<endl  ;
            }
            else{
                vector<int> path ;
                for(int j = i ; j != -1 ; j = parent[j]){
                    path.push_back(j + 1) ;
                }
                reverse(path.begin(), path.end()) ;
                for(int i = 0 ; i < path.size() ; i++){
                    cout<<path[i]<<" " ;
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
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    graph g(9) ;
    g.addedge(1,2,4) ;
    g.addedge(1,8,8) ;
    g.addedge(2,3,8) ;
    g.addedge(2,8,11) ;
    g.addedge(8,9,7) ;
    g.addedge(7,8,1) ;
    g.addedge(9,7,6) ;
    g.addedge(9,3,2) ;
    g.addedge(3,6,4) ;
    g.addedge(6,4,14) ;
    g.addedge(5,6,10) ;
    g.addedge(4,5,9) ;
    g.addedge(3,4,7) ;
    g.addedge(7,6,2) ;
    g.print_graph() ;

    g.dikjstra(1) ;
    return 0 ;
}