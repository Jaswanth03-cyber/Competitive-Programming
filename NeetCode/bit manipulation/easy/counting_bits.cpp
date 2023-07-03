#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/counting-bits/
*/

class Solution {
public:
    int hammingWeight(int n) {
        int temp = n ; 
        int ans = 0 ;
        while((temp != 1) && (temp != 0)){
            if(temp%2 == 1){
                ans++ ;
            }
            temp = temp/2 ;
        }
        if(temp == 1){
            ans++ ;
        }
        return ans ;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0) ;
        for(int i = 1 ; i <= n ; i++){
            ans[i] = hammingWeight(i) ;
        } 
        return ans ;   
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    Solution ans ;
    vector<int> result = ans.countBits(n) ;

    for(int i = 0 ; i <= n ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}