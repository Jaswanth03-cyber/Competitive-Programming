/*
Our first problem is to find the longest increasing sublength in an array
of n elements. This is a maximum-length length of array elements that goes
from left to right, and each element in the length is larger than the previous
element. For example, in the array

Let length(k) denote the length of the longest increasing sublength that
ends at position k. Thus, if we calculate all values of length(k) where 0 ≤ k ≤ n−1,
we will find out the length of the longest increasing sublength. For example,
the values of the function for the above array are as follows:

0-1-2-3-4-5-6-7
6 2 5 1 7 4 8 3

length(0) = 1       as see only 6 so 1
length(1) = 1       as 2 < 6 so 1 
length(2) = 2       as 5 > 2 so    2, 5 is the length so 2
length(3) = 1       as 1 is less so 1
length(4) = 3       as 2, 5, 7 can form that length so 3
length(5) = 2       as 4,1 can form that so 2
length(6) = 4       as 2, 5, 7, 8 can form that length so 4
length(7) = 2       as 3, 1 can form that length so 2


algorithm :
To calculate a value of length(k), we should find a position i < k for which
array[i] < array[k] and length(i) is as large as possible. Then we know that
length(k) = length(i) + 1, because this is an optimal way to add array[k] to a
sublength. However, if there is no such position i, then length(k) = 1, which
means that the sublength only contains array[k].
*/


#include<bits/stdc++.h>
using namespace std ;

int find(int arr[], int n, int position){

    int *length ;

    length = new int[n] ;

    for(int i = 0 ; i < n ; i++){
        length[i] = 1 ;
    } 

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ;j++){
            if(arr[j] < arr[i]){
                length[i] = max(length[i], length[j] + 1) ;
            }
        }
    }


    int result = length[position] ;

    delete[] length ;

    return result ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    int arr[] = {6, 2, 5, 1, 7, 4, 8, 3} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    for(int i = 0 ; i < n ; i++){
        cout<<"length("<<i<<") is : "<<find(arr, n, i)<<endl ;
    }

    return 0 ;
}