#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-common-subsequence/
*/

/*
Logic we are taking a l length sequence and calculating its maximum longest common sub sequence that is possible 
for 0 size 0 is the value and fo =r size 1 if both the characters are same then + 1 if not take maximum of removing that last character from each

possibilities let Zk is the maximum commom subsequence then text1 and text2 are of length n, m respectively and Z is the longest possible sub seq and whose length is k
if text1[n] == text2[m] then Z(k-1) is the longest common subsequence to text1[n-1] and text2[m-1]
if text1[n] != text2[m] then Z(k-1) can be from text1[n-1] and text2[m] or text1[n] and text2[m-1] we have to take the maximum possible 
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.length() ;
        int size2 = text2.length() ;
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0)) ;
        for(int i = 1 ; i <= size1 ; i++){
            for(int j = 1 ; j <= size2 ; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +  1 ;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
                }
            }
        }
        return dp[size1][size2] ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string text1 = "" ;
    string text2 = "" ;
    cin>>text1>>text2 ;

    Solution ans ;
    int res = ans.longestCommonSubsequence(text1, text2) ;
    cout<<res<<endl ;
    return 0 ;
}