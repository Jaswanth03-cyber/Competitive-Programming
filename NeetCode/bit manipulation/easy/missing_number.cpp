#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/missing-number/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        int ans = 0 ;
        for(int i = 0 ; i < 1e4 ; i++){
            if(i >= nums.size()){
                ans = nums[i-1] + 1 ;
                break ;
            }
            else{
                if(i != nums[i]){
                    ans = i ;
                    break ;
                }
            }
        } 
        return ans ;   
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    vector<int> nums(n+1,0) ;
    for(int i = 0 ; i <= n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int result = ans.missingNumber(nums) ;

    cout<<result<<endl ;

    return 0 ;
}