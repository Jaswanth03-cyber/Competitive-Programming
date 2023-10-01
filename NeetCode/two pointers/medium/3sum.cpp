#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/3sum/description/
*/

/*
basically taking a target and in the sorted loop checking if we have a sum of values such that it is equal to -target note the array is
sorted and also note he asked for values not for indices and also if found target do not break there can be a chance that we can have another 
pair in that while itself so check until l  >= r we are checking till l < r only because arr is sorted. so to avoid duplicates we are checking before
itself if i >0 arr[i].first is same as arr[i-1].first and also inside the while when a target has been found we decrease the r until r and  r+1 elements 
are not same to avoid duplicates or we can increment the l until l and l-1 are not same and also check that l < r.

In the third solution as we are checking in a set so if we find a target just l++ and r-- will be sufficient rest set will take care.
*/

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        vector<pair<int, int>> arr(n, {0,0}) ; 
        for(int i = 0 ; i < n ; i++){
            arr[i] = {nums[i], i} ;
        }
        sort(arr.begin(), arr.end()) ;
        vector<vector<int>> ans ;
        for(int i = 0 ; i < n ; i++){
            int target = arr[i].first ;
            if( i > 0 && arr[i].first == arr[i-1].first){
                continue ;
            }
            int l = i+1, r = n-1 ;
            vector<int> temp ;
            while(l < r){
                if(arr[l].first + arr[r].first == -target){
                    temp = {nums[arr[i].second], nums[arr[l].second], nums[arr[r].second]} ;
                    ans.push_back(temp) ;             
                    r-- ;
                    while(arr[r].first == arr[r+1].first && l < r){
                        r-- ;
                    }   
                }
                else if(arr[l].first + arr[r].first > -target){
                    r-- ;
                }
                else{
                    l++ ;
                }
            }
        }
        return ans ; 
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        vector<pair<int, int>> arr(n, {0,0}) ; 
        for(int i = 0 ; i < n ; i++){
            arr[i] = {nums[i], i} ;
        }
        sort(arr.begin(), arr.end()) ;
        vector<vector<int>> ans ;
        for(int i = 0 ; i < n ; i++){
            int target = arr[i].first ;
            if( i > 0 && arr[i].first == arr[i-1].first){
                continue ;
            }
            int l = i+1, r = n-1 ;
            vector<int> temp ;
            while(l < r){
                if(arr[l].first + arr[r].first == -target){
                    temp = {nums[arr[i].second], nums[arr[l].second], nums[arr[r].second]} ;
                    ans.push_back(temp) ;             
                    l++ ;
                    while(arr[l].first == arr[l-1].first && l < r){
                        l++ ;
                    }
                     
                }
                else if(arr[l].first + arr[r].first > -target){
                    r-- ;
                }
                else{
                    l++ ;
                }
            }
        }
        return ans ; 
    }
};

class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        vector<pair<int, int>> arr(n, {0,0}) ; 
        for(int i = 0 ; i < n ; i++){
            arr[i] = {nums[i], i} ;
        }
        sort(arr.begin(), arr.end()) ;
        vector<vector<int>> ans ;
        set<pair<int, int>> st ;
        for(int i = 0 ; i < n ; i++){
            int target = arr[i].first ;
            int l = i+1, r = n-1 ;
            vector<int> temp ;
            while(l < r){
                if(arr[l].first + arr[r].first == -target){
                    if(st.find({arr[l].first, arr[r].first}) == st.end() && st.find({arr[r].first, arr[l].first}) == st.end()){
                        temp = {nums[arr[i].second], nums[arr[l].second], nums[arr[r].second]} ;
                        ans.push_back(temp) ;
                        st.insert({arr[l].first, arr[r].first}) ;
                    }
                    l++ ;
                    r-- ;
                }
                else if(arr[l].first + arr[r].first > -target){
                    r-- ;
                }
                else{
                    l++ ;
                }
            }
        }
        return ans ; 
    }
};