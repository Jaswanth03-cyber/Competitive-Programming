#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0 ; 
        }
        if(s.length() == 1){
            return 1 ; 
        }
        int ans = -INT_MAX ;
        set<char> st ;
        int size ; 
        for(int i = 0 ; i < s.length() ; i++){
            for(int j = i ; j < s.length() ; j++){
                if(st.count(s[j]) == 1){
                    size = st.size() ;
                    ans = max(ans, size) ;
                    st.clear() ;
                    break ;
                }
                else{
                    st.insert(s[j]) ;
                }
            }
        }
        return ans ;      
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s = "" ;
    cin>>s ;

    Solution ans ;
    int result = ans.lengthOfLongestSubstring(s) ;
    cout<<result<<endl ;
    return 0 ;
}