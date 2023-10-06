/*
Coin Problem Here we are given an array of currencies, we are given an input value, we have to find minimum number of coins 
which result to the input value, we go with a greedy approach that first check for large coins, here we can use as many coins of
our wish.currency sets only for sets of this type 

This does not work for all sets it works for only euro coins which is the set below for all others it does not work 

it works for array of this form 

{1k, 2k, 5k...} only k being multiple of 10 
*/
void solve(){
    long long A ; // this was given around 1e9 we can maintain a vector of fibo and we can do like a coin sum but we can not maintain a vector of size 1e9 so there is an efficient greedy approach for it
    vector<int> fibo;
    for(int i=0;i<3;i++) {fibo.push_back(i);}
    while(fibo[fibo.size()-1]<A){
        fibo.push_back(fibo[fibo.size()-1]+fibo[fibo.size()-2]);
        }
    int ans=0;
    int i=fibo.size()-1;
    while(A>0)
    {
        if(fibo[i]<=A)
        {
            A-=fibo[i];
            ans++;
        }
        else i--;
    }
    return ans;
}
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

    int currency[] = {1, 2, 5, 10, 20, 50, 100, 200} ;
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