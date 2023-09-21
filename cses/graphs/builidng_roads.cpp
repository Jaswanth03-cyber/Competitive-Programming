#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    public:
    graph(int n){
        this->vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n) ;
        fill(visited.begin(), visited.end(), false) ;
    }
    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        adjlist[b-1].push_back(a) ;
    }

    void dfs(int src){
        if(visited[src-1]){
            return ;
        }
        visited[src-1] = true ;
        int size = adjlist[src-1].size() ;
        for(int i = 0 ; i < size ; i++){
            dfs(adjlist[src-1][i]) ;
        }
    }
    void solve(){
        vector<int> ans ;
        for(int i = 1 ; i <= vertices ; i++){
            if(!visited[i-1]){
                ans.push_back(i) ;
                dfs(i) ;
            }
        }
        int size = ans.size() ;
        cout<<size-1<<endl ;
        for(int i = 1 ; i < size ; i++){
            cout<<ans[i-1]<<" "<<ans[i]<<endl ;
        }
    }
};
int main(){
    cin.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    int m = 0 ;
    cin>>m ;

    graph g(n) ;
    int a = 0 ;
    int b = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>a ;
        cin>>b ;
        g.addedge(a, b) ;
    }
    g.solve() ;
    return 0 ;
}