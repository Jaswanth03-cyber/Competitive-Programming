#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/sort-characters-by-frequency/
*/



class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq ;
        multimap<int, char, greater<int>> mp ; // can have many keys with all same value 
        string ans = "" ;
        for(int i = 0 ; i < s.size() ; i++){
            if(freq.count(s[i]) == 0){
                freq.insert({s[i], 1}) ;
            }
            else{
                auto it = freq.find(s[i]) ;
                it->second++ ;
            }
        } 
        for(auto it = freq.begin() ; it != freq.end() ; it++){
            mp.insert({it->second, it->first}) ;
        }

        for(auto it = mp.begin(); it != mp.end() ; it++){
            string temp(it->first, it->second) ;
            ans = ans + temp ;
        } 
        return ans ; 
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s = "" ;
    cin>>s ;

    Solution ans ;

    string result = ans.frequencySort(s) ;
    cout<<result<<endl ;

    return 0 ;
}