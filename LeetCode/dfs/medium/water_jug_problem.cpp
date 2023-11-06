#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/water-and-jug-problem/
*/
class Solution {
public:
    bool dfs(int total, int jug1, int jug2, int jug, int target, vector<bool>& visited){
        if(jug > total || jug < 0 || visited[jug] ){
            return false;
        }
        visited[jug] = true ;
        if(jug == target){
            return true;
        }
        bool a = dfs(total, jug1, jug2, jug+jug1, target, visited);
        bool b = dfs(total, jug1, jug2, jug-jug1, target, visited);
        bool c = dfs(total, jug1, jug2, jug+jug2, target, visited);
        bool d = dfs(total, jug1, jug2, jug-jug2, target, visited);
        bool ans = a || b || c || d ;
        return ans ;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int total = jug1Capacity + jug2Capacity ;
        vector<bool> visited(total+1, 0) ;
        int jug = 0 ;
        return dfs(total, jug1Capacity, jug2Capacity, jug, targetCapacity, visited); 
    }
};

/*

if(x + y < z) 
    return false;
if(x == z or y == z or x + y == z)
    return true;

// property of Bézout's identity
return (z % __gcd(x,y) == 0);
*/