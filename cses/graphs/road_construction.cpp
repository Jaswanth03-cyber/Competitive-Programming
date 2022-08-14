#include<bits/stdc++.h>
using namespace std ;
typedef pair<int, int> pi ;
 
class graph{
    private:
    int vertices ;
    int edges ;
    vector<vector<int>> adjlist ;
    vector<vector<int>> adj_rev ;
    int strong_components ;
    int timer ;
    vector<pi> time_in ;
    vector<pi> time_out ;
    vector<bool> visited ;
    vector<bool> visited_rev ;
    public:
    graph(int n, int m){
        this->vertices = n ;
        this->edges = m ;
        this->timer = 0 ;
        adjlist.resize(n + 1) ;
        adj_rev.resize(n + 1) ;
        visited.resize(n+1) ;
        fill(visited.begin(), visited.end(), false) ;
        visited_rev.resize(n+1) ;
        fill(visited_rev.begin(), visited_rev.end(), false) ;
        strong_components = 0 ;
    }
    void addedge(int a, int b){
        adjlist[a].push_back(b) ;
        adjlist[b].push_back(a) ;
 
        adj_rev[a].push_back(b) ;
        adj_rev[b].push_back(a) ;
    }
 
    void dfs(int i){
        if(visited[i]){
            return ;
        }
        time_in.push_back(make_pair(timer, i)) ;
        timer++ ;
        visited[i] = true ;
        for(unsigned int j = 0 ; j < adjlist[i].size() ; j++){
            dfs(adjlist[i][j]) ;
        }
        time_out.push_back(make_pair(timer, i)) ;
        timer++ ;
    }
 
    void dfs_rev(int i){
        if(visited_rev[i]){
            return ;
        }
        visited_rev[i] = true ;
        for(unsigned int j = 0 ; j < adj_rev[i].size() ; j++){
            dfs_rev(adj_rev[i][j]) ;
        }
    }
 
    void fill_timer(){
        for(int i = 1 ; i <= this->vertices ; i++){
            if(!visited[i]){
                dfs(i) ;
            }
        }
    }
    void sort_timer(){
        sort(time_out.begin(), time_out.end(), greater<>()) ;
        sort(time_in.begin(), time_in.begin(), greater<>()) ;
    }
 
    void make_false(){
        fill(visited_rev.begin(), visited_rev.end(), false) ;
    }
    vector<int> no_strong_components(){
        vector<bool> used ;
        used.resize(this->vertices + 1) ;
        fill(used.begin(), used.end(), false) ;
        vector<int> no_of_vertices_component ;
        for(unsigned int i = 0 ; i < time_out.size() ; i++){
            if(!used[time_out[i].second]){
                dfs_rev(time_out[i].second) ;
                this->strong_components++ ;
            }
            int vertices_components = 0 ;
            for(int j =1 ; j <= this->vertices ; j++){
                if(visited_rev[j]){
                    used[j] = true ;
                    vertices_components++ ;
                }
            }
            make_false() ;
            no_of_vertices_component.push_back(vertices_components) ;
        }
        vector<int> result ;
        result.resize(2) ;
        sort(no_of_vertices_component.begin(), no_of_vertices_component.end(), greater<>()) ;
        result[0] = this->strong_components ;
        result[1] = no_of_vertices_component[0] ;
        return result ;
    }
 
    void re_use(){
        this->strong_components = 0 ;
        time_in.clear() ;
        time_out.clear() ;
        fill(visited.begin(), visited.end(), false) ;
        fill(visited_rev.begin(), visited_rev.end(), false) ;
    }
 
};
 
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n ; 
    int m ;
    cin>>n>>m ;
    graph g(n, m) ;
    for(int i = 0 ; i < m ; i++){
        int src ;
        int to ;
        cin>>src>>to ;
        g.addedge(src, to) ;
        vector<int> result ;
        g.fill_timer() ;
        g.sort_timer() ;
        result = g.no_strong_components() ;
        cout<<result[0]<<" "<<result[1]<<endl ;
        g.re_use() ;
    }
    return 0 ;
}