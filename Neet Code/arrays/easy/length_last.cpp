#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/length-of-last-word/
*/

class Solution {
public:
    int lengthOfLastWord(string s) {

        stack<char> st ;
        int n = s.size() ;
        int j = -1 ;
        for(int i = n -1 ; i >=0 ; i--){
            if((j == 1) && (st.size() != 0)){
                break ;
            }
            else if(s[i] == ' '){
                j = 1 ;
            }
            else{
                j = 0 ;
                st.push(s[i]) ;
            }
        }    

        int ans = st.size() ;
        return ans ;   
    }
};



int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s ;
    cin>>s ;

    Solution ans ;
    int result = ans.lengthOfLastWord(s) ;
    cout<<result<<endl ;

    return 0 ;
}