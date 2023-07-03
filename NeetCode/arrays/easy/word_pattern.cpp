#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/word-pattern/
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        string temporary = "" ;
        char del = ' ' ;
        bool ans = true ;
        vector<string> arr ;
        for(size_t i = 0 ; i < s.size() ; i++){
            if(s[i] != del){
                temporary = temporary + s[i] ;
                if(i == s.size() - 1){
                    arr.push_back(temporary) ;
                }
            }
            else{
                arr.push_back(temporary) ;
                temporary = "" ;
            }
        }  
        if(arr.size() != pattern.size()){
            ans = false ;
            return ans ;
        }
        map<char, string> check1 ;
        map<string, char> check2 ;
        for(size_t i = 0 ; i < pattern.size() ; i++){
            if(check1.count(pattern[i]) == 0){
                check1.insert({pattern[i], arr[i]}) ;
            }
            else{
                auto it = check1.find(pattern[i]) ;
                if(it->second != arr[i]){
                    ans = false ;
                    break ;
                }
            }
            if(check2.count(arr[i]) == 0){
                check2.insert({arr[i], pattern[i]}) ;
            }
            else{
                auto it = check2.find(arr[i]) ;
                if(it->second != pattern[i]){
                    ans = false ;
                    break ;
                }
            }
        }
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s ;
    cin>>s ;
    string pattern ;
    cin>>pattern ;

    Solution ans ; 
    bool result = ans.wordPattern(pattern, s) ;

    cout<<result<<endl ;
    return 0 ;
}