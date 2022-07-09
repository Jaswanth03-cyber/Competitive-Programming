#include<iostream>
#include<time.h>
using namespace std ;
#define max 90 ;

/*
Iterate from arr[1] to arr[N] over the array. 

Compare the current element (key) to its predecessor. 

If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements 
one position up to make space for the swapped element.

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. 
The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and 
placed at the correct position in the sorted part.


See for ex lets take the array 
4 3 2 10 12 1 5 6

key is 3 compare with 4, 4 is more so change position 
now the array is
3 4 2 10 12 1 5 6

now key is 2 compare with 4 as 2 is less move it left and again move it as 2 is less than 3 
now the array is 
2 3 4 10 12 1 5 6

now key is 10 its fine no need of any changes 
now the array is 
2 3 4 10 12 1 5 6 

now key is 12 its fine no need of any changes 
now the array is 
2 3 4 10 12 1 5 6

now the key is 1 so now we have to move it till first position 
after all the operations array will be 
1 2 3 4 10 12 5 6 

now the key is 5 simillarly we do


what we do is we are iterating from 1 to N taking arr[i] as the key and placing it in the right position before i
that is between [0,...,i-1] and remember that after this iteration [0,i] elements are sorted we have to check for [i+1,N]
*/

template<typename T> void Swap(T &a, T &b){   // be carefull std has inbuilt swap function 
    T temp ;
    temp = b ;
    b = a ;
    a = temp ;
    return ;
}

template<typename T> void display(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

template<typename T> void insertionsort(T arr[], int n){
    T key ;
    for (int i = 1; i < n; i++){
        key = arr[i];
        int j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return ;
}
int main(){

    srand(time(0)) ;
    int arr[] = {5,1,4,2,8} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    display<int>(arr,n) ;
    insertionsort<int>(arr, n) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr,n) ;

    int arr2[9] ;
    for(int i = 0 ; i < 9 ; i++){
        arr2[i] = rand()%max ;
    }
    display<int>(arr2, 9) ;
    insertionsort<int>(arr2, 9) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr2, 9) ;

    int arr3[] = {5,1,4,2,8,6,7,5,8,7,7,9} ;
    int b = sizeof(arr3)/sizeof(arr3[0]) ;

    display<int>(arr3,b) ;
    insertionsort<int>(arr3, b) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr3,b) ;
 


    return 0 ;
}