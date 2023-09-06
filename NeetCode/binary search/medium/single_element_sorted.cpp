#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/single-element-in-a-sorted-array/description/
*/

/*
Logic :

here if we take the middle element if it is at odd index, number of elements to the left and right of the middle element will be odd
as number of elements here we know size of nums will always be odd so we check previous element of mid and mid element if both are same 
then our element whose frequency is one will be on the side which has odd number of elements, so checking mid-1 and mid if both are same then 
our single frequency element will be in the right side otherwise left side. when l == r case occurs then that is the element, here as n is odd 
is so l == r then that will be the element which has odd frequency 

here the function which is true for first half and not true for second half is that, one half has even number of elements and also nums[i] == nums[i+1]
this will not be true from a particular point in the second half.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // map<int, int> freq ;
        // for(int i = 0 ; i < nums.size(); i++){
        //     if(freq.count(nums[i]) == 0){
        //         freq.insert({nums[i], 1}) ;
        //     }
        //     else{
        //         freq.find(nums[i])->second++ ;
        //     }
        // }  
        // int ans = 0 ;
        // for(auto it = freq.begin() ; it != freq.end() ; it++){
        //     if(it->second == 1){
        //         ans = it->first ;
        //     }
        // } 
        // return ans ;  

        int n = nums.size() ;
        int l = 0 ;
        int r = n -1 ;
        while(l < r){
            int mid = l + (r-l)/2 ;
            if(mid%2 == 1){
                mid-- ;
            }
            if(nums[mid] != nums[mid+1]){
                r = mid ;
            }
            else{
                l = mid + 2  ;
            }
        } 
        return nums[l] ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    vector<int> arr(n, 0) ;
    for(int i = 0; i < n ; i++){
        cin>>arr[i] ;
    }
    Solution ans ;
    int res = ans.singleNonDuplicate(arr) ;
    cout<<res<<endl ;
    return 0 ;
}