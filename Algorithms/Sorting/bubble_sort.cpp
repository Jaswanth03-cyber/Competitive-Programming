#include<bits/stdc++.h>
#include<time.h>
using namespace std ;
#define max 90 
// lets sort in ascending order
template<typename T> void Swap(T &a, T &b){   // be carefull std has inbuilt swap function 
    T temp ;
    temp = b ;
    b = a ;
    a = temp ;
    return ;
}
/*
not from j = i as for ex if array = {17,25, 34,2}... now after one iteration 17 stays there that is wrong so 
we go till n-i-1 as after every iteration first for loop last i + 1 elements will be in proper order

for ex at the end of for i = 0 last element is the maximum in the array, at the end of loop with i = 1 last two elements will be 
proper, at the end of for i = 2 last three elements will be in sorted order 
*/
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

template<typename T> void optimisedbubblesort(T arr[], int n){
    bool swapped = false;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - 1 - i  ; j++){               
            if(arr[j] > arr[j+1]){
                Swap(arr[j], arr[j+1]) ;
                swapped = true ;
            }
        }
/*
No two elements are swapped in the sense array is in sorted order
*/
        if(swapped == false){
            return ;
        }
    }
    
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    srand(time(0)) ;
    int arr[] = {5,1,4,2,8} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    display<int>(arr,n) ;
    bubblesort<int>(arr, n) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr,n) ;

    int arr2[9] ;
    for(int i = 0 ; i < 9 ; i++){
        arr2[i] = rand()%max ;
    }
    display<int>(arr2, 9) ;
    bubblesort<int>(arr2, 9) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr2, 9) ;

    int arr3[] = {5,1,4,2,8,6,7,5,8,7,7,9} ;
    int b = sizeof(arr3)/sizeof(arr3[0]) ;

    display<int>(arr3,b) ;
    bubblesort<int>(arr3, b) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr3,b) ;

    // worst case when array is sorted in reverse order 


    return 0 ;
}