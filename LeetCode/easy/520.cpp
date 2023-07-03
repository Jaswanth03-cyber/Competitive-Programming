#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/detect-capital/
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int ans = 0 ;
        int start = 0 ;
        int i = 0 ;
        while(i < word.size()){
            if((word[i] >= 65) && (word[i] <= 90)){
                ans++ ;
                start = i ;
            }
            i++ ;
        } 
        if(((ans == 1) && (start == 0)) || (ans == word.size()) || (ans == 0)){
            return true ;
        }   
        return false ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string input = "";
    cin>>input ;

    Solution ans ;
    bool result = ans.detectCapitalUse(input) ;
    cout<<result<<endl ;
    return 0 ;
}