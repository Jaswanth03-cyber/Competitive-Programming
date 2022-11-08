#include<bits/stdc++.h>
using namespace std ;


int binomial_coefficient(int n, int k){         // we need nck 
    int **coefficients ;
    coefficients = new int*[n+1] ;
    for(int i = 0 ; i <=n ; i++){
        coefficients[i] = new int[n+1] ;
    }
    for(int i = 0 ; i <=n ; i++){
        coefficients[i][0] = 1 ; 
    }
    for(int j = 1 ; j <=n ; j++){
        coefficients[0][j] = 0 ;
    }
    for(int i = 1 ; i <=n ; i++){
        for(int j = 1 ; j <=n ; j++){
            if(j > i){
                coefficients[i][j] = 0 ;
            }
            else if(i == j){
                coefficients[i][j] = 1 ;
            }
            else{
                coefficients[i][j] = coefficients[i-1][j] + coefficients[i-1][j-1] ;
            }
        }
    }
    int result =  coefficients[n][k] ;
    for(int i = 0 ; i <=n ; i++){
        delete[] coefficients[i] ;
    }
    delete[] coefficients ;
    return result ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n = 4 ;
    int k = 2 ;
    int final = binomial_coefficient(n, k) ;
    cout<<final<<endl ;
    for(int i = 0 ; i <= 9 ; i++){
        cout<<binomial_coefficient(9, i)<<" " ;
    }
    cout<<endl ;
    for(int i = 0 ; i <= 6 ; i++){
        cout<<binomial_coefficient(6, i)<<" " ;
    }
    cout<<endl ;
    for(int i = 0 ; i <= 3 ; i++){
        cout<<binomial_coefficient(3, i)<<" " ;
    }
    cout<<endl ;
    return 0 ;
}