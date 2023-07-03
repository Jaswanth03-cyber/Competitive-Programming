#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-the-town-judge/

I have just added a zero person who is trusted by everyone just to ensure that
all the values from 1-n are in the map 
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, set<int>> mp ;
        set<int> st ;
        st.insert(0) ;
        for(int i = 1 ; i <= n ; i++){
            mp.insert({i,st}) ;
        }
        st.clear() ;
        for(int i = 0 ; i < trust.size() ; i++){
            mp.find(trust[i][0])->second.insert({trust[i][1]}) ;
        }  
        int ans = -1 ;
        auto itr = mp.begin() ;
        for(auto it = mp.begin(); it != mp.end() ; it++){
            if(it->second.size() == 1){
                itr = it ;
                ans = it->first ;
                break ;
            }
        }
        if(ans == -1){
            return ans ;
        }
        else{
            for(auto it = mp.begin() ; it != mp.end() ; it++){
                if(it->first == ans){
                    continue ; 
                }
                if(it->second.count(ans) == 0){
                    ans = -1 ;
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

    int n = 0 ;
    cin>>n ; 

    vector<vector<int>> trust ;
    trust.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        trust[i].resize(2,0) ;
        cin>>trust[i][0] ;
        cin>>trust[i][0] ;
    }

    Solution ans ;
    int result = ans.findJudge(n, trust) ;
    cout<<result<<endl ;
    return 0 ;
}