#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/sort-colors/
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> freq ;
        freq.insert({0,0}) ;
        freq.insert({1,0}) ;
        freq.insert({2,0}) ;   

        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            auto it = freq.find(nums[i]) ;
            it->second++ ;
        } 
        int a = freq[0] ;
        int b = freq[1] ;
        int c = freq[2] ;

        for(int i = 0 ; i < n ; i++){
            if((i >= 0) && (i < a)){
                nums[i] = 0 ;
            }
            else if((i >= a) && (i < a+b)){
                nums[i] = 1 ;
            }
            else{
                nums[i] = 2 ;
            }
        }  
        return ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    vector<int> nums(n, 0) ;

    for(int i =0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    ans.sortColors(nums) ;

    for(unsigned int i = 0 ; i < nums.size() ; i++){
        cout<<nums[i]<<" " ;
    }
    cout<<endl ;

    return 0 ;
}