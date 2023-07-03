#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int countdigits(int num){
        int ans = 0 ;
        while(num != 0){
            ans++ ;
            num = num/10 ;
        }
        return ans ;
    }
    string largestNumber(vector<int>& nums) {
        map<int, set<string, greater<string>>> mp ;
        set<string, greater<string>> st ;
          
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
    string result = ans.largestNumber(nums) ;

    cout<<result<<endl ;
    return 0 ;
}