#include<bits/stdc++.h>
using namespace std ;

/*
unique binary tree of n nodes where node values from 1 to n 
this is catalan number 2nCn/(n+1)
 

 (2n!)/((n!)*(n+1!))
*/

class Solution {
public:
    unsigned long int catalan_number(unsigned int n){

        unsigned long int catalan[n + 1];

        catalan[0] = 1 ;
        catalan[1] = 1 ;
 
        for (int i = 2; i <= n; i++) {
            catalan[i] = 0 ;
            for (int j = 0; j < i; j++){
                catalan[i] = catalan[i] + catalan[j]* catalan[i - j - 1];
            }
        }

        return catalan[n];
    }

    int numTrees(int n){
        unsigned long int k = n ; 
        unsigned long int temp = catalan_number(k) ;
        int result = temp ;
        return result ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;  

    Solution ans ;
    int result = ans.numTrees(n) ;

    cout<<result<<endl ;
    return 0 ;
}