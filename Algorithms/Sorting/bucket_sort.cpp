/*
bucketSort(arr[], n)
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.
Bucket sort is mainly useful when input is uniformly distributed over a range. For example, consider the following problem. 
Sort a large set of Ting point numbers which are in range from 0.0 to 1.0 and are uniformly distributed across the range.
 How do we sort the numbers efficiently?
*/
#include<iostream>
#include<vector>
#include<algorithm>  // for inbuilt sort but we did not use it
#include<time.h>
using namespace std ;
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
    return ;
}


template<typename T> void insertionsort(vector<T> &inp){
    if(inp.size() == 0 || inp.size() == 1){
        return ;
    }
    T key ;
    for (int i = 1; i < inp.size(); i++){
        key = inp[i];
        int j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && inp[j] > key){
            inp[j + 1] = inp[j];
            j = j - 1;
        }
        inp[j + 1] = key;
    }
    return ;
}

template<typename T> void bucketsort(T arr[], int n){
    vector<T> buckets[n] ;
    for(int i = 0 ; i < n ; i++){
        int index = n*arr[i] ;
        buckets[index].push_back(arr[i]) ;
    }
    for(int i = 0 ; i < n ; i++){
        // sort(buckets[i].begin(), buckets[i].end()) ;  // we can even use this inbuilt function 
        insertionsort(buckets[i]) ;
    }
    int index = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < buckets[i].size() ; j++){
            arr[index] = buckets[i][j] ;
            index++ ;
        }
    }
    return ;
}
int main(){
    srand(time(0)) ;
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);

    display(arr,n) ; 

    bucketsort(arr, n);

    cout << "Sorted array is : "<<endl ;
    display(arr,n) ;

    float arr2[9] ;
    for(int i = 0 ; i < 9 ; i++){
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        arr2[i] = r ;
    }
    display(arr2,9) ;
    bucketsort(arr2, 9);
    cout << "Sorted array is : "<<endl ;
    display(arr2, 9) ;
    return 0;

}