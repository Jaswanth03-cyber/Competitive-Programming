#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/delete-columns-to-make-sorted/
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0 ;
        int n = strs.size() ;
        int j = 0 ;
        int size = strs[0].size() ;
        while(j < size){
            for(int i = 0 ; i < n - 1; i++){
                if(strs[i][j] > strs[i+1][j]){
                    ans++ ;
                    break ;
                }
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

    vector<string> strs ;
    string input = "" ;
    for(int i = 0 ; i < n ; i++){
        cin>>input ;
        strs.push_back(input) ;
    }

    Solution ans ;
    int result = ans.minDeletionSize(strs) ;
    cout<<result<<endl ;
    
    return 0 ;
}