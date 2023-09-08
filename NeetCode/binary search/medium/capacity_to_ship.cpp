#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

/*
Logic :- 
Here we have to search for the capacity which is minimum first point is that what is the search space ???

So lets modify the problem lets say we are only one day but having ships == given days so we need the minimum capacity of each ship such that
total given weights can be send in the given number of ships so thats why. 

we can see that minimum capacity required for each ship is maximum weight among all the given weights, as if we can not load that weight if capacity 
is less than that, and the maximum capacity will be total weights sum, so our capacity for each ship will be in this search range so as we got 
l and r what is the function that helps us to reduce the search space 

possible(capacity) we are taking a capacity lets assume each ship has that much capacity now for the given weights count number of ships required if
each ship capacity is given, now if the number of ships is greater than the given number of ships(days) we have to return false 

so if possible(mid) is true so then our search space is l to mid -1 or else mid +1 to r so if we binary search this we will get the minimum capacity 
required for each ship so that it can be done in given number of ships 

complexity will be O(nLogM) where M is the sum of weights as our search space is max(weights) to sum(weights) so LogM for binary search and n as possible 
will take O(n) time.
*/
class Solution {
public:
    bool possible(int capacity, vector<int> &weights, int days){
        int n = weights.size() ;
        int ships_count = 1 ; // ship count will be number of times we are using max_capacity as initially one ship will be there we are loading into it if it is done next one and so on
        int max_capacity = capacity ;
        for(int i = 0 ; i < n ; i++){
            if(max_capacity - weights[i] < 0){
                ships_count = ships_count + 1 ;
                max_capacity = capacity ;
            }
            max_capacity = max_capacity - weights[i] ;
        }
        bool ans = true ;
        if(ships_count > days){
            ans = false ;
        }
        return ans ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size() ;
        int l = INT_MIN, r = 0 ;     
        for(int i = 0 ; i < n ; i++){
            l = max(l, weights[i]) ;
            r = r + weights[i] ;
        }

        int mid = 0 ;
        int ans = r ;
        while(l <= r){
            mid = l + (r-l)/2 ;
            if(possible(mid, weights, days)){
                ans = min(ans, mid) ;
                r = mid - 1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0, days = 0 ;
    cin>>n>>days ;
    vector<int> weights(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>weights[i] ;
    }
    Solution ans ;
    int res = ans.shipWithinDays(weights, days) ;
    cout<<res<<endl ;
    return 0 ;
}