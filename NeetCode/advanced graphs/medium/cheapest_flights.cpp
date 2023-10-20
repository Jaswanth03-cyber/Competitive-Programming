#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/
typedef pair<int, int> pi ;
class graph{
    int vertices ;
    vector<vector<pi>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest, int cost){
        adjlist[src].push_back({dest, cost}) ;
    }

    int solve(int src, int dest, int k){
        vector<int> distance(vertices, INT_MAX) ;
        vector<int> count(vertices, 0) ;
        distance[src] = 0 ;
        count[src] = -1 ;
        queue<tuple<int, int, int>> pq ;
        pq.push(make_tuple(src, 0, -1)) ;

        while(!pq.empty()){
            int top = get<0>(pq.front());
            int cost = get<1>(pq.front());
            int nofnodes = get<2>(pq.front()) ;
            pq.pop() ;
            int size = adjlist[top].size() ;

            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i].first ;
                int weight = adjlist[top][i].second ;
                if(nofnodes < k){
                    if(distance[node] > cost + weight){
                        distance[node] = cost + weight ;
                        pq.push(make_tuple(node, distance[node], nofnodes+1)) ;
                    }
                }
            }
        }
        if(distance[dest] == INT_MAX){
            return -1 ;
        }
        return distance[dest] ;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        graph g(n) ;
        int m = flights.size() ;
        for(int i = 0 ; i < m ; i++){
            g.add(flights[i][0], flights[i][1], flights[i][2]) ;
        }


        int ans = g.solve(src, dst, k) ;
        return ans ;
    }
};

/*
so the thing is that we have to change the approach of finding the minimum distance of nodexs from the starting node
note in the dijkstra to update distance of a node we update it using the distance pushed into the queue not using distance[top] + weight 
as we already check if cost > distance[top] then continue 

but here it is not the case there is a restriction in the number of nodes between src to destination so along with the distance I will also push
number of vertices in that minimum path so if numberofnodes < k and also cost+weight is less than the current distance[node] I am updating it 
and pushing it into the queue do not push if there is no update useless processing, note that initial number of nodes for src is -1

and also note I am not updating the distance using distance[top] + weight, distance[top] might have been updated before itself whose shortest path
has already k nodes in a way for the current vertex you are finding the shortest path with k+1 nodes which is nothing but finding the shortest
distance between src and dest with out any contsraint on the number of vertices in between. so update using the cost in the queue. 

also only if distance updates then only push otherwise do not uneccessary processing of nodes leads to MLE/TLE

this can be done usingg min heap also just like dijkstra but note the number of vertices when updating.
*/