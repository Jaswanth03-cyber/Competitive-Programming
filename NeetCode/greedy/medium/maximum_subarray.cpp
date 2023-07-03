#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = -1e5 ;
        int maximum_ending_here = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            maximum_ending_here = maximum_ending_here + nums[i] ;
            if(max_so_far < maximum_ending_here){
                max_so_far = maximum_ending_here ;
            }
            if(maximum_ending_here < 0){
                maximum_ending_here = 0 ;
            }
        }  
        return max_so_far ;  
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    vector<int> nums(n,0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }
    Solution ans ;
    int result = ans.maxSubArray(nums) ;
    cout<<result<<endl ;
    return 0 ;

}