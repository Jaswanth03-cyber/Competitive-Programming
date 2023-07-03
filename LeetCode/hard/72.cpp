#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/edit-distance/
*/

class Solution {
public:
int edit_distance(string a, string b){
    vector<vector<int>> distance ;
    int n = a.size() ;
    int m = b.size() ;
    distance.resize(n+1) ;
    for(int i = 0 ; i <= n ; i++){
        distance[i].resize(m+1) ;
    }
    for(int i = 0 ; i <= n ; i++){
        distance[i][0] = i ;
    }
    for(int j = 1 ; j <= m ; j++){
        distance[0][j] = j ;
    }
    string string1 = " " + a ; 
    string string2 = " " + b ;

    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= m ; j++){
            int cost ;
            int minimum ;
            if(string1[i] == string2[j]){
                cost = 0 ;
            }
            else{
                cost = 1 ;
            }
            minimum = min(distance[i][j-1] + 1 , distance[i-1][j] + 1) ;
            distance[i][j] = min(distance[i-1][j-1] + cost, minimum) ;
        }
    }
    int result = distance[n][m] ; 
    return result ;
}
    int minDistance(string word1, string word2) {

        int ans = edit_distance(word1, word2) ;
        return ans ;   
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s = "" ;
    string t = "" ;

    cin>>s ;
    cin>>t ;

    Solution ans ;
    int result = ans.minDistance(s,t) ;

    cout<<result<<endl ;
    return 0 ;
}