/*
Exponential search involves two steps:  

Find range where element is present
Do Binary Search in above found range.
How to find the range where element may be present? 
The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last 
element of a subarray is not greater.  Once we find an index i (after repeated doubling of i), we know that the element 
must be present between i/2 and i  (Why i/2? because we could not find a greater value in previous iteration) 

*/

#include<bits/stdc++.h>
using namespace std ;
#define max 90 

template<typename T> void Swap(T &a, T &b){   // be carefull std has inbuilt swap function 
    T temp ;
    temp = b ;
    b = a ;
    a = temp ;
    return ;
}

template<typename T> void bubblesort(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - 1 - i  ; j++){               
            if(arr[j] > arr[j+1]){
                Swap(arr[j], arr[j+1]) ;
            }
        }
    }
    return ;
}

template<typename T> void display(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

template<typename T> int binarysearch(T arr[], int const begin, int const end, int const x){
    if(end >= begin){
        int mid = begin + (end - begin)/2 ;
        if(arr[mid] == x){
            return mid ;
        }
        if(x > arr[mid]){
            return binarysearch(arr, mid +1, end, x) ;
        }
        return binarysearch(arr, begin, mid -1 , x) ;
    }
    return -1 ;
}

template<typename T> int exponentialsearch(T arr[], int const n, int const x){
    if(arr[0] == x){
        return 0 ;
    }
    int i = 1 ;
    while(( i < n) && (arr[i]) <= x){
        i = i*2 ;
    }
    return binarysearch(arr, i/2 , min(i, n-1), x)   ;     // it is min() beacuse i can exceed n-1 
}

int main(){
    
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int arr[9] ;
    int a = 0 ;
    for(int i = 0 ; i < 9 ; i++){
        arr[i] = rand()%max ;
    }
    a = arr[3] ;
    display<int>(arr, 9) ;
    bubblesort<int>(arr, 9) ;

    int b = exponentialsearch(arr, 8, a) ;
    cout<<"In the sorted array the element "<<a<<" is present at "<<b<<" index"<<endl ;

    return 0 ;
}