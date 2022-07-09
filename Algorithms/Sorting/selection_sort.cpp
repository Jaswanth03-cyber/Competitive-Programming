/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order)
from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

The subarray which is already sorted. 
Remaining subarray which is unsorted.


For the first position in the sorted array, the whole array is traversed from index 0 to 4 sequentially. The first 
position where 64 is stored presently, after traversing whole array it is clear that 11 is the lowest value.
   64   	   25   	   12   	   22   	   11   
Thus, replace 64 with 11. After one iteration 11, which happens to be the least value in the array, tends to appear in the first position of the sorted list.
   11   	   25   	   12   	   22   	   64   


Second Pass:
For the second position, where 25 is present, again traverse the rest of the array in a sequential manner.
   11   	   25   	   12   	   22   	   64   
After traversing, we found that 12 is the second lowest value in the array and it should appear at the second place in the array,
thus swap these values.
   11   	   12   	   25   	   22   	   64  

Third Pass:
Now, for third place, where 25 is present again traverse the rest of the array and find the third least value 
present in the array.
   11   	   12   	   25   	   22   	   64   
While traversing, 22 came out to be the third least value and it should appear at the third place in the array, thus swap 22 with element present at third position.
   11   	   12   	   22   	   25   	   64   

Fourth pass:
Similarly, for fourth position traverse the rest of the array and find the fourth least element in the array 
As 25 is the 4th lowest value hence, it will place at the fourth position.
   11   	   12   	   22   	   25   	   64  

Fifth Pass:
At last the largest value present in the array automatically get placed at the last position in the array
The resulted array is the sorted array.
   11   	   12   	   22   	   25   	   64 


Basically finding min element(assuming ascending order) in the [i+1,N] for every iteration  and placing it at i for i = 0 to n-1 
*/

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

template<typename T> void display(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

template<typename T>void selectionsort(T arr[], int n){
    for(int i = 0 ; i < n - 1 ; i++){   // be carefull i can not be n-1 as j = i + 1 so be carefull
        int min_ind = i ;
        for(int j = i +1 ; j < n -1 ; j++){
            if(arr[j] < arr[min_ind]){
                min_ind = j  ;
            }
        }
        Swap(arr[i], arr[min_ind]) ;
    }
    return ;
}

int main(){

    srand(time(0)) ;
    int arr[] = {5,1,4,2,8} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    display<int>(arr,n) ;
    selectionsort<int>(arr, n) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr,n) ;

    int arr2[9] ;
    for(int i = 0 ; i < 9 ; i++){
        arr2[i] = rand()%max ;
    }
    display<int>(arr2, 9) ;
    selectionsort<int>(arr2, 9) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr2, 9) ;

    int arr3[] = {5,1,4,2,8,6,7,5,8,7,7,9} ;
    int b = sizeof(arr3)/sizeof(arr3[0]) ;

    display<int>(arr3,b) ;
    selectionsort<int>(arr3, b) ;
    cout << "Sorted array is : "<<endl ;
    display<int>(arr3,b) ;

 


    return 0 ;
}