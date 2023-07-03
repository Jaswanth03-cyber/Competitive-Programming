#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-number-of-balloons/
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> freq ;
        freq.insert({'b', 0}) ;
        freq.insert({'a', 0}) ;
        freq.insert({'l', 0}) ;
        freq.insert({'o', 0}) ;
        freq.insert({'n', 0}) ;
        for(size_t i = 0 ; i < text.size() ; i++){
            if(freq.count(text[i]) == 1){
                auto it = freq.find(text[i]) ;
                it->second++ ;
            }
            else{
                continue ;
            }
        } 
        int count = -1 ;
        freq['l'] = freq['l']/2 ;
        freq['o'] = freq['o']/2 ;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq ;
        for(auto it = freq.begin() ; it != freq.end() ; it++){
            pq.push(make_pair(it->second, it->first)) ;
        }
        count = pq.top().first ;
        return count ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string text ;
    cin>>text ;

    Solution ans ;

    int result = ans.maxNumberOfBalloons(text) ;
    cout<<result<<endl ;

    return 0 ;
}