#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/valid-anagram/
*/

class Solution {
public:
    void freq(string &s, map<char, int> &mp){
        for(int i = 0 ; i < s.size() ; i++){
            if(mp.count(s[i]) == 0){
                mp.insert({s[i],1}) ;
            }
            else{
                mp.find(s[i])->second++ ;
            }
        }
        return ;
    }
    bool isAnagram(string s, string t){
        map<char, int> mp1 ;
        map<char, int> mp2 ; 

        freq(s, mp1) ;
        freq(t, mp2) ;

        if(mp1.size() != mp2.size()){
            return false ;
        }
        auto i = mp2.begin() ;
        for(auto it = mp1.begin() ; it != mp1.end() ; it++){
            if((it->first != i->first) || (it->second != i->second)){
                return false ;
            }
            i++ ;
        } 
        return true ;    
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s ;
    string t ;

    cin>>s ;
    cin>>t ;

    Solution ans ;

    bool result = ans.isAnagram(s, t) ;
    cout<<result<<endl ;
    return 0 ;
}