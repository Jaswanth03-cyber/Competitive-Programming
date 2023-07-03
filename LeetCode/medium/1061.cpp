#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char, set<char>> mp ;
        set<char> st ;

        for(char i = 'a' ; i <= 'z' ; i++){
            st.insert(i) ;
            mp.insert({i, st}) ;
            st.clear() ;
        }
        for(int i = 0 ; i < s1.size() ; i++){
            mp.find(s1[i])->second.insert(s2[i]) ;
            mp.find(s2[i])->second.insert(s1[i]) ;
        } 

        string ans = "" ;   
        char temp ;
        for(int i = 0 ; i < baseStr.size() ; i++){
            temp = *mp.find(baseStr[i])->second.begin() ;
            ans = ans + temp ;
        }
        return ans ; 
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}