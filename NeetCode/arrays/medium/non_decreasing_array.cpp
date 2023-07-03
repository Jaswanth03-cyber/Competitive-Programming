#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0 ;
        int index ;
        bool ans = true ;
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            if(nums[i] > nums[i+1]){
                index = i ;
                count++ ;
            }
        }
        if(count > 1){
            ans = false ; 
        } 
        return ans ;   
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}