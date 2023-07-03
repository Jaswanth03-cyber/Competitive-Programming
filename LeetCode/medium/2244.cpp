#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
*/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0 ;
        map<int, int> mp ;
        priority_queue<int, vector<int>, greater<int>> pq ;
        for(int i = 0 ; i < tasks.size() ; i++){
            if(mp.count(tasks[i]) == 0){
                mp.insert({tasks[i], 1}) ;
            }
            else{
                mp.find(tasks[i])->second++ ;
            }
        } 
        int two = 0 ;
        int three = 0 ;
        int check1 = 0 ;
        int check2 = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(it->second < 2){
                return -1 ;
            }
            else if((it->second == 2) || (it->second == 3)){
                ans++ ;
            }
            else{
                three = it->second%3 ;
                two = it->second%2 ;
                if(two == 0){
                    check2 = it->second/2 ;
                }
                else{
                    check2 = (it->second - 3)/2 + 1 ;
                }
                if(three == 2){
                    check1 = (it->second/3) + 1 ;
                }
                else if(three == 0){
                    check1 = (it->second/3) ;
                }
                else{
                    check1 = (it->second - 4)/3 + 2 ;
                }
                ans = ans + min(check1, check2) ;
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

    vector<int> tasks(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>tasks[i] ;
    }

    Solution ans ;

    int result = ans.minimumRounds(tasks) ;
    cout<<result<<endl ;
    
    return 0 ;
}