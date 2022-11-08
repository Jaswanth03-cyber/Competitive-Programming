/*
Given an array of n positive integers and an integer say b, we have to find if there is a  subset in the array of those positive 
integers whose sum is b 

Naive approach:
go through all the subsets and see if any subset sum is b but this algorithm is exponential as we will have pow(2,n) subsets and each subset
takes n iterations in worst case so we need to find another approach for this 

here check[i][j] reprsents true if there exists a subset from the new_arr[1...i](nothing but arr[0...i-1])whose 
sum is j else false here i reprsents no of elements we are taking to 

sub problems {1, ... n} and {0, ... sum}

*/

#include<bits/stdc++.h>
using namespace std ;

bool find(int arr[], int n, int sum){
    
    int *new_arr ;         // creating new array of elements for no confusion further 
    new_arr = new int[n+1] ;
    new_arr[0]  = -1 ;      // this is not needed so some negative number 
    for(int i = 1 ; i <=n ;i++){
        new_arr[i] = arr[i-1] ;
    }

    bool **check  ; 

    check = new bool*[n + 1] ;        // n rows are created 
    for(int i = 0 ; i <= n ; i++){
        check[i] = new bool[sum + 1] ;   // here for each row sum columns are created 
    }

    for(int i = 0 ; i <= n ; i++){
        check[i][0] = 1 ;         // sum is 0 only with no elements so true as empty set is a subset
    }

    for(int j = 1 ; j <= sum ;j++){
        check[0][j] = 0 ;              // sum can not be j if number of elements is 0 
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= sum ; j++){
            if(new_arr[i] > j){
                check[i][j] = check[i-1][j] ;
            }
            else{
                check[i][j] = max(check[i-1][j], check[i-1][j - new_arr[i]]) ;
            }
        }
    }

    bool result = check[n][sum] ;

    for(int i = 0 ; i < n ; i++){
        delete[] check[i] ;
    }
    delete[]  check ;
    delete[] new_arr ;
    return result ;
}

/*

check[i][j] = max(check[i-1][j], check[i-1][j - new_arr[i]]) ;
we can even write this in this way

bool a ;

      -----1-------      -----------2-------------
a = ((check[i-1][j]) || (check[i-1][j - new_arr[i]]))

check[i][j] = a ;

as see if new_arr[i] is in the set then 2 is calculated if not then 1 is calculated if any is true then value of a is 1
if none are true then 0 so both are same 

*/  

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int set[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 9; 
    int n = sizeof(set) / sizeof(set[0]); 
    cout<<find(set, n, 2)<<endl ;
    for(int i = 0 ; i < n ; i++){
        cout<<find(set, n, set[i]) ;
    }
    cout<<endl ;
    for(int i = 0 ; i < n ; i++){
        cout<<find(set, n, 100) ;
    }
    cout<<endl ;
    return 0 ;
}


