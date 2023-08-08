#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp ;
        int size = nums.size() ;
        for(int i = 0 ; i < size ; i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]]++ ;
            }
            else{
                mp.insert({nums[i], 1}) ;
            }
        }    
        int i = 0 ; 
        int count = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(it->second >= 2){
                nums[i] = it->first ;
                nums[++i] = it->first ;
                i++ ;
                count = count + 2 ;
            }
            else{
                nums[i++] = it->first ;
                count++ ;
            }
        }
        return count ; 

    }
};