#include<iostream>
#include<time.h>
using namespace std ;
#define max 90 ;


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

// actually we assume array given is sorted array but lets take normal one tooo and sort it before giving as input 
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

template<typename T> void display(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

int main(){
    int arr[9] ;
    int a = 0 ;
    for(int i = 0 ; i < 9 ; i++){
        arr[i] = rand()%max ;
    }
    a = arr[3] ;
    display<int>(arr, 9) ;
    bubblesort<int>(arr, 9) ;
    display<int>(arr,9) ;

    int b = binarysearch(arr, 0, 8, a) ;
    cout<<"In the sorted array the element "<<a<<" is present at "<<b<<" index"<<endl ;

    return 0 ;
}