#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/guess-number-higher-or-lower/description/
*/

/*
Here logic is same as finding the number itself, here f(t) which will be true for first half and will not be true for second half is that 
the number which we guess is greater than one half of the array and less than the other half of the array. 
*/
class Solution {
public:
    int guessNumber(int n) {  
        int l = 1 ;
        int r = n ;

        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(guess(mid) == 0){
                return mid ;
            }
            else if(guess(mid) < 0){
                r = mid -1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return 0 ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    Solution ans ;
    int res = ans.guessNumber(n) ;
    cout<<res<<endl ;
    return 0 ;
}