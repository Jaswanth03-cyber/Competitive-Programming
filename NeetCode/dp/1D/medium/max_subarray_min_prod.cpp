#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int64_t ans = 0 ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            int temp = nums[i] ;
            int j = i - 1;
            int k = i+1 ;
            long long sum = nums[i] ;
            int64_t prod = 1 ;
            while(j >= 0 && nums[j] >= temp){
                sum = sum + nums[j] ;
                j-- ;
            }
            while(k < n && nums[k] >= temp){
                sum = sum + nums[k] ;
                k++ ;
            }
            prod = sum*temp ;
            ans = max(ans, prod) ;
        }
        int mod = 1e9+7 ;
        int res = ans%mod ;
        return res ; 
    }
};

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> left(n, 0) ;
        vector<int> right(n, n-1) ;
        vector<long long> prefix(n, 0) ;
        prefix[0] = nums[0] ;
        for(int i = 1 ; i < n ; i++){
            prefix[i] = nums[i] + prefix[i-1] ;
        }

        stack<int> st ;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop() ;
            }
            if(!st.empty()){
                left[i] = st.top() + 1 ;
            }
            st.push(i) ;
        }

        while(!st.empty()){
            st.pop() ;
        }

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop() ;
            }
            if(!st.empty()){
                right[i] = st.top() - 1 ;
            }
            st.push(i) ;
        }
        long long ans = 0 ;
        long long sum = 0 ;
        long long prod = 0 ;
        for(int i = 0 ; i < n ; i++){
            // cout<<i<<" "<<left[i]<<" "<<right[i]<<endl ;
            sum = sum + prefix[right[i]] ;
            if(left[i] != 0){
                sum = sum - prefix[left[i]-1] ;
            }
            prod = sum*nums[i] ;
            ans = max(ans, prod) ;
            sum = 0 ;
        }
        int mod = 1e9 + 7 ;
        int res = ans%mod ;
        return res ;
    }
};
/*
this gives right answer but tle this can be improved see for every element you are considering the sub array for which the current value will be 
minimum so in the worst case it takes O(n^2) this can be optimised by pre computing for each value how much right or left it can go such that
this value still remains the min 

so using a stack we are computing how much right and how much left we can go from a value and we are storing that now using pre computed
prefix array we can calculate the sum product and take the maximum pls note the indexes well and check which value to be included in the sum well.

when ever the condition is wrong that nums[st.top()] >= nums[i] so till st.top()+1 we can go left as exactly at st.top() we lost the minimum
similarly for right when ever the condition is wrong till st.top()-1 we can go and also when st is empty then for right we can go till n-1 
and for left we can go till 0.
*/