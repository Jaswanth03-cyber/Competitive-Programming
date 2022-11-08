#include<bits/stdc++.h>
using namespace std ;
typedef tuple<int, int, int> tp ;

class graph{
    private:
    int vertices ;
    int edges ;
    vector<bool> pushed_tree ;
    vector<tuple<int, int, int>> edge_list ;
    public:
    graph(int n){
        this->vertices = n ;
        this->edges = 0 ;
        pushed_tree.resize(this->vertices) ;
        fill(pushed_tree.begin(), pushed_tree.end(), false) ;
    }
    void addedge(int from, int to, int weight){
        edge_list.emplace_back() ;
        get<0>(edge_list[this->edges]) = weight ;
        get<1>(edge_list[this->edges]) = from ;
        get<2>(edge_list[this->edges]) = to ;
        this->edges++ ;
    }

    void kruskal(){
        sort(edge_list.begin(), edge_list.end()) ; // by deafult sorted by first one 
        int tree_length  = 0 ;

        priority_queue<tp, vector<tp>, greater<tp>> pq ;
        pq.push(edge_list[0]) ;
        pushed_tree[get<1>(edge_list[0]) - 1] = true ;
        pushed_tree[get<2>(edge_list[0]) - 1] = true ;
        tree_length = tree_length + get<0>(pq.top()) ;

        vector<pair<int, int>> path ;
        path.push_back(make_pair(get<1>(edge_list[0]), get<2>(edge_list[0]))) ;

        for(int i = 1 ; i < edge_list.size() ; i++){
            if( !pushed_tree[get<1>(edge_list[i]) - 1] || !pushed_tree[get<2>(edge_list[i]) - 1]){
                pq.push(edge_list[i]) ;
                tree_length = tree_length + get<0>(edge_list[i]) ;
                pushed_tree[get<1>(edge_list[i]) - 1] = true ;
                pushed_tree[get<2>(edge_list[i]) - 1] = true ;
                path.push_back(make_pair(get<1>(edge_list[0]), get<2>(edge_list[0]))) ;
            }
        }
        cout<<"Tree length is "<<tree_length<<" and the edges added in the order are as shown : "<<endl ;
        for(int i = 0 ; i < path.size() ; i++){
            cout<<"("<<path[i].first<<", "<<path[i].second<<")"<<" " ;
        }
        cout<<endl ;
    }
};
/*
We can also even do this 

edge_list.push_back(make_tuple(weight, from, to)) ;
this->edges++ ;

or 

edge_list.emplace_back() ;
edge_list[this->edges] = {weight, from, to}
this->edges++ ;
*/

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    graph g(6) ;
    g.addedge(1,2,3) ;
    g.addedge(1,5,5) ;
    g.addedge(2,5,6) ;
    g.addedge(5,6,2) ;
    g.addedge(6,4,7) ;
    g.addedge(4,3,9) ;
    g.addedge(3,2,5) ;
    g.addedge(3,6,3) ;

    g.kruskal() ;


    graph G(5) ;
    G.addedge(1,2,1) ;
    G.addedge(2,4,4) ;
    G.addedge(4,5,2) ;
    G.addedge(5,3,6) ;
    G.addedge(5,2,3) ;
    G.addedge(3,2,5) ;
    G.addedge(1,3,7) ;

    G.kruskal() ;

    graph Gg(9) ;
    Gg.addedge(1,2,4) ;
    Gg.addedge(2,3,8) ;
    Gg.addedge(3,4,7) ;
    Gg.addedge(4,5,9) ;
    Gg.addedge(5,6,10) ;
    Gg.addedge(6,7,2) ;
    Gg.addedge(7,8,1) ;
    Gg.addedge(8,1,8) ;
    Gg.addedge(8,9,7) ;
    Gg.addedge(8,2,11) ;
    Gg.addedge(9,7,6) ;
    Gg.addedge(3,9,2) ;
    Gg.addedge(6,4,14) ;
    Gg.addedge(3,6,4) ;

    Gg.kruskal() ;

    return 0 ;
}