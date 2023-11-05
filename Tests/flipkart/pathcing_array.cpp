#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/patching-array/
*/

class Solution {
public:
    int minPatches(vector<int>& cost, int P) {
        long long sum = 0 ;
        int size = cost.size() ;
        int i = 0 ;
        int ans = 0 ;
        vector<int> req ;
        while(sum < P){
            if(i < size && cost[i] <= sum+1){
                sum = sum + cost[i++] ;
            }
            else{
                ans++ ;
                req.push_back(sum+1) ;
                sum = 2*sum + 1 ;
            }
        }
        return ans ; 
    }
};

/*
so starting from 1 what we are doing is that if in case first condition is satisfied so 
we can create sums upto sum = sum + nums[i]
if not then we need sum+1 being greedy so that we can get valeus upto sum*2+1 as we are adding sum+1 denomination to it 
*/