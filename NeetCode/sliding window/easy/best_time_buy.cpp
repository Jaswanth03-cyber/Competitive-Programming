#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

/*
So as the brute force is that going through i = 0 ; i < n ; i++ and j = i+1 ; j < n ; j++ so now we have to optimise 
as if we see the constraints we have to either solve it in NLogN or N 

so if we see from a day we have to find maximum from the next days so that our profit will be maximized 
sliding window as we have to solve for the first window here first window will be starting from 0 to n-1  
so keep all the elements from 0 to n-1 in a map and now for 0 to n-1 prices we have to remove it first and take the maximum from 
the remaining days so mp.end()-- helps in finding that as there can repeated values we are maintaining a frequence or else we can just use
a set.
so here first window is from 0 to n-1 next will be from 1 to n-1, next will be from 2 to n-1 and so on...

our approach is sliding window so in sliding window we have to solve for the first window.
*/
class Solution{
public:
    int maxProfit(vector<int>& prices) {
        map<int, int> mp ;
        int ans = INT_MIN ;
        int n = prices.size() ;
        for(int i = 0 ; i < n ; i++){
            mp[prices[i]]++ ;
        }
        for(int i = 0 ; i < n -1 ; i++){
            if(mp[prices[i]] > 1){
                mp[prices[i]]-- ;
            }
            else{
                mp.erase(mp.find(prices[i])) ;
            }
            auto it = mp.end() ;
            it-- ;
            ans = max(ans, it->first - prices[i]) ;
        }
        if(ans < 0){
            ans = 0 ;
        }
        return ans ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ; 
    cin>>n ;
    vector<int> prices(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>prices[i] ;
    }
    Solution ans ;
    int result = ans.maxProfit(prices) ;
    cout<<result<<endl ;
    return 0 ;
}