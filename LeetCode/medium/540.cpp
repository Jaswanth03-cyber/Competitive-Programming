#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> freq ;
        for(int i = 0 ; i < nums.size(); i++){
            if(freq.count(nums[i]) == 0){
                freq.insert({nums[i], 1}) ;
            }
            else{
                freq.find(nums[i])->second++ ;
            }
        }  
        int ans = 0 ;
        for(auto it = freq.begin() ; it != freq.end() ; it++){
            if(it->second == 1){
                ans = it->first ;
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
    int result = ans.singleNonDuplicate(nums) ;

    cout<<result<<endl ;
    return 0 ;
}