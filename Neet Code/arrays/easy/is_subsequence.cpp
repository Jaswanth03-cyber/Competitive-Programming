#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/is-subsequence/
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int j = 0 ; 
        int index = 0 ;   
        int i = 0 ;
        while(i < t.size()){
            if(s[j] == t[i]){
                j++ ;
            }
            i++ ;
        }
        if(j != s.size()){
            return false ;
        }
        else{
            return true ;
        }
    }    
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s = "" ;
    string t = "" ;

    cin>>s ;
    cin>>t ;

    Solution ans ;
    bool result = ans.isSubsequence(s,t) ;
    cout<<result<<endl ;

    return 0 ;
}