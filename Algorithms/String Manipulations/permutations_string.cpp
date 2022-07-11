#include<iostream>
#include<string.h>
using namespace std ;

void Swap(char &a, char &b){
    char temp ;
    temp = b ;
    b = a ;
    a = temp ;
    return ;
}
void permutations(char s[], int low, int high){
    if(low == high){
        cout<<s<<endl ;
    }
    for(int i = low ; i <=high ; i++){

        Swap(s[low], s[i]) ;
        permutations(s, low +1 , high) ;
        Swap(s[low], s[i]) ;

    }
}

int main(){
    char arr[] = {'a', 'b', 'c'} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    permutations(arr, 0, n-1) ;

    return 0 ;
}