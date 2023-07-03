#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {   
        priority_queue<int, vector<int>, greater<int>> pq ;  
        for(int i = 0 ; i < nums.size(); i++){
            pq.push(nums[i]) ;
        }

        vector<int> ans ;
        while(!pq.empty()){
            ans.push_back(pq.top()) ;
            pq.pop() ;
        }
        return ans ;
    }
};


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    vector<int> nums(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    vector<int> result = ans.sortArray(nums) ;

    for(int i = 0 ; i < n ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}