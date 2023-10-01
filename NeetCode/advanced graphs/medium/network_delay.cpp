#include <bits/stdc++.h>
using namepace std ;

/*
updating till the distance is min
*/

/*
https://leetcode.com/problems/network-delay-time/
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

    void add(int src, int dest, int weight){
        adjlist[src].push_back({dest, weight}) ;
    }

    int solve(int src){
        priority_queue<pi, vector<pi>, greater<pi>> pq ;
        pq.push({0, src}) ;
        vector<int> distance(vertices, INT_MAX) ;

        distance[src] = 0 ;

        while(!pq.empty()){
            int top = pq.top().second ;
            int dis = pq.top().first ;
            pq.pop() ;
            if(dis > distance[top]){
                continue ; // makes it simpler and less complex.
            }
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                int weight = adjlist[top][i].second ;
                if(distance[node] > dis + weight){
                    distance[node] = dis + weight ;
                    pq.push({distance[node], node}) ;
                }
            }
        }

        int ans = *max_element(distance.begin(), distance.end()) ;
        if(ans == INT_MAX){
            return -1 ;
        }
        return ans ;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        graph g(n) ;
        int m = times.size() ;
        for(int i = 0  ; i < m ; i++){
            g.add(times[i][0]-1, times[i][1]-1, times[i][2]) ;
        }
        int ans = 0 ;
        ans = g.solve(k-1) ;  
        return ans ;
    }
};