#include<bits/stdc++.h>
using namespace std ;


int main(){
    string input ; 
    cin>>input ;

    int size = input.length() ;

    int current_max = 0 ;

    int i = 0 ; 

    while(i < size){
        int index = i ;
        int length = 0 ;
        while((input[index + 1] == input[index]) && ( i + 1 < size )){
            length++ ;
            index++ ;
        }
        i = index + 1 ;
        current_max = max(current_max, length+1) ;
    }
    cout<<current_max<<endl ;
    return 0 ;
}