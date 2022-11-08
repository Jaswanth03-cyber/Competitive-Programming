#include<bits/stdc++.h>
#include<time.h>
using namespace std ;

template<typename T> int linearsearch(T arr[], int n, int a){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == a){
            return i ;
        }
    }
    return -1 ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int arr[] = {5,4,3,2,1,6,7,8,9} ;
    int a = 3 ;
    int index = linearsearch<int>(arr, 9, a) ;
    cout<<"The element "<<a<<" is present in the array at the index "<<index<<endl ;

    return 0 ;
    
}