#include <bits/stdc++.h>
using namespace std ;

/*
Here subarray in the sense non emepty contigous elements of an array so it can never be zero 
*/

/*
Same way we can do minimum also 
*/
int approach(vector<int> &nums){
        int max_so_far = nums[0] ;
        int maximum = nums[0] ;
        int n = nums.size() ;
        int min_so_far = nums[0] ;
        int minimum = nums[0] ;
/*
this is just basically checking at which index maximum sub array sum starts 
initially we take maximum sum sub array starts at index 0 so we set maximum values and maximum so far to nums[0] now from 
index 1 to n-1 we check whether our sub array sum starts from 0 itself or have to change it, we can see we add nums[1] to it 
so if nums[0] + nums[1] > nums[1] we can start our sub array from 0 only or else we need to change it to index 1.
our maximum sub array sum starts from here.
*/
        for(int i = 1 ; i < n ; i++){
            maximum = max(maximum + nums[i], nums[i]) ;
            max_so_far = max(max_so_far, maximum) ;

            minimum = min(minimum + nums[i], nums[i]) ;
            min_so_far = min(min_so_far, minimum) ;
        }
        return max_so_far ;
}
int maxsubarraysum(vector<int> &arr){
    int n = arr.size() ;
    int max_ending_here = 0 ;
    int ans = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        max_ending_here = max_ending_here + arr[i] ;
        if(ans < max_ending_here){
            ans = max_ending_here ;
        }
        if(max_ending_here < 0){
            max_ending_here = 0 ;
        }
        return ans ;
    }
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    vector<int> arr(n, 0) ;
    for(int i = 0 ; i , n ; i++){
        cin>>arr[i] ;
    }

    int ans = maxsubarraysum(arr) ;

    return 0 ;
}