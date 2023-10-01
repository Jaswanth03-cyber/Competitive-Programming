#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
*/

/*
Note this is not dijkstra 
*/
typedef pair<int, int> pi ;
class graph{
    int vertices ;
    vector<vector<pair<int, int>>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest, int cost){
        adjlist[src-1].push_back({dest-1, cost}) ;
        adjlist[dest-1].push_back({src-1, cost}) ;
    }

// both are working
    int solve1(){
        vector<int> distance(vertices, 1e5) ;
        queue<pair<int, int>> pq ;
        pq.push({1e5, 0}) ;
        while(!pq.empty()){
            int top = pq.front().second ;
            int dis = pq.front().first ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                int weight = adjlist[top][i].second ;
                if(distance[node] > min(dis, weight)){
                    distance[node] = min(dis, weight) ;
                    pq.push({distance[node], node}) ;
                }
            }
        }
        return distance[vertices-1] ;
    }

    int solve(){
        vector<int> distance(vertices, 1e5) ;
        queue<pair<int, int>> pq ;
        pq.push({1e5, 0}) ;
        while(!pq.empty()){
            int top = pq.front().second ;
            int dis = pq.front().first ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                int weight = adjlist[top][i].second ;
                if(distance[node] > min(distance[top], weight)){
                    distance[node] = min(distance[top], weight) ;
                    pq.push({distance[node], node}) ;
                }
            }
        }
        return distance[vertices-1] ;
    }
/*
normal dijkstra with modified definition of distance
every node has to visit once 
*/
// this is also working 
    int solve2(){
        int MIN = 1e5 ;
        vector<int> distance(vertices, MIN) ;
        priority_queue<pi, vector<pi>, greater<pi>> pq ;
        pq.push({MIN, 0}) ;
        while(!pq.empty()){
            int top = pq.top().second ;
            int dis = pq.top().first ;
            pq.pop() ;
            if(dis > distance[top]){
                continue ;
            }
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                int weight = adjlist[top][i].second ;
                if(distance[node] > min(distance[top], weight)){
                    distance[node] = min(distance[top], weight) ;
                    pq.push({distance[node], node}) ;
                }
            }
        }
        return distance[vertices-1] ;
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        graph g(n) ;
        int m = roads.size() ;
        for(int i = 0 ; i < m ; i++){
            g.add(roads[i][0], roads[i][1], roads[i][2]) ;
        }
        int ans = g.solve() ;
        return ans ;
    }
};