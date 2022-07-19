#include<iostream>
using namespace std ;

void fibonacci(int n){
    int *F ;
    F = new int[n+1] ;
    F[0] = 1 ;
    F[1] = 1 ;
    for(int i = 2 ; i <= n ; i++){
        F[i] = F[i-1] + F[i-2] ;
    }

    for(int i = 0 ; i <= n ; i++){
        cout<<F[i]<<" " ;
    }
    cout<<endl ;
    delete[] F ;
    return ;
}

int main(){
    int n = 9 ;
    fibonacci(n) ;
    return 0 ;
}