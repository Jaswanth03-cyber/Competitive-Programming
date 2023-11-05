#include <bits/stdc++.h>
using namespace std ;


/*
this can even be done using floyd warshall, all pair shortest paths but all pair shortest path complexity will be O(N^3) this has O(N*(N+N-1)) = O(N^2)
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest){
        adjlist[src-1].push_back(dest) ;
        adjlist[dest-1].push_back(src) ;
    }

    int dfs(int src){
        vector<int> dis(vertices, 0) ;
        vector<bool> visited(vertices, false) ;

        queue<int> pq ;
        visited[src-1] = true ;
        dis[src-1] = 0 ;
        int ans = 0 ;
        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;
            int size = adjlist[top-1].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top-1][i] ;
                if(!visited[node-1]){
                    visited[node-1] = true ;
                    dis[node-1] = dis[top-1] + 1 ;
                    pq.push(node) ;
                    ans = max(ans, dis[node-1]) ;
                }
            }
        }
        return ans ;
    }

    vector<int> solve(){
        vector<int> ans(vertices, 0) ;
        for(int i = 1 ; i <= vertices ; i++){
            ans[i] = dfs(i) ;
        }
        return ans ;
    }

};

vector<int> calculate_power(int n, vector<vector<int>> &vec){
    graph g(n) ;
    for(int i = 0 ; i < n-1 ; i++){
        g.add(vec[i][0], vec[i][1]) ;
    }
    vector<int> ans = solve() ;
    return ans ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int n = 0 ;
    cin>>n ;
    vector<vector<int>> vec(n-1, vector<int>(2, 0)) ;
    for(int i = 0 ; i < n -1 ; i++){
        cin>>vec[i][0]>>vec[i][1] ;
    }
    vector<int> ans = calculate_power(n, vec) ;
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" " ;
    }
    return 0 ;
}