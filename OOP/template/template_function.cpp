#include<iostream>
using namespace std ;
// remember that namespace std contains max, min, sort, swap functions inbuilt so before declaring function name just be carefull
template <typename T>     
/*
not sufficient if we declare once at the top, we have to write this before every function/class we can have sam name T or u can even use another name
where we want to use template that is function for more data types, we can even write template <class T> class/typename both are fine 
*/

T mymax(T x, T y){     
    if(x > y){
        return x ;
    }
    else if(x == y){
        return x ;
    }
    else{
        return y ;
    }
}
template <typename T>     // instead of T u can even write template<typename U> and use U in place of T for this function
T mymin(T x, T y){
    if(x > y){
        return y ;
    }
    else if(x == y){
        return x ;
    }
    else{
        return x ;
    } 
}
 template <typename T>
 void myswap(T &a, T &b){
    T c = b ;
    b = a ;
    a = c ;
    return ;
}
template <typename T>  // yes u have to declare every time before the function/class we use otherwise compile time error 
void mysort(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[i]){
                myswap(arr[j], arr[i]) ;
            }
        }
    }
    return ;
}
int main(){
    cout<<mymax<int>(3,9)<<endl ;
    cout<<mymax<double>(3.6, 9.6)<<endl ;
    cout<<mymin<int>(3,9)<<endl ;
    cout<<mymin<double>(3.6, 9.6)<<endl ;
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);
    mysort<int>(a, n) ;
    for(int i = 0 ; i < n ; i++){
        cout<<a[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}
