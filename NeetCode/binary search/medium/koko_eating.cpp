#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/koko-eating-bananas/
*/
/*
Logic 
the rate at which the monkey eats the bananas lets say be the maximum element of the array then time taken will be n size of the array
now for any value greater than the maximum value time will be n only so in our range of search this maximum value is the right one and minimum will 
be 1 we have to search in this now in this range [1, max] we have to do a binary search take a mid value if time taken for this is <= h then change the
right to mid-1 search in this, if not possible then change the l now search in this now among all possible we have to take the minimu value.
*/

class Solution {
public:
    bool check(int value, vector<int> &piles, int h){
      int n = piles.size() ;
      long long time = 0 ;
      for(int i = 0 ; i < n ; i++){
        if(piles[i]%value == 0){
          time = time + piles[i]/value ;
        }
        else{
          time = time + piles[i]/value + 1 ;
        }
      }
      if(time <= h){
        return true ;
      }
      return false ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      sort(piles.begin(), piles.end()) ;
      int large = *max_element(piles.begin(), piles.end()) ;
      int small = 1 ;
      int mid = 0 ;
      int ans = INT_MAX ;
      while(small <= large){
        mid = small + (large-small)/2 ;
        if(check(mid, piles, h)){
          ans = min(ans, mid) ;
          large = mid - 1 ; 
        }
        else{
          small = mid + 1 ;
        }
      }
      return ans ;
    }
};