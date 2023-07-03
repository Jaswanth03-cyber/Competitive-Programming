#include<bits/stdc++.h>
using namespace std ;


class graph{
    private :
    vector<vector<int>> adjlist ;
    int vertices ;
    vector<bool> visited ;
    vector<bool> added ;
    public :
    graph(int n, string labels){
        this->vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n) ;
        added.resize(n) ;
        fill(visited.begin(), visited.end(), false) ;
        fill(added.begin(), added.end(), false) ;
        added[0] = true ;
    }
    void addedge(int a, int b){
        if(added[a]){
            adjlist[a].push_back(b) ;
            added[b] = true ;
        }
        if(added[b]){
            adjlist[b].push_back(a) ;
            added[a] = true ;
        }
    }

    void dfs(int src, int &count, char value, string &labels){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        if(labels[src] == value){
            count++ ;
        }
        for(int i = 0 ; i < adjlist[src].size() ; i++){
            dfs(adjlist[src][i], count, value, labels) ;
        }
    }
    void make_false(){
        fill(visited.begin(), visited.end(), false) ;
    }
};
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph g(n, labels) ;
        for(int i = 0 ; i < edges.size() ; i++){
            g.addedge(edges[i][0], edges[i][1]) ;
        }

        vector<int> ans ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            g.dfs(i, count, labels[i], labels) ;
            ans.push_back(count) ;
            g.make_false() ;
            count  = 0 ;
        }
        return ans ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}