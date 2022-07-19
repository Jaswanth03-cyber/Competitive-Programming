/*
Let us now consider another version of the coin problem where our task is to
calculate the total number of ways to produce a sum x using the coins. For
example, if coins = {1,3,4} and x = 5, there are a total of 6 ways:
• 1+1+1+1+1
• 1+1+3
• 1+3+1
• 3+1+1
• 1+4
• 4+1
f ways we can form the sum x. For example, if coins = {1,3,4}, then solve(5) = 6
and the recursive formula is
solve(x) = solve(x−1) + solve(x−3)+ solve(x−4).
*/

#include<iostream>
using namespace std ;

int find(int arr[], int n, int value){

    int *possibilities ;

    possibilities = new int[value + 1] ;

    possibilities[0] = 1 ;
    for(int i = 1 ; i <=value ; i++){
        possibilities[i] = 0 ;
    }

    for(int i = 1 ; i <=value ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i >= arr[j]){
                possibilities[i] = possibilities[i] + possibilities[i - arr[j]]  ;
            }
        }
    }
    int result = possibilities[value] ;
    delete[] possibilities ;

    return result ;
}

int main(){
    int arr[] = {1, 3, 4} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    cout<<find(arr, n, 7)<<endl ;
    return 0 ; 
}