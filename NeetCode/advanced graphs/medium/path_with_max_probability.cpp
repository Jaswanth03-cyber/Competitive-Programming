#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/path-with-maximum-probability/description/
*/
typedef pair<double, int> pi ;
class graph{
    int vertices ;
    vector<vector<pair<int, double>>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest, double weight){
        adjlist[src].push_back({dest, weight}) ;
        adjlist[dest].push_back({src, weight}) ;
    }

    double solve(int src, int end){
        priority_queue<pi> pq ;
        pq.push({1.0, src}) ;
        vector<double> distance(vertices, 0.0) ;

        distance[src] = 1.0 ;

        while(!pq.empty()){
            int top = pq.top().second ;
            double dis = pq.top().first ;
            pq.pop() ;
            if(dis < distance[top]){
                continue ; // makes it simpler and less complex.
            }
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                cout<<adjlist[top][i].second<<" "<<dis<<" "<<top<<endl ;
                double weight = adjlist[top][i].second*dis ;
                if(distance[node] < weight){
                    distance[node] = weight ;
                    pq.push({distance[node], node}) ;
                }
            }
        }

        return distance[end] ;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        graph g(n) ;
        int m = edges.size() ;
        for(int i = 0 ; i < m ; i++){
            g.add(edges[i][0], edges[i][1], succProb[i]) ;
        }
        double ans = g.solve(start_node, end_node) ;
        return ans ;
    }
};

/*
normal dijkstra but here max heap thats it and see the update and to avoid useless processing we have added that if condition and continue.
*/