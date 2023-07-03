#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map< int, int > hash;
        int count = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == k) {
                count++;
            }
            if (hash.find(sum - k) != hash.end()) {
                count += hash[sum - k];
            }
            hash[sum]++;
        }
        return count;      
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0; 
    cin>>n ;
    int k = 0;
    cin>>k ;
    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }
    Solution ans ;
    int result = ans.subarraySum(nums, k) ;
    cout<<result<<endl ;
    return 0 ;
}