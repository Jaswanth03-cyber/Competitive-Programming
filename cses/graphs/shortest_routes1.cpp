#include <bits/stdc++.h>
using namespace std ;

typedef pair<long long, int> pi ;
typedef pair<int, long long> pii ;
class graph{
    private :
    int vertices ;
    vector<vector<pii>> adjlist ;
    vector<bool> visited ;
    vector<long long> distance ;
    public:
    graph(int n){
        this->vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n) ;
        fill(visited.begin(), visited.end(), false) ;
        distance.resize(n) ;
        fill(distance.begin(), distance.end(), LLONG_MAX) ;
    }

    void add(int src, int dest, long long dist){
        adjlist[src-1].push_back(make_pair(dest, dist)) ;
    }

    void dijkstra(){
        priority_queue<pi, vector<pi>, greater<pi>> pq ;
        pq.push(make_pair(0, 1)) ;
        distance[0] = 0 ;
        int src = 0 ;
        int size = 0 ;

        while(!pq.empty()){
            src = pq.top().second ;
            pq.pop() ;
            if(visited[src-1]){
                continue ;
            }
            visited[src-1] = true ;
            size = adjlist[src-1].size() ;
            for(int i = 0 ; i < size ; i++){
                if(distance[adjlist[src-1][i].first -1] > distance[src-1] + adjlist[src-1][i].second){
                    distance[adjlist[src-1][i].first -1] = distance[src-1] + adjlist[src-1][i].second ;
                    pq.push(make_pair(distance[adjlist[src-1][i].first-1], adjlist[src-1][i].first)) ;
                }
            }
        }

        for(int i = 0 ; i < this->vertices ; i++){
            cout<<distance[i]<<" " ;
        }
        cout<<endl ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ; 
    int m = 0 ;
    cin>>n ;
    cin>>m ;

    graph g(n) ;

    int src = 0;
    int dest = 0 ;
    long long dist = 0 ;
    for(int i = 0 ; i < m; i++){
        cin>>src ;
        cin>>dest ;
        cin>>dist ;
        // cout<<dist<<endl ;
        g.add(src, dest, dist) ;
    }
    g.dijkstra() ;
    return 0 ;
}