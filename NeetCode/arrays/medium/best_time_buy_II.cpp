#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

/*
Its same see lets say a b c are consecutive days and a < b < c 

so buy on a, sell on b again buy on b and sell on c 
total ptofit 
b - a + c - b == c - a 

so the logic and greedy step is that if prices[i] < prices[i+1] just buy on ith day and sell on i+1th day 
if not profit is made zero.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size() ;
        // int ans = 0 ;
        // for(int i = 1 ; i < n ; i++){
        //     if(prices[i] > prices[i-1]){
        //         ans = ans + prices[i] - prices[i-1] ;
        //     }
        // } 
        // return ans ; 

        int n= prices.size() ;
        int ans = 0 ;
        int Min = prices[0] ;
        int profit = 0 ;
        for(int i = 1 ; i < n ; i++){
            if(prices[i] < Min){
                Min = prices[i] ;
            }
            else if(prices[i] > Min){
                profit = profit + prices[i] - Min ;
                Min = prices[i] ; // now making this as the min price, if so next time min occurs that will be the next min. see the examples given
            }
        }
        return profit ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    vector<int> prices(n, 0) ;
    for(int i = 0 ;i < n ; i++){
        cin>>prices[i] ;
    }
    Solution ans ;
    int res = ans.maxProfit(prices) ;
    cout<<res<<endl ;
    return 0 ;
}