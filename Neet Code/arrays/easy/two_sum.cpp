#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/two-sum/
*/

class Solution {
public:

    vector<int> index(vector<int> &nums, int target){
        vector<int> ans ; 
        for(size_t i = 0 ; i < nums.size() ; i++){
            if(ans.size() == 2){
                break ;
            }
            if(nums[i] == target){
                ans.push_back(i) ;
            }
        }
        return ans ;
    }
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans ;
        map<int, int> check ;
        map<int, int> freq ;
        for(size_t i = 0 ; i < nums.size() ; i++){
            if(check.count(nums[i]) == 0){
                check.insert({nums[i], i}) ;
                freq.insert({nums[i], 0}) ;
            }
            else{
                auto it = freq.find(nums[i]) ;
                it->second++ ;
            }
        } 
        // bool found = false ;
        for(auto it = check.begin() ; it != check.end() ; it++){

            int a = target - it->first ;

            if(a == it->first){
                if(freq.count(a) < 1){
                    continue ;
                }
                else{
                    ans = index(nums, a) ;
                    return ans ;
                }
            }
            if(check.count(a) == 1){
                // found = true ;
                ans.push_back(it->second) ;
                ans.push_back(check.find(a)->second ) ;
                return ans ;
            }
        }

        return ans ;
    }
};


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    int n ;
    cin>>n ;
    int target ;
    cin>>target  ;

    vector<int> nums ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    vector<int> result = ans.twoSum(nums, target) ;
    for(size_t i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;


    return 0 ;
}