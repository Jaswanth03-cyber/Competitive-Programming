#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/delete-and-earn/
*/
/*
Logic 
sort the input array now have a freq map and also a vector which just contains the distinct elements of the given input array
here it is somewhat similar to knapsack there exists different cases such as if we take this and what if we not take this it comes like a decision 
tree so somewhat like knapsack 

so basically after calculating the vector now we will maintain a dp where 
dp[i] denotes maximum you can earn considering elements from to 0 to i-1 in the temp vector created 
so dp[0] is 0 base case and dp[1] will obv be temp[i-1]*countof(temp[i-1])
so now dp[i] from i = 2 till m
two cases if temp[i-1] is temp[i-2]+1 then take the maximum of we can earn if we take temp[i-1] and if we take temp[i-2] note if we take
temp[i-1] then we can include temp[i-3] that is dp[i-2] so consider maximum as abs(temp[i-3]-temp[i-1]) > 1 so we can take it
if temp[i-1] and temp[i-2] does not differ by 2 then we dp[i] will be maximum if we consider both.

so return dp[n] 
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(), nums.end()) ;
        vector<int> temp ;
        map<int, int> mp ;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]]++ ;
            }
            else{
                mp.insert({nums[i], 1}) ;
                temp.push_back(nums[i]) ;
            }
        }
        int m = temp.size() ;
        vector<int> dp(m+1, 0) ;
        dp[1] = temp[0]*mp[temp[0]] ;
        for(int i = 2 ; i <= m ; i++){
            if(temp[i-1] == temp[i-2]+1){
                dp[i] = max(dp[i-1], temp[i-1]*mp[temp[i-1]] + dp[i-2]) ;
            }
            else{
                dp[i] = dp[i-1] + temp[i-1]*mp[temp[i-1]] ;
            }
        }
        return dp[m] ; 
    }
};