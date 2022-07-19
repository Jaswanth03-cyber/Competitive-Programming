/*
Given an array of n positive integers we have to print all the check subset sums of the array given assume sum of all the 
elements of the array is not too big 
*/

#include<iostream>
#include<cmath>
#include<vector> 
#include<cstring>
using namespace std ;

vector<int> subsetsum(int arr[], int n){

    int *new_array ;      // creating to avoid confusion between the indexes 

    new_array = new int[n + 1] ;
    new_array[0] = -1 ;

    for(int i = 1 ; i <= n ; i++){
        new_array[i] = arr[i-1] ;
    }

    int sum = 0 ; 
    for(int i  = 0 ; i < n ; i++){
        sum = sum + arr[i] ;
    }



    bool **check ;

    check = new bool*[n+1] ;
    for(int i = 0 ; i <= n ; i++){
        check[i] = new bool[sum+1] ;
    }

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= sum ; j++){
            check[i][j] = false ;
        }
    }

    for(int i = 0 ; i <= n ; i++){
        check[i][0] = true ;
    }

    for(int i = 1 ; i <= n ; i++){

        check[i][new_array[i]] = true ;

        for(int j = 1 ; j <= sum  ; j++){

            if(check[i - 1][j] == true){

                check[i][j + new_array[i]] = true ;
                check[i][j] = true ;
            }
        }
    }

    vector<int> res ;

    for(int i = 0 ; i <= sum ; i++){
        if(check[n][i] == true ){
            res.push_back(i) ;
        }
    }

    for(int i = 0 ; i <= n ; i++){
        delete[] check[i] ;
    }
    delete[] check ;

    return  res ;
}

/*
Here check[i][j] is true considering the array elements from arr[0...i-1] that is new_array[1...i] if there is a subset whose 
sum is j.

so like if we see we write check[i][new_arr[i]] = true as considering elements from arr[0... i-1] that is new_array[1...i]

as new_array[i] is the last element in that we can have a subset singelton element whose sum is new_arr[i] so its true 

now for suppose check[i-1][j] is true then even if we increase number of elements there is still a subset whose sum is j so 
check[i][j] is true if so check[i-1][j] is true similarly if we add new_array[i] to the sum and increase no of elements such 
that value added to the sum that is new_array[i] is at the index i so thats also true because we already have a subset whose 
sum is j now we are adding one element to the subset also to the sum so its true. 
*/

int main(){

    int arr[] = {2, 3, 4, 5, 6} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    vector<int> res ;
    res = subsetsum(arr, n) ;

    cout<<"Distinct check sum of elements among all check subsets are : " ;
    for(int i = 0 ; i < res.size() ; i++){
        cout<<res.at(i)<<" " ;
    }
    cout<<endl ;

    return 0 ;
}