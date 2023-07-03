#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/determine-if-string-halves-are-alike/
*/

class Solution {
public:
    bool halvesAreAlike(string s) {

        size_t n = s.size()/2 ;
        string one = s.substr(0, n) ;
        string two = s.substr(n, n) ;

        int count1 = 0 ; 
        int count2 = 0 ;
        for(int i = 0 ; i < n ; i++){
            if((one[i] == 'a') || (one[i] == 'e')  || (one[i] == 'i')  || (one[i] == 'o') ||  (one[i] == 'u') ||  (one[i] == 'A') ||  (one[i] == 'E') ||  (one[i] == 'I') ||  (one[i] == 'O') ||  (one[i] == 'U')){
                count1++ ;
            }
            if((two[i] == 'a') || (two[i] == 'e')  || (two[i] == 'i')  || (two[i] == 'o') ||  (two[i] == 'u') ||  (two[i] == 'A') ||  (two[i] == 'E') ||  (two[i] == 'I') ||  (two[i] == 'O') ||  (two[i] == 'U')){
                count2++ ;
            }
        }
        if(count1 == count2){
            return true ;
        }
        return false ;
    }
};
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s = "";
    cin>>s ;

    Solution ans ;
    bool result = ans.halvesAreAlike(s) ;
    cout<<result<<endl ;

    return 0 ;
}