#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/last-stone-weight/
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq ;
        for(int i = 0 ; i < stones.size() ; i++){
            pq.push(stones[i]) ;
        }
        int a = 0 ;
        int b= 0 ;
        if(pq.size() == 0){
            return 0 ;
        }      
        else if(pq.size() == 1){
            return pq.top() ;
        }
        else{
            while(pq.size() > 1){
                a = pq.top() ;
                pq.pop() ;
                b = pq.top() ;
                pq.pop() ;
                if(a==b){
                    continue ;
                }
                else{
                    pq.push(a-b) ;
                }
            }
        }
        if(pq.size() == 0){
            return 0 ;
        }
        return pq.top() ;
    }
};
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<int> stone(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>stone[i] ;
    }

    Solution ans ; 

    int result = ans.lastStoneWeight(stone) ;
    cout<<result<<endl ;

    return 0 ;
}