#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/maximum-ice-cream-bars/
*/


/*
What I have done is that I have sorted the given input using priority queue and then now by looping through the queue I have reduced the 
number of coins we have as I have taken a greedy choice that choosing minimum cost ice cream every time which increases the number of ice creams
do not forget to check whether priority queue becomes empty or not as even though it becomes empty next value will be some random value and that
value can even be less than the number of coins we have at that time 
*/


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> pq ;
        for(int i = 0 ; i < costs.size() ; i++){
            pq.push(costs[i]) ;
        }  

        int temp = coins ;
        int ans = 0 ;
        while((!pq.empty()) && (pq.top() <= temp)){
            temp = temp - pq.top() ;
            pq.pop() ;
            ans++ ;
        }
        return ans ; 
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<int> costs(n,0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>costs[i] ;
    }
    int coins = 0 ;
    cin>>coins ;

    Solution ans ;
    int result = ans.maxIceCream(costs, coins) ;
    cout<<result<<endl ;
    return 0 ;
}