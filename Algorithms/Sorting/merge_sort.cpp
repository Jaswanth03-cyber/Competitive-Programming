#include<iostream>
#include<time.h>
using namespace std ;
#define max 90 ;

template<typename T> void display(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

template<typename T> void merge(T arr[], int const left, int const mid, int const right){
    auto const left_size = mid - left + 1 ;    // size of left array
    auto const right_size = right - mid ;     // size of right array 

    T *left_array  ;
    T *right_array ;
    left_array = new T[left_size] ;
    right_array = new T[right_size] ;
    for(auto i = 0 ; i < left_size ; i++){
        left_array[i] = arr[i + left] ;       // not that arr indexing starts from 0 in middle left is not zero so
    }
    for(auto j = 0 ; j < right_size ; j++){
        right_array[j] = arr[mid + 1 + j]   ;    // right array starts from mid +1 till right 
    }

/*
Now we have to merge the two arrays 
*/
    auto left_index = 0 ;      // starting index of left array
    auto right_index = 0 ;       // starting index of the right array 
    int merge_index = left ; 

    while((left_index < left_size) && (right_index < right_size)){
        if(left_array[left_index] <= right_array[right_index]){
            arr[merge_index] = left_array[left_index] ;
            left_index++ ;   
        }
        else{
            arr[merge_index] = right_array[right_index] ;
        }
        merge_index++ ;
    }

    // copying any left over elements in the left array to the merged array 
    while(left_index < left_size){
        arr[merge_index] = left_array[left_index] ;
        left_index++ ;
        merge_index++ ;
    }
    // copying any left over elements in the right array to the merged array
    while(right_index < right_size){
        arr[merge_index] = right_array[right_index] ;
        right_index++ ;
        merge_index++ ;
    }

    return ; 

}

template<typename T>void mergesort(T arr[], int const begin, int const end){
    if(begin >= end){
        return ;
    }
    int mid = begin + (end - begin)/2 ;
    mergesort(arr, begin, mid) ;
    mergesort(arr, mid + 1, end) ;
    merge(arr, begin, mid, end) ;

}

int main(){

    srand(time(0)) ;
    int arr[] = {5,1,4,2,8} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    display<int>(arr,n) ;
    mergesort<int>(arr, 0, n-1) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr,n) ;

    int arr2[9] ;
    for(int i = 0 ; i < 9 ; i++){
        arr2[i] = rand()%max ;
    }
    display<int>(arr2, 9) ;
    mergesort<int>(arr2, 0, 8) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr2, 9) ;

    int arr3[] = {5,1,4,2,8,6,7,5,8,7,7,9} ;
    int b = sizeof(arr3)/sizeof(arr3[0]) ;

    display<int>(arr3,b) ;
    mergesort<int>(arr3, 0, b-1) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr3,b) ;


    return 0 ;
}