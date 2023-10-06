#include <bits/stdc++.h>
using namespace std ;

/*
so this is slightly modified problem of longest increasing subsequence just see the basic implementaion of longest increasing subsequence 
so this is basically the same but here we have to maintain a count vector where count[i] denotes number of subsequences of length dp[i] starting at
index i.

so if we see the code if there nums[i] < nums[j] then then we increase our longest subsequence so we are checking if dp[i] < dp[j] + 1 
and updating the count according to it if in case dp[i] is same as dp[j]+1 then count[i] should be increased by that count[j] because from j there 
are count[j] longest subsequences that are possible so thats why sequences that start at i and are longest we have to add count[j] ones also if 
dp[i] = dp[j]+1 if not just make that count[i] as count[j]

for example 
1 3 5 4 7

4 3 2 2 1 dp
2 2 1 1 1 count 
take like a decision tree you will get an idea.

at last if maximum subsequneces length are more do not forget to add all of them to get total number of longest subseqeunces 
for ex 
2 2 2 2 2

1 1 1 1 1 dp
1 1 1 1 1 count

5 4 7 

2 2 1 dp
1 1 1 count

see longest increasing subsequence need not always start at index 0 so always longest increasing subseqeunce will not be dp[0] we have to take the 
maximum value.

for ex 
10 3 5 4 7 

1 3 2 2 1 dp
1 2 1 1 1 count

if nums[i] >= nums[j] need not change anything for dp[i] and count[i] and also initialy before computations all values in dp and count are 1 as
1 is the longest and number of subsequences is 1.
*/


/*
here dp[i] denotes longest subsequence that is starting at index i. we can even do the reverse number of subsequences that are ending at index i.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n, 1) ;
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = i+1 ; j < n ; j++){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i], dp[j]+1) ;
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end()) ;
        return ans ;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n, 1) ; 
        vector<int> count(n, 1) ;
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = i + 1 ; j < n ; j++){
                if(nums[i] < nums[j]){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j] + 1 ;
                        count[i] = count[j] ;
                    }
                    else if(dp[i] == dp[j]+1){
                        count[i] = count[i] + count[j] ;
                    }
                }
            }
        }
        int maxlength = *max_element(dp.begin(), dp.end()) ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(dp[i] == maxlength){
                ans = ans + count[i] ;
            }
        }
        return ans ;
    }
};