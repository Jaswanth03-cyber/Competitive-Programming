#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/house-robber-ii/
*/
/*
Logic lets take 
at in index i if robbing is done then at i-2 only we can rob so add nums[i] and dp[i-2] max we can rob at i-2 and if not robbing at index i then 
dp[i-1] this is the maximum possible till index i take that.
when n = 1 obv nums[0] is the answer
when n = 2, so he can take any one of those which is maximum as adjacent we should not rob
now when n >= 3 
here dp[i] denotes maximum you can rob until that index 
we know at an index he can rob it or not rob it 
if i-1 is robbed then i should not be robbed 
[1,2,3,1]
now dp[0] = 1 
dp[1] = 2 here is one is robbed 
so dp[2] is two possibilites only one is robbed or 0 is robbed and we can rob at house 2 also so add those take maximum
dp[2] = 4 
dp[3] 
dp[2] and dp[1] + nums[3] now 

as circular its two cases take from 1 to n-1 or 2 to n it reduces to house robber problem take maximum of these two.
I have just checked 1 to n-1 did not go from the backside 2 to n.
*/
class Solution {
public:
    int func(vector<int> &nums){
        int n = nums.size() ;
        if(n == 1){
            return nums[0] ;
        } 
        vector<int> dp(n, INT_MAX) ;
        dp[0] = nums[0] ;
        dp[1] = max(nums[0], nums[1]) ;
        for(int i = 2 ; i < n ; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]) ;
        }
        return dp[n-1] ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n==1){
            return nums[0] ;
        }
        vector<int> arr1(nums.begin(), nums.begin() + n-1) ;
        vector<int> arr2(nums.begin()+1,nums.end()) ;
        int one = func(arr1) ;
        int two = func(arr2) ;
        return max(one, two) ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    vector<int> coins(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i] ;
    }
    Solution ans ;
    int res = ans.rob(coins) ;
    cout<<res<<endl ;
    return 0 ;
}