#include<bits/stdc++.h>
using namespace std ;



class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = 2*nums.size() ;
        vector<int> ans(size, 0) ;

        for(int i = 0 ; i < size ; i++){
            if(i >= size/2){
                ans[i] = nums[i-size/2] ;
            }
            else{
                ans[i] = nums[i] ;
            }
        } 
        return ans ;   
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    vector<int> nums(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    vector<int> result = ans.getConcatenation(nums) ;

    for(int i = 0 ; i < 2*n ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}