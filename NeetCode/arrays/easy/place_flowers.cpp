#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/can-place-flowers/
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0 ;
        bool ans = false ;

        if(n <=0){
            return true ;
        }
        if(flowerbed.size() == 1){
            if(n == 1){
                if(flowerbed[0] == 0){
                    flowerbed[0] = 1 ;
                    return true ;
                }
                else{
                    return false ;
                }
            }
            else{
                return false ;
            }
        }
        if(n >= flowerbed.size()){
            return false ;
        }
        for(size_t i = 0 ; i < flowerbed.size() ; i++){
            if(flowerbed[i] == 0){
                if(i == 0){
                    if(flowerbed[i+1] != 1){
                        count++ ;
                        flowerbed[i] = 1 ;
                    }
                }
                else if(i == flowerbed.size() -1){
                    if(flowerbed[i-1] != 1){
                        flowerbed[i] = 1 ;
                        count++ ;
                    }
                }
                else{
                    if((flowerbed[i-1] != 1) && (flowerbed[i+1] != 1)){
                        flowerbed[i] = 1 ;
                        count++ ;
                    }
                }
            }
        }
        if(count < n){
            ans = false ;
        }
        else{
            ans = true ;
        }
        return ans ;
    }
};



int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int m = 0 ;
    cin>>m ;
    vector<int> arr(m, 0) ;
    for(size_t i = 0 ; i < m ; i++){
        cin>>arr[i] ;
    }

    int n ; 
    cin>>n ; 

    Solution ans ;
    bool result = ans.canPlaceFlowers(arr,n) ;
    cout<<result<<endl ;

    return 0 ;  
}