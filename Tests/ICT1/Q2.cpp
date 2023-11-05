#include <bits/stdc++.h>
using namespace std ;

typedef pair<int, char> pi ;

bool valid(string s){
    int size = s.length() ;
    bool ans = true ;
    unordered_map<char, int> mp ;
    for(int i = 0 ; i < size ; i++){
        mp[s[i]]++ ;
    }

    int count = 0 ;
    for(auto it = mp.begin() ; it != mp.end() ; it++){
        if(it->second%2 == 1){
            count++ ;
        }
    } 

    if(count > 1 || (count == 1 && size%2 == 0)){
        ans = false ;
    }

    return ans ;    
} 

class graph{
    int vertices ;
    vector<vector<pi>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest, char c){
        adjlist[src].push_back({dest, c}) ;
        adjlist[dest].push_back({src, c}) ;
    }

    void dfs(int src, int &count){
        vector<string> path(vertices, "") ;
        vector<bool> visited(vertices, false) ;

        queue<int> pq ;
        pq.push(src) ;
        visited[src] = true ;
        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;

            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                char a = adjlist[top][i].second ;
                if(!visited[node]){
                    visited[node] = true ;
                    path[node] = path[top]+ a ;
                    pq.push(node) ;
                }
            }
        }

        for(int i = 0 ; i < vertices ; i++){
            if(i != src){ // we do not want empty string 
                if(valid(path[i])){
                    count++ ;
                }
            }
        }
    }

    void solve(){

        int count = 0 ; 
        for(int i = 0 ; i < vertices ; i++){
            dfs(i, count) ;
        }
        int ans = count/2 ; // as we counted every string two times
        cout<<ans<<endl ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    vector<int> parent(n, 0) ;
    string s ; 
    for(int i = 0 ; i < n ; i++){
        cin>>parent[i] ;
    }
    cin>>s ;
    graph g(n) ;
    for(int i = 1 ; i < n ; i++){
        g.add(i, parent[i], s[i]) ;
    }
    g.solve() ;
    return 0 ;
}