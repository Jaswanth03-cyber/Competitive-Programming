#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/stone-game/description/
*/
/*
Intitially you might think that taking the max every time we will en dup to the maximum sum but no it is not the case for example 
lets have 4 5 1 3 
now if we take 4 he takes 5 and now if we take 3 we will end up with 7 but there is another choice lets say we choose 3 he chooses 4 if we chosoe 5
then we will end up with 8 so 7 is not the maximum possible value

It is given that every player plays optimally which means both try to maximise their total value 
so lets say we are calculating maximum value for 
[i..j]    so either we can take ith element or jth element but we dont know what the remaining elements in the array from i+1 to j-1 
so as both players try to play optimally 
dp[i..j] = max(sum - dp[i+1...j], sum - dp[i...j-1]) where sum is the elements from i to j 
think logically lets say game is starting from array size 2   [a1, a2] first one end up taking max(a1, a2) lets say we have [a1,a2,a3]
so first one end up with the value = max(sum-max(a1,a2), sum-max(a2,a3)) which is nothing but the dp relation which we wrote 


so basically we calculate the dp table here we calculate for all i<=j as [i...j] first we compute all 2 size ones next we will calculate for size 3
and so on...
so when size = 2 and i is the starting index and ending index will be j = i+size-1 and maximum starting index can be n-size so also we maintain a 
prefix array for easy calculation and also for size 1 dp[i][i] is just the value of nums[i] 

so the recursion relation 
total = sum(i...j)
dp[i][j] = max(total - dp[i+1][j], total - dp[i][j-1]) 

after we calculate the maximum value 
we check if this max > totalsum - max 

do not write max > total/2 as given totalsum is odd small problem so better write this only.
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size() ;
        vector<int> prefix(n, 0) ;
        vector<vector<int>> dp(n, vector<int>(n, 0)) ;

        for(int i = 0 ; i < n ; i++){
            if(i != 0){
                prefix[i] = prefix[i-1] + piles[i] ;
            }
            else{
                prefix[i] = piles[i] ;
            }
            dp[i][i] = piles[i] ;
        }

        for(int size = 2 ; size <= n ; size++){
            for(int i = 0 ; i <= n-size ; i++){
                int total = prefix[i+size-1] - prefix[i] + piles[i] ;
                dp[i][i+size-1] = max(total - dp[i+1][i+size-1], total - dp[i][i+size-2]) ;
            }
        }

        int sum = accumulate(piles.begin(), piles.end(), 0) ;
        bool ans = true ;
        if(dp[0][n-1] < sum - dp[0][n-1]){
            ans = false ;
        }
        return ans ;
    }
};