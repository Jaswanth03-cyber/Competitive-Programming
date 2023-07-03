#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool ans = false ;
        int sum = 0 ;
        int n = nums.size() ;
        int reminder = 0 ;
        unordered_map<int, int> hash ;
        for(int i = 0 ; i < n ; i++){
            sum = sum + nums[i] ;
            reminder = sum%k ;
            if(sum%k == 0 && i != 0){
                ans = true ;
                break ;
            }
            if(hash.find(k - reminder) != hash.end()){
                ans = true ;
                break ;
            }
            hash[reminder]++ ;
        }
        return ans ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}