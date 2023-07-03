#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/string-compression/
*/

class Solution {
public:
    vector<int> digits(int num){
        vector<int> ans ;
        while(num != 0 ){
            ans.push_back(num%10) ;
            num = num/10 ;
        }
        return ans ;
    }
    int compress(vector<char>& chars) {
        if(chars.size() == 1){
            return 1 ; 
        }   
        int n = chars.size() ;
        string s = "" ;
        int count = 0 ;
        char character = chars[0] ;
        char req = 'a' ;
        vector<int> temp ;
        for(int i = 0 ; i < chars.size() ; i++){
            if(chars[i] == character){
                count++ ;
                if(i == chars.size() - 1){
                    s = s + character ;
                    temp = digits(count) ;
                    for(int i = temp.size() -1  ; i >= 0; i--){
                        req = temp[i]+ 48 ;
                        s = s + req ;
                    }
                }
            }
            else{
                s = s + character ;
                if(count != 1){
                    temp = digits(count) ;
                    for(int i = temp.size() -1 ; i >= 0 ; i--){
                        req = temp[i] + 48 ;
                        s = s + req ;
                    }
                    temp.clear() ;
                }
                if(i == chars.size() -1){
                    s = s + chars[i] ;
                }
                else{
                    character = chars[i] ;
                    count = 1 ;
                }
            }
        }
        int ans = s.length() ;
        chars.resize(ans) ;
        for(int i = 0 ; i < ans ; i++){
            chars[i] = s[i] ;
        }
        return ans ;
    }
};


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    vector<char> chars(n, 'a') ;

    for(int i = 0 ; i , n ; i++){
       cin>>chars[i] ;   
    }

    Solution ans ;

    int result = ans.compress(chars) ;

    cout<<result<<endl ;
    return 0 ;
}