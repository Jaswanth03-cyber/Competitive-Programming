#include <bits/stdc++.h>
using namespace std ;

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
};
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        unordered_map<pair<int, int>, int> mp ;
        mp.insert({{start[0], start[1]}, 0}) ;
        int count = 1 ;
        int m = specialRoads.size() ;
        for(int i = 0 ; i < m ; i++){
            if(mp.find({specialRoads[i][0], specialRoads[i][1]}) == mp.end()){
                mp.insert({{specialRoads[i][0], specialRoads[i][1]}, count++}) ;
            }
            if(mp.find({specialRoads[i][2], specialRoads[i][3]}) == mp.end()){
                mp.insert({{specialRoads[i][2], specialRoads[i][3]}, count++}) ;
            }
        }
        if(mp.find({target[0], target[1]}) == mp.end()){
            mp.insert({{target[0], target[1]}, count++}) ;
        }

        graph g(count) ;
        for(int i = 0 ; i < m ; i++){
            int cost = min(specialRoads[i][4], abs(specialRoads[i][0] - specialRoads[i][2]) + abs(specialRoads[i][1] - specialRoads[i][3]));

        }
    }
};