#include<bits/stdc++.h>
using namespace std ;

class graph{
    private:
    int vertices ;
    int edges ;
    vector<vector<pair<int, long long>>> adjlist ;
    vector<vector<long long>> distance ;
    long long MAX = 1e12 ;
    public:
    graph(int n, int m){
        this->vertices = n ;
        this->edges = m ;
        adjlist.resize(this->vertices) ;
        distance.resize(this->vertices + 1) ;
        for(int i = 0 ; i <= this->vertices ; i++){
            distance[i].resize(this->vertices + 1) ;
        }
        for(int i = 0 ; i <= this->vertices ; i++){
            distance[i][0] = 0 ;
            distance[0][i] = 0 ;
            distance[i][i] = 0 ;
        }
        for(int i = 1 ; i <=this->vertices ; i++){
            for(int j = 1 ; j <=this->vertices ; j++){
                if(i != j){
                    distance[i][j] = MAX ;
                }
            }
        }
    }

    void addedge(int a, int b, long long weight){
        adjlist[a-1].push_back(make_pair(b, weight)) ;
        adjlist[b-1].push_back(make_pair(a, weight)) ;
    }

    void floyd_warshall(){

        for(int i = 0 ; i < this->vertices ; i++){
            for(unsigned int j = 0 ; j < adjlist[i].size() ; j++){
                if(distance[i+1][adjlist[i][j].first] > adjlist[i][j].second){
                    distance[i+1][adjlist[i][j].first] = adjlist[i][j].second ;      
                }
               // distance[i+1][adjlist[i][j].first] = adjlist[i][j].second ;
            }
        }
        for(int k = 1 ; k <=this->vertices ; k++){
            for(int i = 1 ; i <=this->vertices ; i++){
                for(int j = 1 ; j <=this->vertices ; j++){
                    if((distance[i][k] < MAX) && (distance[k][j] < MAX)){
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]) ;
                    }
                }
            }
        }
    }

    long long distance_vertices(int a, int b){
        if(abs(distance[a][b] - MAX) <= 100){
            return - 1;
        }
        else{
            return distance[a][b] ;
        }
    }
};




int main(){
    ios_base::sync_with_stdio(false)  ;
    cin.tie(NULL) ;

    int n ;
    int m ;
    int q ;
    cin>>n>>m>>q ;

    graph g(n, m);

    for(int i = 0 ; i < m ; i++){
        int a ;
        int b ; 
        long long weight ; 
        cin>>a>>b>>weight ;
        g.addedge(a,b,weight) ;
    }

    g.floyd_warshall() ;

    for(int i = 1 ; i <= q ; i++){
        int a ;
        int b ; 
        cin>>a>>b ; 
        cout<<g.distance_vertices(a, b)<<endl  ;
    }
    
    return 0 ;
}