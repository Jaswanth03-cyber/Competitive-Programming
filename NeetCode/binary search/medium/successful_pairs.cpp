#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
*/
/*
Two ways both are same 
in first one take the lower bound of success/spells[i] take the ceil function as that is the integer required such that spells[i]*integer >= success
so we get the index lower_bound as we can have == of success so thats why lower bound not upper bound so value is m - index

similarly second one is same as above we will find the minimum index i in the sorted array of potions where potions[i]*value >= success 
so final one is m - i, so we have to update the count = m - mid until l <= r or potions[mid]*value < success be carefull with long long comparisions.
better convert all to long long.
*/
class Solution {
public:
    int binarysearch(vector<int> &potions, long long success, long long value){
        int l = 0 ;
        int m = potions.size()  ;
        int r = m - 1 ;
        int count = 0 ;
        long long product ;
        long long one ;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            one = potions[mid] ;
            product = one*value ;
            if(product >= success){
                count = m - mid ;
                r = mid - 1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return count ;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // long int n = spells.size() ;
        // int m = potions.size() ;
        // sort(potions.begin(), potions.end()) ;
        // vector<int> ans(n, 0) ;
        // int index = 0 ;
        // long int value = 0 ;
        // double num = success ;
        // double den = 0 ; 
        // for(int i = 0 ; i < n ; i++){
        //     den = spells[i] ;
        //     // cout<<success/spells[i]<<" " ;
        //     value = ceil(num/den) ;
        //     // cout<<value<<endl ;
        //     index = lower_bound(potions.begin(), potions.end(),value) - potions.begin() ; // binary search is done over here
        //     ans[i] = m - index ;
        // }
        // return ans ;
        int n = spells.size() ;
        int m = potions.size() ;
        vector<int> ans(n, 0) ;
        sort(potions.begin(), potions.end()) ;
        int count = 0 ;
        long long value ;
        for(int i = 0 ; i < n ; i++){
            value = spells[i] ;
            count = binarysearch(potions, success, value) ;
            ans[i] = count ;
        }
        return ans ; 
    }
};