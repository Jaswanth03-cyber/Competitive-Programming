#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/

class Solution {
public:
    vector<int> z_function(string s){
        int n = s.size() ;

        vector<int> z(n,0) ;
        int l = 0 ; 
        int r = 0 ; 
        for(int i = 1 ; i < n ; i++){

            if(i <= r){
                z[i] = min(z[i - l], r - i + 1) ;
            }
            while((i + z[i] < n) && (s[z[i]] == s[i + z[i]])){
                z[i]++ ;
            }
            if(i + z[i] - 1 > r){
                l = i ; 
                r = i + z[i] - 1 ;
            }
        }
        return z ;
    }

    int strStr(string haystack, string needle) {    
        string total = needle + "$" + haystack ; 
        vector<int> z = z_function(total) ;
        int result ;
        for(unsigned int i = needle.size() + 1 ; i < total.size() ; i++){
            if(z[i] == needle.size()){
                result = i - needle.size() - 1 ;   
                break ; 
            }
        }
        return result ;   
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string pattern = "";
    cin>>pattern ;

    string text = "";
    cin>>text ;

    Solution ans ;
    int result = 0 ;
    result = ans.strStr(text, pattern) ;

    cout<<result<<endl ;

    return 0 ;
}