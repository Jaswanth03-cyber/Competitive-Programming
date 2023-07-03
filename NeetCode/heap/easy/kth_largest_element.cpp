#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

class KthLargest {
public:
    multiset<int, greater<int>> st ;
    int temp ;
    KthLargest(int k, vector<int>& nums) {
        temp = k ;
        for(int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]) ;
        }
    }
    int add(int val) { 
        st.insert(val) ;
        int count = 0 ;
        int ans = 0 ;
        for(auto it = st.begin() ; it != st.end() ; it++){
            count++ ;
            if(count == temp){
                ans = *it ;
                break ;
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

    vector<int> nums(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    int k = 0 ;
    cin>>k ;
    KthLargest ans(k, nums) ;

    int val = 0 ;
    cin>>val ;
    int res = ans.add(val) ;
    cout<<res<<endl ;
    return 0 ;
}