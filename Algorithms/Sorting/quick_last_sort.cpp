#include<iostream>
#include<time.h>
using namespace std ;
#define max 90 ;

/*
Basically what we do is we take a pivot in the given array we will partition the array in such a way that 
pivot is kept at the right position whereas all the elements to the left of pivot are less than the pivot and that to the 
right are more than the pivot, we repeat this reccursively This is basically a divide and conquer problem. 
Pivot can be 
random element 
always last element
always first element 
median is the pivot  

Here we are taking last element as the pivot 
*/
template<typename T> void Swap(T &a, T &b){
    T temp ;
    temp = b ;
    b  = a ;
    a = temp ; 
    return ;
}
template<typename T> void display(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}
template<typename T>int partition(T arr[], int low, int high){
    T pivot = arr[high] ;
    int pivot_index = low ; 
/*
as this would be the pivot final place as for every partition we find correct place for last element in that array given
*/ 
    for(int j = low ; j < high ; j++){
        if(arr[j] <= pivot){
            Swap(arr[pivot_index], arr[j]) ;
            pivot_index++ ;
        }
    }
    Swap(arr[pivot_index], arr[high]) ;
    return pivot_index ;
}
template<typename T>void quicksort(T arr[], int low, int high){
    if(low < high){
        int partition_index = partition(arr, low, high) ;         
/*
Here we are basically finding the right position for the last element in the given range low to high of the parameters
we place it there and for array before that and array after that we call the function reccursively.
*/
        quicksort(arr, low, partition_index - 1) ;
        quicksort(arr, partition_index + 1, high) ;
    }
    return ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    srand(time(0)) ;
    int arr[] = {5,1,4,2,8} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    display<int>(arr,n) ;
    quicksort<int>(arr, 0, n-1) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr,n) ;

    int arr2[9] ;
    for(int i = 0 ; i < 9 ; i++){
        arr2[i] = rand()%max ;
    }
    display<int>(arr2, 9) ;
    quicksort<int>(arr2, 0, 8) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr2, 9) ;

    int arr3[] = {5,1,4,2,8,6,7,5,8,7,7,9} ;
    int b = sizeof(arr3)/sizeof(arr3[0]) ;

    display<int>(arr3,b) ;
    quicksort<int>(arr3, 0, b-1) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr3,b) ;


    return 0 ;
}

