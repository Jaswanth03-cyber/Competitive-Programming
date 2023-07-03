#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/majority-element/
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        size_t n = nums.size() ;    
        map<int, int> freq ;

        for(size_t i = 0 ; i < n ; i++){
            if(freq.count(nums[i]) == 0){
                freq.insert({nums[i], 0}) ;
            }
            else{
                auto it = freq.find(nums[i]) ;
                it->second++ ;
            }
        }

        priority_queue<pair<int, int>> pq ;
        for(auto it = freq.begin(); it != freq.end() ; it++){
            pq.push(make_pair(it->second, it->first)) ;
        }

        return pq.top().second ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<int> nums(n, 0) ;
    for(size_t i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ; 
    int result = ans.majorityElement(nums) ;
    cout<<result<<endl ;

    return 0 ;
}