#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/min-cost-to-connect-all-points/description/
*/

/*
connect all the vertices and then mst
*/
class disjoint_set{
    vector<int> parent ;
    vector<int> rank ;
    public:
    disjoint_set(int n){
        parent.resize(n, -1) ;
        rank.resize(n, -1) ;
    }

    void make_set(int v){
        parent[v] = v ;
        rank[v] = 1 ;
    }

    int find_set(int v){
        if(v == parent[v]){
            return v ;
        }
        parent[v] = find_set(parent[v]) ;
        return parent[v] ;
    }

    void unite_sets(int u, int v){
        int a = find_set(u) ;
        int b = find_set(v) ;

        if(rank[a] < rank[b]){
            swap(a, b) ;
        }
        parent[b] = a ;
        rank[a] += rank[b] ;
    }

};
struct edge{
    int src ;
    int dest ;
    int weight ;

    edge(int src, int dest, int weight){
        this->src = src ;
        this->dest = dest ;
        this->weight = weight ;
    }
};

struct comp{
    bool operator()(const edge &a, const edge &b)const{
        return a.weight < b.weight ;
    }
};

class graph{
    int vertices ;
    vector<edge> edges ;
    public:
    graph(int n){
        vertices = n ; 
    }
    void add(int src, int dest, int weight){
        edges.push_back(edge(src, dest,weight)) ;
    }

    int solve(){
        disjoint_set dsu(vertices) ;
        for(int i = 0 ; i < vertices ; i++){
            dsu.make_set(i) ;
        }

        sort(edges.begin(), edges.end(), comp()) ;
        int cost = 0 ;

        int size = edges.size() ;
        for(int i = 0 ; i < size ; i++){
            int src = edges[i].src, dest = edges[i].dest, weight = edges[i].weight ;
            int a = dsu.find_set(src), b = dsu.find_set(dest) ;
            if(a != b){
                cost += weight ;
                dsu.unite_sets(a, b) ;
            }
        }

        return cost ;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        graph g(n) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i != j){
                    g.add(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])) ;
                }
            }
        }

        int ans = g.solve() ;
        return ans ;
    }
};