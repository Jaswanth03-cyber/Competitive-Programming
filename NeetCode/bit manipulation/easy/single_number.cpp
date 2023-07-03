#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/single-number/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.count(nums[i]) == 0){
                mp.insert({nums[i],1}) ;
            }
            else{
                mp.find(nums[i])->second++ ;
            }
        }   
        int ans = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(it->second != 2){
                ans = it->first ;
                break ;
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

    vector<int> nums(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int result = ans.singleNumber(nums) ;

    cout<<result<<endl ;
    return 0 ;
}