#include<iostream>
using namespace std ;
void binary(int a){
    int keys[32] ;
    for(int i =0; i < 32; i++){
        keys[i] = 0 ;
    }
    int j = 31 ;
    while(a != 1 && a != 0){
        int k = a%2 ;
        keys[j] = k ;
        j-- ;
        a = a/2 ;
    }
    keys[j] = a ;
    for(int i = 0 ; i< 32; i++){
        cout<<keys[i] ;
    }
    cout<<endl ;
    return ;
}
int main(){
    binary(4) ;
    binary(9) ;
    binary(32) ;
    binary(165) ;
    binary(4096) ;
    return 0 ;
}