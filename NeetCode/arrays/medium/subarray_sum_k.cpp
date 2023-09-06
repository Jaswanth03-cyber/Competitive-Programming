#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/subarray-sum-equals-k/description/
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int count = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == k) {
                count++;
            }
            // this is because until now if somewhere at j < i if we have value sum - k then from j to value will be k so adding that
            // here this also has every case even when i = j + 1 so we need not add mp[nums[i]]++ explicitly.
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            // we have incremented here because if sum = k/2 then in count += mp[sum-k] we count one extra 
            mp[sum]++;
        }
        return count;      
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int k = 0 ;
    cin>>n>>k ;
    vector<int> arr(n, 0) ;
    for(int i  = 0 ; i < n; i++){
        cin>>arr[i] ;
    }
    Solution ans ;
    int res = ans.subarraySum(arr, k) ;
    cout<<res<<endl ;
    return 0 ;
}