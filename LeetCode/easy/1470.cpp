#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n, 0) ;
        int j = 0 ;
        for(int i = 0 ; i < 2*n ; i = i + 2){
            ans[i] = nums[j] ;
            ans[i+1] = nums[j+n] ;
            j++ ;
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

    for(int i = 0 ; i < n  ; i++){
        cin>>nums[i] ;
    }

    Solution ans ; 
    vector<int> result = ans.shuffle(nums, n) ;

    for(int i = 0 ; i < result.size(); i++){
        cout<<result[i]<<endl ;
    }
    return 0 ;
}