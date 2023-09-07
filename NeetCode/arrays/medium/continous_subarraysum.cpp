#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/continuous-subarray-sum/
*/

/*
Logic is same as before after calculating the sum we are taking modulo checking now if we have any mp[sum] such that i - mp[sum] > 1 as 
adding elements between these will be divisible by k and as given in the question we are checking if length is greater than 1 or not 
if not greater than one also no need to update mp[sum] in first if condition as if so sum again occurs then length might increase if we keep the 
min indxe where sum occurred 
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
            sum %= k;
            if(mp.find(sum) != mp.end()){
                if(i - mp[sum] > 1) return true;
            }else{
                mp[sum] = i;
            }
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }
    int k = 0 ;
    cin>>k ;

    Solution ans ;
    bool res = ans.checkSubarraySum(nums, k) ;

    cout<<res<<endl ;
    return 0 ;
}