/*
Given a floor of size n x m and tiles of size 1 x m. The problem is to count the number of ways to tile the given floor using 
1 x m tiles. A tile can either be placed horizontally or vertically. Both n and m are positive integers and 2 < = m.

            |  1, 1 < = n < m
 count(n) = |  2, n = m
            | count(n-1) + count(n-m), m < n
*/

#include<iostream>
using namespace std ;

int tiles(int n, int m){

    int count[n + 1] ;

    count[0] = 0 ;

    for(int i = 1 ; i <= n ; i++){
        if(i > m){
            count[i] = count[i-m] + count[i-1] ;
        }
        else if (i == m || i == 1){
            count[i] = 1 ;
        }
        else{
            count[i] = 2 ;
        }
    }

    return count[n] ;
}

int main(){
    int n = 7 ;
    int m = 4 ;
    cout<<tiles(n, m)<<endl ;
    return 0 ; 
}

