#include <bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/trapping-rain-water/
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        int res = 0 ;
        int l = 0, r = n-1 ;
        int maxleft = height[l] ;
        int maxright = height[r] ;

        while(l < r){
            if(maxleft <= maxright){
                l++ ;
                maxleft = max(maxleft, height[l]) ;
                if(maxleft - height[l] > 0){
                    res += maxleft - height[l] ;
                }
            }
            else{
                r-- ;
                maxright = max(maxright, height[r]) ;
                if(maxright - height[r] > 0){
                    res += maxright - height[r] ;
                }
            }
        }
        // vector<int> maxleft(n, 0) ;
        // vector<int> maxright(n, 0) ;
        // maxleft[0] = 0 ;
        // for(int i = 1 ; i < n ; i++){
        //     maxleft[i] = max(maxleft[i-1], height[i-1]) ;
        // }
        // maxright[n-1] = 0 ;
        // for(int i = n-2 ; i >= 0 ; i--){
        //     maxright[i] = max(maxright[i+1], height[i+1]) ;
        // }

        // int res = 0 ;
        // int currmin ;
        // for(int i = 0 ; i < n ; i++){
        //     currmin = min(maxleft[i], maxright[i]) ;
        //     if(currmin - height[i] > 0){
        //         res = res + currmin - height[i] ;
        //     }
        // }
        return res ; 
    }
};

/*
we can do either ways so basically we are taking the maxleft until that height and also maxright after height taking the min of those to withstand
the trapped water between them that we add it if currmin - height[i] < 0 no water thats what we are doing over there 

l can not be euqal just see the logic you will get an idea  
*/