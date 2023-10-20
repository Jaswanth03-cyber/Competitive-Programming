#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> paththrough ;
    vector<int> firstmaxdistance ;
    vector<int> secondmaxdistance ;
    public:

    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        firstmaxdistance.resize(n, 0) ;
        secondmaxdistance.resize(n, 0) ;
        paththrough.resize(n, 0) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs1(int src, int parent){
        int size = adjlist[src].size() ;

        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dfs1(node, src) ;

            if(firstmaxdistance[node]+1 > firstmaxdistance[src]){
                secondmaxdistance[src] = firstmaxdistance[src] ;
                firstmaxdistance[src] = firstmaxdistance[node] + 1 ;
                paththrough[src] = node ;
            }
            else if(firstmaxdistance[node] + 1 > secondmaxdistance[src]){
                secondmaxdistance[src] = firstmaxdistance[node] + 1 ;
            }
        }
    }

    void dfs2(int src, int parent){
        int size = adjlist[src].size() ;

        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }

            if(paththrough[src] == node){
                if(secondmaxdistance[src] + 1 > firstmaxdistance[node]){
                    secondmaxdistance[node] = firstmaxdistance[node] ;
                    firstmaxdistance[node] = secondmaxdistance[src] + 1 ;
                    paththrough[node] = src ;
                }
                else if(secondmaxdistance[src] + 1 > secondmaxdistance[node]){
                    secondmaxdistance[node] = secondmaxdistance[src] + 1 ;
                }
            }
            else{
                secondmaxdistance[node] = firstmaxdistance[node] ;
                firstmaxdistance[node] = firstmaxdistance[src] + 1 ;
                paththrough[node] = src ;
            }
            dfs2(node, src) ;
        }
    }

    void solve(){
        dfs1(0, -1) ;
        dfs2(0, -1) ;

        for(int i = 0 ; i < vertices ; i++){
            cout<<firstmaxdistance[i]<<" " ;
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
    int m = n-1 ;
    graph g(n) ;
    int src, dest =0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src-1, dest-1) ;
    }
    g.solve() ;
    return 0 ;
}