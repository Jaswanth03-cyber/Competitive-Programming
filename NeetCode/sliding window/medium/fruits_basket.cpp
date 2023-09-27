#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/fruit-into-baskets/
*/

/*
adding the elements to the map now until the size of the map is <= 2 we add elements and take the maximum if in case size is > 2
now the left pointer where it is that subarray is invalid when it ends at that index i where size > 2 so until size in the map is again 2 we remove 
the elements and increase the left pointer till where again we get a valid subarray such that in that subarray we just have two types of ellments
while reducing the count do not forget to reduce the total as we are removing it and also if a type count becomes 0 then remove it that should not be
in the map as it effects the size. and also do l++.
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp ;
        int n = fruits.size() ;
        int ans = 0 ;
        int l = 0 ;
        int total = 0 ;
        int size = 0 ;
        for(int i = 0 ; i < n ; i++){
            mp[fruits[i]]++ ;
            total++ ;
            size = mp.size() ;
            while(size > 2){
                int type = fruits[l] ;
                mp[type]-- ;
                total = total - 1 ;
                l++ ;
                if(mp[type] == 0) {
                    mp.erase(mp.find(type)) ;
                }
                size = mp.size() ;
            }
            ans = max(ans, total) ;
        } 
        return ans ; 
    }
};