#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ; 
    vector<int> *adjlist ;
    vector<bool> visited ;
    vector<int> distance ;

    public:
    graph(int n){
        this->vertices = n ; 
        adjlist = new vector<int>[n] ;
        visited.resize(n) ;
        fill(visited.begin(), visited.end(), false) ;
        distance.resize(n) ;
        fill(distance.begin(), distance.end() , 0) ;
    }

    void addedge(int a, int b){
        adjlist[a-1].push_back(b) ;
        adjlist[b-1].push_back(a) ;
    }

    void nullify(){
        fill(distance.begin(), distance.end(), 0) ;
        fill(visited.begin(), visited.end(), false) ;
    }

    void bfs(int src){
        visited[src-1] = true ;
        distance[src-1] = 0 ;
        queue<int> pq ; 
        pq.push(src) ;
        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;

            for(unsigned int i = 0 ; i < adjlist[top-1].size() ; i++){
                if(!visited[adjlist[top-1][i] -1]){
                    visited[adjlist[top-1][i] - 1] = true ;
                    distance[adjlist[top-1][i] - 1] = distance[top- 1] +  1 ;
                    pq.push(adjlist[top-1][i]) ;
                }
                else{
                    continue ;
                }
            }
        }
    }

    int max_distance_index(){
        int maximum = distance[this->vertices - 1] ; 
        int index = this->vertices  ;
        for(int i = 0 ; i < this->vertices - 1 ; i++){
            if(maximum < distance[i]){
                maximum = distance[i] ;
                index = i + 1 ;
            }
        }

        return index  ;
    }

    int max_distance(){
        int maximum = distance[0] ; 
        for(int i = 1 ; i < this->vertices ; i++){
            if(maximum < distance[i]){
                maximum = distance[i] ;
            }
        }
        int result = maximum ;
        return result ;       
    }

};




int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    int n ; 
    cin>>n ; 

    graph g(n) ;
    if(n == 1){
        cout<<0<<endl ;
    }
    else{
        int src ;
        for(int i = 1 ; i <= n-1 ; i++){
            int a ;
            int b ;
            cin>>a>>b ; 
            g.addedge(a, b) ;
            src = b ;
        }

        g.bfs(src) ;

        int index = g.max_distance_index() ;

        g.nullify() ;
        g.bfs(index) ;

        int result = g.max_distance() ;
        cout<<result<<endl ; 
    }
    return 0 ;
}