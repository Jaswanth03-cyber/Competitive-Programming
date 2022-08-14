
#include<bits/stdc++.h>
using namespace std ;

#define MIN 1e9 

int min_coins(long long arr[], int n, int value){

    if(value < 0){
        return -1 ;
    }

    int *min_coins_req ;
    min_coins_req = new int[value +1] ;

    min_coins_req[0] = 0 ;
    for(int i = 1 ; i <=value ; i++){
        min_coins_req[i] = 0 ;
    }

    for(int i = 1 ; i <=value ; i++){

        int min_value = MIN ;

        for(int j = 0 ; j < n ; j++){
            if(i >= arr[j]){
                min_value = min(min_value, min_coins_req[i-arr[j]] + 1) ;
            }
            else{
                min_coins_req[i] = 0 ;
            }
        }

        min_coins_req[i] = min_value ;
    }
    if(min_coins_req[value] == MIN){
        return -1 ;
    }

    int result = min_coins_req[value] ;

    delete[] min_coins_req ;

    return result ;
}

int main(){
    long long n ;
    cin>>n ;
    long long value ; 
    cin>>value ;
    long long  arr[n] ;
    for(long long i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }

    cout<<min_coins(arr, n, value)<<endl ;

    return 0 ;
}