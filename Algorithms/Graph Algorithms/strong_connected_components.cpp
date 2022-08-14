#include<bits/stdc++.h>
using namespace std ;
typedef pair<int, int> pi ;


class graph{
    private:
    int vertices ;
    int edges ;
    vector<vector<int>> adjlist ;
    vector<vector<int>> adj_rev ;
    int no_strong_components ;
    vector<bool> visited ;
    vector<bool> visited_rev ;
    int timer ;
    vector<pi> time_in ;
    vector<pi> time_out ;

    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ;
        adjlist.resize(this->vertices +1) ;
        adj_rev.resize(this->vertices +1) ;
        this->no_strong_components = 0 ;
        visited.resize(this->vertices +1) ;
        visited_rev.resize(this->vertices +1) ;
        fill(visited.begin(), visited.end(), false) ;
        fill(visited_rev.begin(), visited_rev.end(), false) ;
        this->timer = 0 ;
    }

    void addedge(int a, int b){
        adjlist[a].push_back(b) ;
        adj_rev[b].push_back(a) ;
        this->edges++ ;
    }

    void dfs(int src){
        if(!visited[src]){
            visited[src] = true ;
            time_in.push_back(make_pair(this->timer, src)) ;
            this->timer++ ;
            for(unsigned int i = 0 ; i < adjlist[src].size() ; i++){
                dfs(adjlist[src][i]) ;
            }
            time_out.push_back(make_pair(this->timer, src)) ;
            this->timer++ ;
        }
    }
    void fill_timers(){
        for(int i =1 ; i <=this->vertices ; i++){
            if(!visited[i]){
                dfs(i) ;
            }
        }
    }
    void sort_timers(){
        sort(time_in.begin(), time_in.end(), greater<>()) ;
        sort(time_out.begin(), time_out.end(), greater<>()) ;
    }

    void dfs_rev(int src, vector<int> &vertices){
        if(!visited_rev[src]){
            vertices.push_back(src) ;
            visited_rev[src] = true ;
            for(unsigned int i = 0 ; i < adj_rev[src].size() ; i++){
                dfs_rev(adj_rev[src][i], vertices) ;
            }
        }
    }

    void make_false(){
        fill(visited_rev.begin(), visited_rev.end(), false) ;
    }

    vector<pair<int , vector<int>>> strong_components(){
        vector<bool> used(this->vertices + 1, false) ;
        fill_timers() ;
        sort_timers() ;
        vector<pair<int, vector<int>>> result ;
        for(unsigned int i = 0 ; i < time_out.size() ; i++){
            if(!used[time_out[i].second]){
                vector<int> vertices ;
                dfs_rev(time_out[i].second, vertices) ;
                this->no_strong_components++ ;
                for(int j = 1; j <=this->vertices ; j++){
                    if(visited_rev[j]){
                        used[j] = true ;
                    }
                }
                //make_false() ;
                int size = vertices.size() ;
                result.push_back(make_pair(size, vertices)) ;
            }
        }
        return result ;
    }
    int total_strong_components(){
        return this->no_strong_components ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    graph g(8) ;
    g.addedge(1,2) ;
    g.addedge(2,3) ;
    g.addedge(3,4) ;
    g.addedge(4,1) ;
    g.addedge(3,5) ;
    g.addedge(5,6) ;
    g.addedge(6,7) ;
    g.addedge(7,5) ;
    g.addedge(7,8) ;

    vector<pair<int , vector<int>>> result = g.strong_components() ;
    cout<<g.total_strong_components()<<endl ;                              // to check both results properly
    cout<<"----------------------------------------"<<endl ;
    cout<<"Total no of strongly connected components are : "<<result.size()<<endl ;
    for(unsigned int i = 0 ; i < result.size() ; i++){
        cout<<"No of vertices in the "<<i+1<<"th components is "<<result[i].first<<" and the vertices are as shown :" ;
        for(unsigned int j = 0 ; j < result[i].second.size() ; j++){
            cout<<result[i].second[j]<<" " ;
        }
        cout<<endl ;
    }

    graph G(6) ;
    G.addedge(1,2) ;
    G.addedge(2,3) ;
    G.addedge(3,1) ;
    G.addedge(4,5) ;

    vector<pair<int, vector<int>>> result_1 = G.strong_components();
    cout<<G.total_strong_components()<<endl ;                              // to check both results properly
    cout<<"----------------------------------------"<<endl ;
    cout<<"Total no of strongly connected components are : "<<result_1.size()<<endl ;
    for(unsigned int i = 0 ; i < result_1.size() ; i++){
        cout<<"No of vertices in the "<<i+1<<"th components is "<<result_1[i].first<<" and the vertices are as shown :" ;
        for(unsigned int j = 0 ; j < result_1[i].second.size() ; j++){
            cout<<result_1[i].second[j]<<" " ;
        }
        cout<<endl ;
    }

    graph gra(12) ;
    gra.addedge(1,2) ;
    gra.addedge(2,3) ;
    gra.addedge(3,4) ;
    gra.addedge(4,1) ;
    gra.addedge(5,1) ;
    gra.addedge(10,6) ;
    gra.addedge(6,7) ;
    gra.addedge(7,6) ;
    gra.addedge(8,6) ;
    gra.addedge(9,8) ;
    gra.addedge(11,12) ;
    gra.addedge(12,11) ;

    vector<pair<int, vector<int>>> result_2 = gra.strong_components();
    cout<<gra.total_strong_components()<<endl ;                              // to check both results properly
    cout<<"----------------------------------------"<<endl ;
    cout<<"Total no of strongly connected components are : "<<result_2.size()<<endl ;
    for(unsigned int i = 0 ; i < result_2.size() ; i++){
        cout<<"No of vertices in the "<<i+1<<"th components is "<<result_2[i].first<<" and the vertices are as shown :" ;
        for(unsigned int j = 0 ; j < result_2[i].second.size() ; j++){
            cout<<result_2[i].second[j]<<" " ;
        }
        cout<<endl ;
    }

    return 0 ;
}