#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/group-anagrams/
*/

/*
What I have done is that first for each string in the given input I have calculated a freq map which calculates the frequency of each character 
in the string and stores it in a map name called check now if check is already in the map<mi,vi> then I have just added that string to its anagrams
vector string by finding mp.find(check)->second this is a vector of strings which are anagrams so just pushed back this string 

if check map is not present in mp then I have inserted it this map and the corresponding input string in a vector name v which I cleared before adding

to reduce the space I have just once declared the check and v and used it every time for all the strings 
*/


typedef set<char> si ;
typedef vector<string> vi ;
typedef map<char, int> mi ;
class Solution {
public:
    mi freq(string &input){
        mi mp ;
        for(int i = 0 ; i < input.size() ; i++){
            if(mp.count(input[i]) == 0){
                mp.insert({input[i], 1}) ;
            }
            else{
                mp.find(input[i])->second++ ;
            }
        }
        return mp ;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        mi check ;
        map<mi, vi> mp ;
        vi v ;
        for(int i = 0 ; i < strs.size() ; i++){
            check = freq(strs[i]) ;
            if(mp.count(check) == 0){
                v.clear() ;
                v.push_back(strs[i]) ;
                mp.insert({check, v}) ;
            }
            else{
                mp.find(check)->second.push_back(strs[i]) ;
            }
        }
        vector<vector<string>> ans ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            ans.push_back(it->second) ;
        }
        return ans ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    string input = "" ;
    vector<string> strs(n, "") ;

    for(int i = 0 ; i < n ; i++){
        cin>>strs[i] ;
    }

    Solution ans ;

    vector<vector<string>> result = ans.groupAnagrams(strs) ;

    for(int i = 0 ; i < result.size() ; i++){
        for(int j = 0 ; j < result[i].size() ; j++){
            cout<<result[i][j]<<" " ;
        }
        cout<<endl ;
    }
    cout<<endl ;
    return 0 ;
}