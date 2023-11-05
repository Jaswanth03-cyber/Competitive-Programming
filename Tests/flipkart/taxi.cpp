#include <bits/stdc++.h>
using namespace std ;

typedef pair<int, int> pi ;
class graph{
    int vertices ;
    vector<vector<pi>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(2*n) ;
    }

    void add(int src, int dest, int statecost, int nationalcost){
        adjlist[src].push_back({dest, statecost}) ;
        adjlist[dest].push_back({src, statecost}) ;
        adjlist[src+vertices].push_back({dest+vertices, statecost}) ;
        adjlist[dest+vertices].push_back({src+vertices, statecost}) ;

        adjlist[src].push_back({dest+vertices, nationalcost}) ;
        adjlist[dest].push_back({src+vertices, nationalcost}) ;
    }

    int solve(int src, int dest){
        if(src == dest){
            return 0 ;
        }
        vector<int> distance(2*vertices, INT_MAX) ;
        distance[src] = 0 ;
        priority_queue<pi, vector<pi>, greater<pi>> pq ;
        pq.push({0, src}) ;

        while(!pq.empty()){
            int top = pq.top().second ;
            int curr = pq.top().first ;
            pq.pop() ;
            if(curr > distance[top]){
                continue ;
            }

            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                int cost = adjlist[top][i].second ;
                if(curr + cost < distance[node]){
                    distance[node] = curr + cost ;
                    pq.push({distance[node], node}) ;
                }
            }
        }

        if(distance[dest+vertices] == INT_MAX){
            return -1 ;
        }
        return distance[dest+vertices] ;
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
    int src, dest, statecost, natcost ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest>>statecost>>natcost ;
        g.add(src-1, dest-1, statecost, natcost) ;
    }

    cin>>src ;
    cin>>dest ;
    int ans = g.solve(src-1, dest-1) ;
    cout<<ans<<endl ;
    return 0 ;
}