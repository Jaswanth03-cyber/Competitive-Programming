#include<bits/stdc++.h>
using namespace std ;

class graph{
    private: 
    int vertices ;
    int edges ;
    vector<pair<int, int>> *adjlist ;
    vector<vector<int>> distance ;
    public:
    graph(int n){
        this->vertices = n ; 
        this->edges = 0 ; 
        adjlist = new vector<pair<int, int>>[this->vertices] ;
        distance.resize(this->vertices+1) ;
        for(int i = 0 ; i <= this->vertices ; i++){
            distance[i].resize(this->vertices + 1) ;
        }
        for(int i = 0 ; i <= this->vertices ; i++){
            distance[0][i] = 0 ; 
            distance[i][0] = 0 ; 
            distance[i][i] = 0 ;
        }
        for(int i = 1 ; i <=this->vertices ; i++){
            for(int j = 1 ; j <=this->vertices ; j++){
                if(i != j){
                    distance[i][j] = 1e5 ;
                }
            }
        }
    }

    void addedge(int a, int b, int weight){
        adjlist[a-1].push_back(make_pair(b, weight)) ;
        this->edges++ ;
    }

    void floyd_warshall(){
        for(int i = 1 ; i <=this->vertices ; i++){
            for(int j = 0 ; j < adjlist[i-1].size() ; j++){
                if(distance[i][adjlist[i-1][j].first] > adjlist[i-1][j].second){
                    distance[i][adjlist[i-1][j].first] = adjlist[i-1][j].second ; 
                }
                // distance[i][adjlist[i-1][j].first] = adjlist[i-1][j].second ;
                // this condition is checked because if more edges between two vertices we are taking the minimum one 
            }
        }

        for(int k = 1 ; k <=this->vertices ; k++){
            for(int i = 1 ; i <=this->vertices ; i++){
                for(int j = 1 ; j <=this->vertices ; j++){
                    if((distance[i][k] < 1e5) && (distance[k][j] < 1e5)){
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]) ;
                    }
                }
            }
        }

        for(int i = 1 ; i <=this->vertices ; i++){
            for(int j = 1 ; j <=this->vertices ; j++){
                if(i == j){
                   // we can leave this blank nothing happens  
                }
                else if(abs(distance[i][j] - 1e5) <= 100){
                    cout<<"There is no path from the vertex "<<i<<" to the vertex "<<j<<endl ;
                }
                else{
                    cout<<"The shortest distance from the vertex "<<i<<" to the vertex "<<j<<" is : "<<distance[i][j]<<endl ;
                }
            }
        }
    }




    ~graph(){
        delete[] adjlist ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    graph g(4) ;

    g.addedge(1,2,5) ;
    g.addedge(2,3,-3) ;
    g.addedge(3,4,1) ;
    g.addedge(1,4,10) ;

    g.floyd_warshall() ;

    return 0 ;

}