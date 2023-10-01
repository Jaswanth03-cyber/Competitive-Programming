#include <bits/stdc++.h>
using namespace std ;


/*
thing is that we are maintaining rev and given graph if in the first graph if we can not reach from a vertex from 1 just print no and 1, that vertex

if we can visite all the vertices then we can see that we can reach from 1 to all vertices 
now in the next reverse graph we are checking if we can reach 1 from all if not return No and print those 

now if in none of the cases if we dont have No then we can go from any cities to the other because you can reach every city from 1 and also 
you can reach 1 from any other city. 

in graph dfs(0) we will get all the vertices that can be reached from 0 
in rev graph dfs(0) all the vertices from which we can reach 0.
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<vector<int>> revlist ;
    vector<bool> visited ;
    vector<bool> visitedrev ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        revlist.resize(n) ;
        visited.resize(n, false) ;
        visitedrev.resize(n, false) ;
    }

    void add(int src, int dest){
        adjlist[src-1].push_back(dest-1) ;
        revlist[dest-1].push_back(src-1) ;
    }

    void dfs(int src){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            dfs(adjlist[src][i]) ;
        }
    }

    void dfsrev(int src){
        if(visitedrev[src]){
            return ;
        }
        visitedrev[src] = true ;
        int size = revlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            dfsrev(revlist[src][i]) ;
        }
    }

    void solve(){
        dfs(0) ;
        for(int i = 1 ; i < vertices ; i++){
            if(!visited[i]){
                cout<<"NO"<<endl ;
                cout<<1<<" "<<i+1<<endl ;
                return ;   
            }
        }

        dfsrev(0) ;
        for(int i = 1 ; i < vertices ; i++){
            if(!visitedrev[i]){
                cout<<"NO"<<endl ;
                cout<<i+1<<" "<<1<<endl ;
                return ;
            }
        }
        cout<<"YES"<<endl ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int m = 0 ;
    cin>>n>>m ;

    graph g(n) ;
    int src = 0, dest = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
    }

    g.solve() ;

}