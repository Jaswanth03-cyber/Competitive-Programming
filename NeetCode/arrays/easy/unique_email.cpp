#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/unique-email-addresses/
*/

class Solution {
public:
    string process(string &s){
        string ans = ""  ;

        int i = 0 ;
        while(i < s.size()){
            if(s[i] == '.'){
                i++ ;
                continue ;
            }
            else if(s[i] == '+'){
                while(s[i] != '@'){
                    i++  ;
                }
                break ;
            }
            else if(s[i] == '@'){
                break ;
            }
            else{
                ans = ans + s[i] ;
                i++ ;
            }
        }
        while(i < s.size()){
            ans = ans + s[i] ;
            i++ ;
        }
        return ans ;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> st ;
        string ans = "" ;
        for(int i = 0 ; i < emails.size() ; i++){
            ans = process(emails[i]) ;
            if(st.count(ans) == 0){
                st.insert(ans) ;
            }
        }
        int result = st.size() ;
        return result ;    
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    string input = "" ;
    vector<string> emails ;

    for(int i = 0 ; i < n ; i++){
        cin>>input ;
        emails.push_back(input) ;
    }

    Solution ans ;
    int result = ans.numUniqueEmails(emails) ;

    cout<<result<<endl ;
    return 0 ;
}