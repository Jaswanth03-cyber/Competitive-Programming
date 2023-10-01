#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    vector<char> color ;
    // vector<int> parent ;
    map<int, int> mpin ;
    map<int, int> mpout ;
    int timer ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n, false) ;
        color.resize(n, 'w') ;
        // parent.resize(n, 0) ;
        timer = 0 ;
    }

    void add(int src, int dest){
        adjlist[src-1].push_back(dest) ;
    }

    bool dfs(int src, stack<int> &st){
        mpin[src] = timer++ ;
        color[src-1] = 'g' ;
        int size = adjlist[src-1].size() ;
        for(int i = 0 ; i < size ; i++){
            if(color[adjlist[src-1][i]-1] == 'w'){
                // parent[adjlist[src-1][i]-1] = src ;
                if(dfs(adjlist[src-1][i], st)){
                    return true ;
                }
            }
            else if(color[adjlist[src-1][i]-1] == 'g'){
                return true ;
            }
        }
        color[src-1] = 'b' ;
        mpout[src] = timer++ ;

        st.push(src) ;
        return false ;
    }

    void cycle(){
        bool stop = false ;
        stack<int> st ;
        // dfs from 1 to n or n to 1 it results same as it depends on the edges direction, timerout gives the topo sort
        for(int i = 0 ; i <= vertices ; i++){
            if(color[i-1] == 'w'){
                if(dfs(i, st)){
                    stop = true ;
                    break ;
                }
            }
        }
        if(stop){
            cout<<"IMPOSSIBLE"<<endl ;
        }
        else{
            priority_queue<pair<int, int>> pq ;
            for(auto it = mpout.begin() ; it != mpout.end() ; it++){
                pq.push({it->second, it->first}) ;
            }

            while(!pq.empty()){
                cout<<pq.top().second<<" " ;
                pq.pop() ;
            }
            while(!st.empty()){
                cout<<st.top()<<" " ;
                st.pop() ;
            }
            cout<<endl ;
            cout<<endl ;
        }
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
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
    }
    g.cycle() ;
    return 0 ;
}