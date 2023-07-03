/*
https://leetcode.com/problems/contains-duplicate/
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> pq ;
        bool find ;
        
        for(unsigned int i = 0 ; i < nums.size() ; i++){
            if(pq.count(nums[i]) == 0){
                pq.insert(nums[i]) ;
            }
            else{
                return true ;
            }
        }        
        return false ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;



    vector<int> p ;
    int n ;
    cin>>n ; 
    p.resize(n) ;

    for(int i  = 0 ; i < n ; i++){
        cin>>p[i] ;
    }

    Solution ans ;

    bool check = ans.containsDuplicate(p) ;
    cout<<check<<endl ;

    return 0 ;
}