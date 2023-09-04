#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp ;
        int size = nums.size() ;
        int n = 0 ;
        bool ans = false ;
        for(int i = 0 ; i < size ; i++){
            if(mp.find(nums[i]) != mp.end()){
                n = mp[nums[i]].size() ;
                for(int j = 0 ; j < n ; j++){
                    if(abs(i-mp[nums[i]][j]) <= k){
                        return true ; 
                    }
                }
                mp[nums[i]].push_back(i) ;
            }
            else{
                vector<int> vec ;
                vec.push_back(i) ;
                mp.insert({nums[i], vec}) ;
            }
        } 
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int k = 0 ;
    cin>>n>>k ;
    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int result = ans.containsNearbyDuplicate(nums, k) ;
    cout<<result<<endl ;
}