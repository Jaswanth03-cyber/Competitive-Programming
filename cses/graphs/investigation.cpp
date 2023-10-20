#include <bits/stdc++.h>
using namespace std ;

/*
this is more of dijkstra so if a node diatnce is less then minpaths[node] = minpaths[top] both will be the same and also we have to find number
of flights which means number of edges in the path, this can be modified to min or max numbrr of vertices in the min path so only base case changes
set base values to 1, and also whenever distance[node] is same it means with the min distance itself we can reach many ways so adding those ways to 
the node from top and also minflights and maxflights take the min and max
*/
typedef long long ll ;
typedef pair<int, ll> pi ;
typedef pair<ll, int> pii ;
class graph{
    int vertices ;
    vector<vector<pi>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest, ll cost){
        adjlist[src].push_back({dest, cost}) ;
    }

    void solve(){
        int mod = 1e9 + 7 ;
        priority_queue<pii, vector<pii>, greater<pii>> pq ;
        vector<ll> distance(vertices, LLONG_MAX) ;
        vector<int> minpaths(vertices, 0) ;
        vector<int> minflights(vertices, vertices) ;
        vector<int> maxflights(vertices, 0) ;
        minpaths[0] = 1 ;
        minflights[0] = 0 ;
        maxflights[0] = 0 ;
        distance[0] = 0 ;
        pq.push({0, 0}) ;

        while(!pq.empty()){
            int top = pq.top().second ;
            ll currcost = pq.top().first ;
            pq.pop() ;
            if(currcost > distance[top]){
                continue ;
            }
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                ll cost = adjlist[top][i].second ;
                if(distance[node] > currcost + cost){
                    distance[node] = currcost + cost ;
                    pq.push({distance[node], node}) ;
                    minpaths[node] = minpaths[top] ;
                    minflights[node] = minflights[top] + 1 ;
                    maxflights[node] = maxflights[top] + 1 ;
                }
                else if(distance[node] == cost + currcost){
                    minpaths[node] = (minpaths[node] + minpaths[top])%mod ;
                    minflights[node] = min(minflights[node], minflights[top]+1) ;
                    maxflights[node] = max(maxflights[node], maxflights[top]+1) ;
                }
            }
        }

        cout<<distance[vertices-1]<<" "<<minpaths[vertices-1]<<" "<<minflights[vertices-1]<<" "<<maxflights[vertices-1]<<endl ;
    }
};
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    int m = 0 ;
    cin>>m ;
    graph g(n) ;
    int src=0, dest = 0 ;
    ll cost = 0 ;

    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest>>cost ;
        g.add(src-1, dest-1, cost) ;
    }
    g.solve() ;
    return 0 ;
}