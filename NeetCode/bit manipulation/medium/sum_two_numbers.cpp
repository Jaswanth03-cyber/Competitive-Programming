#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/sum-of-two-integers/
*/

/*
int Add(int x, int y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry should be unsigned to
        // deal with -ve numbers
        // carry now contains common
        //set bits of x and y
        unsigned carry = x & y;
 
        // Sum of bits of x and y where at
        //least one of the bits is not set
        x = x ^ y;
 
        // Carry is shifted by one so that adding
        // it to x gives the required sum
        y = carry << 1;
    }
    return x;
}
*/

class Solution {
public:
    int getSum(int a, int b) { 
        int temp = a ;
        if(b == 0){
            return temp ;
        }
        else if(b < 0){
            for(int i = b ; i <= -1 ; i++){
                temp = temp -1 ;
            }
        }
        else{
            for(int i = 1 ; i <= b ; i++){
                temp = temp + 1  ;
            }
        }
        return temp ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int a = 0 ; 
    int b = 0 ;
    cin>>a>>b ;

    Solution ans ;
    int result = ans.getSum(a,b) ;
    cout<<result<<endl ;

    return 0 ;
}