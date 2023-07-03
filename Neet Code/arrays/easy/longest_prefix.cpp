#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-common-prefix/
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.size() == 1){
            return strs[0] ;
        }
        string ans = "" ;
        int j = 0 ;
        int count = 0 ;
        while(j < strs[0].size()){
            for(int i = 1 ; i < strs.size() ; i++){
                if((j >= strs[i].size()) || (strs[i][j] != strs[0][j])){
                    return ans ;
                }
                else{
                    count++ ;
                }
            }
            if(count == strs.size() - 1){
                ans = ans + strs[0][j] ;
                count = 0 ;
            }
            else{
                return ans ;
            }
            j++ ;
        }
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<string> strs(n, "") ;

    for(int i = 0 ; i < n ; i++){
        cin>>strs[i] ;
    }

    Solution ans ;

    string result = ans.longestCommonPrefix(strs) ;

    cout<<result<<endl ;
    
    return 0 ;
}