#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
*/
/*
Logic is simple that first and last letter should be same so we take the letters which occur more than once take the min index and max index of the
occurence of that alphabet all the distinct alphabets between them will form a palindrome.
*/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length() ;
        map<char, pair<int, int>> mp ;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]].first = min(i, mp[s[i]].first) ;
                mp[s[i]].second = max(i, mp[s[i]].second) ;
            }
            else{
                mp[s[i]] = {i, 0} ;
            }
        }

        int one = 0 ;
        int two = 0 ;
        int ans = 0 ;
        int size = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            set<char> st ;
            for(int i = it->second.first + 1 ; i < it->second.second ; i++){
                st.insert(s[i]) ;
            }
            size = st.size() ;
            ans = ans + size ;
        }
        return ans ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string s = "" ;
    cin>>s ;
    Solution ans ;
    int res = ans.countPalindromicSubsequence(s) ;
    cout<<res<<endl ;
    return 0 ;
}