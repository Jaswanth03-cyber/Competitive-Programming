#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isPalindrome(string s) {

        string temp = "" ;
        string two = "" ;
        int n = s.size() ; 

        for(int i = 0 ; i < n ; i++){
            if((s[i] >= 'A') && (s[i] <= 'Z')){
                s[i] = s[i] + 32 ;
                temp = temp + s[i] ;
            }
            else if((s[i] >= 'a') && (s[i] <= 'z')){
                temp = temp + s[i] ;
            }
            else if((s[i] >= '0') && (s[i] <= '9')){   
                temp = temp + s[i] ;       
            }
            else{
                continue ;
            }
            if((s[n-i-1] >= 'A') && (s[n-i-1] <= 'Z')){
                s[n-i-1] = s[n-i-1] + 32 ;
                two = two + s[n-i-1] ;
            }
            else if((s[n-i-1] >= 'a') && (s[n-i-1] <= 'z')){
                two = two + s[n-i-1] ;
            }
            else if((s[n-1-i] >= '0') && (s[n-i-1] <= '9')){   
                two = two + s[n-i-1] ;       
            }
            else{
                continue ;
            }
        } 
        cout<<temp<<endl ;
        cout<<two<<endl ;
        if(temp != two){
            return false ;
        }
        return true ;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string ans = "abc" ;
    ans = ans + 'i' ;

    cout<<ans<<endl ;

    return 0 ;
}