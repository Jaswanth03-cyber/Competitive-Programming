#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/binary-search/
*/

class Solution {
public:
int binarysearch(vector<int> &arr, int const begin, int const end, int const x){
    if(end >= begin){
        int mid = begin + (end - begin)/2 ;
        if(arr[mid] == x){
            return mid ;
        }
        if(x > arr[mid]){
            return binarysearch(arr, mid +1, end, x) ;
        }
        return binarysearch(arr, begin, mid -1 , x) ;
    }
    return -1 ;
}
    int search(vector<int>& nums, int target) {
        int ans = binarysearch(nums, 0, nums.size() - 1, target) ;
        return ans ;  
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
    int target = 0 ;
    cin>>target ;
    Solution ans ;
    int result = ans.search(nums, target) ;
    cout<<result<<endl ;
    return 0 ;
}