#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-consecutive-sequence/
*/

/*
I have kept all the nums in to the set now starting from begining of the set and traversing through the set I have checked whether next consecutive 
element is in the set or not if its there then increased the count if not there I have again set the counter to 1 and pushed the previous 
value into the priority queue as we want largest consecutive sequence and we will check from the next element. when ans = 1 then at that index
i num[i] will be the starting value of the sequence which is present in the nums there will be many consecutive sequences in the nums but 
we have taken maximum one 

for ex nums = [4,3,2,5,0,-1,-2,6,8,7,9]

here there are two sequences -2, -1, 0 and 2,3,4,5,6,7,8,9  ans =1 when *it is -2 and when *it is 2 
as in a set the values are by default in increasing order
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        if(nums.size() == 0){
            return 0 ;
        }
        set<int> st ;
        for(int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]) ;
        } 
        int ans = 1 ;
        priority_queue<int> pq ;
        for(auto it = st.begin() ; it != st.end() ; it++){
            if(st.count(*it+1) == 0){
                pq.push(ans) ;
                ans = 1 ;
            } 
            else{
                ans++ ;
            }
        } 
        return pq.top() ;   
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<int> nums(n, 0) ;

    for(int i = 0 ; i < n; i++) {
        cin>>nums[i] ;
    }

    Solution ans ;

    int result = ans.longestConsecutive(nums) ;
    cout<<result<<endl ;
    return 0 ;
}