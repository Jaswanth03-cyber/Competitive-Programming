#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/hand-of-straights/
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size() ;
        vector<bool> visited(n, false) ;
        if(n%groupSize != 0){
            return false ;
        }
        sort(hand.begin(), hand.end()) ;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                int j = i+1 ;
                int count = 1 ;
                int temp = hand[i] ;
                while(j < n && count != groupSize){
                    if(!visited[j] && temp+1 == hand[j]){
                        count++ ;
                        temp = hand[j] ;
                        visited[j] = true ;
                    }
                    j++ ;
                }
                visited[i] = true ;
                if(count != groupSize){
                    return false ;
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                return false ;
            }
        }
        return true ;
    }
};

/*
logic
so if the size of the array is not a multiple of groupsize return false else now first sort the array easy to check 
I have ben maintaining a visited boolean array which helps to take unselected number so if there is a unselected number there must be 
groupsize consecutive numbers along with so searching for groupsize consecutive numbers if present then continue if not return false after the while loop
carefull that count = 1 initially as we have to count hand[i] also and do not forget to make visited[i] true 

ans also sorting makes it faster even though without sorting also it can be done but worst case will be O(n^2) but after sorting O(nlogn)
*/