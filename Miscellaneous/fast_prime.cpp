#include<iostream>
using namespac std ;
int main(){
    int n ;
    cin>>n ;
    bool is_prime = true  ;
    for(int i = 0 ; i*i < n ; i++){
        if(n%i == 0){
            is_prime = false
            break ;
        }
    }
    if(is_prime == true){
        cout<<"n is prime"<<endl ;
    }
    else{
        cout<<"n is not a prime number"<<endl
    }
    return 0 ;
}