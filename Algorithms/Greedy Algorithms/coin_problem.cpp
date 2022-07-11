/*
Coin Problem Here we are given an array of currencies, we are given an input value, we have to find minimum number of coins 
which result to the input value, we go with a greedy approach that first check for large coins, here we can use as many coins of
our wish.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

template<typename T> vector<T> min_coins(T currency[], int n, T value){

    vector<T> coins ;
    sort(currency, currency + n) ; // we sort the currencies given 

    for(int i = n-1 ; i >=0 ; i--){
        while(value >= currency[i]){
            value = value - currency[i] ;
            coins.push_back(currency[i]) ;
        }
    }

    return coins ;
}

int main(){

    int currency[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000} ;
    int n = sizeof(currency)/sizeof(currency[0]) ;

    vector<int> res ;
    res = min_coins<int>(currency, n, 93) ;

    int min_coins_required = res.size() ;
    cout<<"Minimum number of coins required are : "<<min_coins_required<<" and the coins are as follows " ;
    for(int i = 0 ; i < res.size() ; i++){
        cout<<res.at(i)<<" " ;
    }
    cout<<endl ;

    return 0 ;
}