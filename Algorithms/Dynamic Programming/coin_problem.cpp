/*
Given a currency set and a value of amount is given we have to find min_coins_reqimum number of coins needed whose total sum results in the 
given value and the coins we choose should be in the currency set given 

idea :

The essential property of solve is that its values can be recursively calculated
from its smaller values. The idea is to focus on the first coin that we choose for
the sum. For example, in the above scenario, the first coin can be either 1, 3
or 4. If we first choose coin 1, the remaining task is to form the sum 9 using
the min_coins_reqimum number of coins, which is a subproblem of the original problem.
Of course, the same applies to coins 3 and 4. Thus, we can use the following
recursive formula to calculate the min_coins_reqimum number of coins:

solve(x) = min_coins_req(solve(x-a[0]), solve(x-a[1]), solve(x - a[2]), solve(x - a[3]), ... solve(x - a[n-1])) + 1 where n is the length
of the currency array(a) given 
*/

#include<iostream>
#include<cmath>
using namespace std ;

#define MIN 1e5 ;

int min_coins(int arr[], int n, int value){

    if(value < 0){
        return -1 ;
    }

    int *min_coins_req ;
    min_coins_req = new int[value] ;

    min_coins_req[0] = 0 ;

    for(int i = 1 ; i < value ; i++){

        int min_value = MIN ;

        for(int j = 0 ; j < n ; j++){
            if(i >= arr[j]){
                min_value = min(min_value, min_coins_req[i-arr[j]] + 1) ;
            }
        }

        min_coins_req[i] = min_value ;
    }

    int result = min_coins_req[value-1] ;

    delete[] min_coins_req ;

    return result ;
}

int main(){
    int arr[] = {1, 3, 4} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    cout<<"Minimum number of coins required to get "<<27<<" is : "<<min_coins(arr, n, 27)<<endl ;

    return 0 ;
}