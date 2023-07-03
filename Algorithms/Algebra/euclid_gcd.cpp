#include<bits/stdc++.h>
using namespace std ;

/*
worst case for gcd(a,b) algorithm will be when a and b are consecutive fibonacci numbers 
*/
int gcdloop(int a, int b){
    int tempa = a ;
    int tempb = b ;
    int remi = 0 ;
    while(tempb != 0){
        remi = tempa%tempb ;
        tempa = tempb ;
        tempb = remi ;
    }
    return tempa ;
}
int gcd(int a, int b){
    if(b == 0){
        return a ;
    }
    return gcd(b, a%b) ;
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int a =0, b = 0 ;
    cin>>a>>b ;
    int ans = 0 ;
    if(a > b){
        ans = gcd(a, b) ;
    }
    else{
        ans = gcd(b,a) ;
    }
    cout<<"gcd of "<<a<<" and "<<b<<" is : " ;
    cout<<ans<<endl ;
    int lcm = (a*b)/ans ;
    cout<<"lcm of "<<a<<" and "<<b<<" is : " ;
    cout<<lcm<<endl ;
    ans = gcdloop(a, b) ;
    cout<<"gcd of "<<a<<" and "<<b<<" using while loop is : " ;
    cout<<ans<<endl ;  
    return 0 ;
}