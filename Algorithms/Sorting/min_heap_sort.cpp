#include<iostream>
#define max 90 ;
using namespace std ;


/*this will give us the sorted order in descending order 


*/
template<typename T> void Swap(T &a, T &b){
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
template<typename T>void heapify(T arr[], int n, int index){
        int left_index = 2*(index) + 1;
        int right_index = 2*(index) + 2 ;
        int smallest = index ;
        if((arr[left_index] < arr[index])  && (left_index < n) ){
            smallest = left_index ;
        }
        if((arr[right_index] < arr[smallest]) && (right_index < n) ){
            smallest = right_index ;
        }
        if(smallest != index){
            swap(arr[index], arr[smallest]) ;
            heapify(arr, n, smallest) ;
        }
        return  ;
    }

template<typename T> void heapsort(T arr[], int n){
    for(int i = n/2 - 1 ; i >=0 ; i--){
        heapify(arr,n,i) ;
    }
    for(int i = n -1 ; i >= 0 ; i--){
        Swap(arr[0],arr[i]) ;
        heapify(arr,i,0) ;
    }
    return ;
}

int main(){
    srand(time(0)) ;
    int arr[] = {5,1,4,2,8} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    display<int>(arr,n) ;
    heapsort<int>(arr, n) ;
    cout << "Sorted array in descending order is : "<<endl ;
    display<int>(arr,n) ;

    int arr2[9] ;
    for(int i = 0 ; i < 9 ; i++){
        arr2[i] = rand()%max ;
    }
    display<int>(arr2, 9) ;
    heapsort<int>(arr2, 9) ;
    cout << "Sorted array in descending order is : "<<endl ;
    display<int>(arr2, 9) ;

    int arr3[] = {5,1,4,2,8,6,7,5,8,7,7,9} ;
    int b = sizeof(arr3)/sizeof(arr3[0]) ;

    display<int>(arr3,b) ;
    heapsort<int>(arr3, b) ;
    cout << "Sorted array in descending order is : "<<endl ;
    display<int>(arr3,b) ;

    return 0 ;

}