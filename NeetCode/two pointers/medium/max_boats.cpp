#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/boats-to-save-people/
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()) ;
        int n = people.size() ;
        int ans = 0 ;
        int l = 0 ;
        int r = n-1 ;

        while(l <= r){
            if(people[l] + people[r] <= limit){
                ans++ ;
                l++ ;
                r-- ;
            }
            else{
                ans++ ;
                r-- ;
            }
        }
        return ans ;
    }
};

/*
sort from the back pair them if first case both are used if not take last as l is small it can be paired may be 
*/