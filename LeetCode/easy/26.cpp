#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st ;
        int count = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]) ;
                count++ ;
            }
        }
        int i = 0 ;
        for(auto it = st.begin() ; it != st.end() ; it++){
            nums[i] = *it ;
            i++ ;
        }
        return count ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int result = ans.removeDuplicates(nums) ;
    cout<<result<<endl ;
}


