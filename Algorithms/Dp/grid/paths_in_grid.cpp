/*
Our next problem is to find a path from the upper-left corner to the lower-right
corner of an n × n grid, such that we only move down and right. Each square
contains a positive integer, and the path should be constructed so that the sum of
the values along the path is as large as possible.

3 7 9 2 7
9 8 3 5 5
1 7 9 8 5
3 8 6 4 10
6 3 9 7 8
path from the upper-left corner to the lower-right corner.
Assume that the rows and columns of the grid are numbered from 1 to n, and
value[y][x] equals the value of square (y, x). Let sum(y, x) denote the maximum
sum on a path from the upper-left corner to square (y, x). Now sum(n,n) tells
us the maximum sum from the upper-left corner to the lower-right corner. For
example, in the above grid, sum(5,5) = 67.
We can recursively calculate the sums as follows:
sum(y, x) = max(sum(y, x−1),sum(y−1, x))+value[y][x]
*/

#include<bits/stdc++.h>
using namespace std ;

int find_max(int value[][5], int n){

    int **sum ;

    sum = new int*[n] ;
    for(int i = 0 ; i < n ; i++){
        sum[i] = new int[5] ;
    }

    int count_row = value[0][0] ;
    for(int i = 1 ; i < n ; i++){
        sum[0][i] = count_row + value[0][i] ;
        count_row = count_row + value[0][i] ;
    }
    int count_column = value[0][0] ;
    for(int j = 1 ; j < 5 ; j++){
        sum[j][0] = count_column + value[j][0] ;
        count_column = count_column + value[j][0] ;
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < 5 ; j++){
            sum[i][j] = max(sum[i-1][j], sum[i][j-1]) + value[i][j] ;
        }
    }

    int result = sum[n-1][4] ;

    for(int i = 0 ; i < n ; i++){
        delete[] sum[i] ;
    }
    delete[] sum ;

    return result ;

}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int arr[][5] = {{3, 7, 9, 2, 7}, 
                    {9, 8, 3, 5, 5}, 
                    {1, 7, 9, 8, 5}, 
                    {3, 8, 6, 4, 10}, 
                    {6, 3, 9, 7, 8}} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    cout<<find_max(arr, n)<<endl ;
}