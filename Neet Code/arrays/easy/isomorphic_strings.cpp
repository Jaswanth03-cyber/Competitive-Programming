#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/isomorphic-strings/
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool ans = true ;
        if(s.size() != t.size()){
            ans = false ; 
            return ans ;
        } 

        map<char, char> check ;

        for(size_t i = 0 ; i < s.size() ; i++){
            if(check.count(s[i]) == 0){
                check.insert({s[i], t[i]}) ;
            }
            else{
                auto it = check.find(s[i]) ;
                if(t[i] != it->second){
                    ans = false ;
                    break ;
                }
            }
        }  
        set<char> check2 ;
        for(auto it = check.begin() ; it != check.end() ; it++){
            if(check2.count(it->second) == 0){
                check2.insert(it->second) ;
            }
            else{
                ans = false ;
                break ;
            }
        } 
        return ans ;  
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    string s = "";
    string t = "" ;

    cin>>s ;
    cin>>t ;

    Solution ans ;
    bool result = ans.isIsomorphic(s,t) ;
    cout<<result<<endl ;
    return 0 ;
}