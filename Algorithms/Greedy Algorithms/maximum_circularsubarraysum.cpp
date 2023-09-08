#include <bits/stdc++.h>
using namespace std ;

/*
Logic is simple as here it is circular not only maximum sub array sum in a linear array we will have another case 
lets say we are having min possible sum from i to j 

0 1 2 3 ... i ... j j+1 ... n - 1

now as it is ciruclar it can be the case that 
j+1 ... n-1, 0... i this sum can also result in maximum possible sum so we are considering that also.

when sum == minimum in the sense all the values in the array are negative so in that case maximum sub array sum that is here maximum will contain
the maximum element of the given array < 0 and sum - minimum = 0 so in that case our ans will be zero which can not be as sub array is non empty 
if it is given that sub array can be empyt then ans can be zero 
*/
int circular(vector<int> &nums){
        int max_so_far = nums[0] ;
        int maximum = nums[0] ;
        int n = nums.size() ;
        int min_so_far = nums[0] ;
        int minimum = nums[0] ;
        int sum = nums[0] ;
        for(int i = 1 ; i < n ; i++){
            max_so_far = max(nums[i] + max_so_far, nums[i]) ;
            maximum = max(maximum, max_so_far) ;

            min_so_far = min(min_so_far + nums[i], nums[i]) ;
            minimum = min(minimum, min_so_far) ;

            sum = sum + nums[i] ;
        }
        if(sum == minimum){
            ans = maximum ;
        }
        else{
            ans = max(maxium, sum - minimum) ;
        }
        return ans ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    int ans = circular(nums) ;
    cout<<ans<<endl ;
}