#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/
*/
class Solution {        
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0 ;
        for(int i = n-1 ; i >= 1 ; i = i - 2){
            ans += abs(cost[i] - cost[i-1]) ;
            cost[(i-1)/2] += max(cost[i], cost[i-1]) ;
        }
        return ans ; 
    }
};

/*
we try to modify all the path total sums equal to highest total um from root to the leaf so what we do is that 
we modify the values of the two child node valeus to same and add that value to the parent obv we have to change them 
the value which is maximum and this maximum value has to be added to the parent
*/