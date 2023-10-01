#include <bits/stdc++.h>
using namespace std ;

/*
the thing is that given 1 is the boss so doing bfs from one and stroing child boss pair in stack now in the stack top 
always leaves and their respective bosses will be there so going through the stack and adding the sub ordinates

As I have just added the edge from boss to the sub ordinate making it directed there is no need of visited 
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
        adjlist[src-1].push_back(dest-1) ;
    }

    void solve(){
        queue<int> pq ;
        pq.push(0) ;
        // vector<bool> visited(vertices, false) ;
        // visited[0] = true ;
        stack<pair<int, int>> st ;
        vector<int> ans(vertices, 0) ;
        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i] ;
                // if(!visited[node]){
                // visited[node] = true ;
                st.push({node,top}) ;
                pq.push(node) ;
                // }
            }
        }

        while(!st.empty()){
            int first = st.top().first ;
            int second = st.top().second ;
            ans[second] += ans[first]+1 ;
            st.pop() ;
        }

        for(int i = 0 ; i < vertices ; i++){
            cout<<ans[i]<<" " ;
        }
        cout<<endl ;
    }
};
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    graph g(n) ;
    int boss ;
    for(int i = 2 ; i <= n ; i++){
        cin>>boss ;
        g.add(boss, i) ;
    }

    g.solve() ;
}