#include <bits/stdc++.h>
using namespace std ;

/*
Logic :-
I have created a new network of graph rather than given graph topology I have added new n vertices these n vertices are such that lets say in the original
graph we have vertices from 1 to n, correspondingly n+1 to 2*n vertices we will have  
here we have src, dest, cost given as input. 
src->dest one edge whose weight is cost
src+n->dest+n edge between these vertices whose edge cost is cost
src->dest+n edge whose cost is cost/2

src+n to dest + n has the same edges as 1-n along with this we have extra src -> dest + n whose edge cost is cost/2 because 
here we are having two graphs starting if we go from first graph to second graph we can not reach back first graph again as no edges back 
so in this graph according to the weights we will go from first graph to second graph only once where edge is cost/2 
actually some a->b is cost but instead of this we go from a->b+n whose cost/2 now from this b+n to we go to 2*n these edges cost is same as 
first graph only we have used this discount only once.
*/
typedef pair<int, long long> pi ;
typedef pair<long long, int> pii ;
class graph{
    int vertices ;
    vector<vector<pi>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(2*n) ;
    }

    void add(int src, int dest, long long cost){
        adjlist[src-1].push_back(make_pair(dest, cost)) ;
        adjlist[src-1+vertices].push_back(make_pair(vertices+dest, cost)) ;
        adjlist[src-1].push_back(make_pair(dest+vertices, cost/2)) ;
    }

    void dijkstra(){
        vector<long long> distance(2*vertices, LLONG_MAX) ;
        vector<bool> visited(2*vertices, false) ;
        priority_queue<pii, vector<pii>, greater<pii>> pq ;
        pq.push(make_pair(0, 1)) ;
        distance[0] = 0 ;

        while(!pq.empty()){
            int top = pq.top().second ;
            pq.pop() ;
            if(visited[top-1]){
                continue ;
            }
            visited[top-1] = true ;
            int size = adjlist[top-1].size() ;
            for(int i = 0 ; i < size ; i++){
                if(distance[adjlist[top-1][i].first-1] > distance[top-1] + adjlist[top-1][i].second){
                    distance[adjlist[top-1][i].first-1] = distance[top-1] + adjlist[top-1][i].second ;
                    pq.push(make_pair(distance[adjlist[top-1][i].first-1], adjlist[top-1][i].first)) ;
                }
            }
        }
        cout<<distance[2*vertices-1]<<endl ;
    }
};

int main(){
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;

    int n = 0 ;
    cin>>n ;

    int m = 0 ;
    cin>>m ;

    graph g(n) ;
    int src, dest ;
    long long cost ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest>>cost ;
        g.add(src, dest, cost) ;
    }
    g.dijkstra() ;
    return 0 ;
}