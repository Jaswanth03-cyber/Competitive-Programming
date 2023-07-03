#include<bits/stdc++.h>
using namespace std ;

/*
we are calculating pow(x,n)modm in an efficient way 

we will take the followign as an advatnage 
            | 1     if n = 0 
pow(x, n) = | pow(x, n/2)*pow(x, n/2)  if n is even
            | pow(x, n-1)*x         if n is odd

(x.y)mod m = ((xmod m)*(ymod m))mod m

there while 
temp = modular(x, n/2, m) ;
if n is even then fine we will get second case 
if so n is odd then modular(x, n/2, m) = modular(x, n-1/2, m)  as n is odd 
anyway as we need calculate modular(x, n-1, m) just multiply them and then multiple by x 

remember fermats theorem 

pow(x, m-1)mod m = 1 when x and m are co prime
*/

int modular(int x, int n, int m){
    if(n == 0){
        return 1%m ;
    }
    int temp = modular(x, n/2, m) ;
    temp = (temp*temp)%m ;
    if(n%2 == 1){
        temp = (temp*(x%m))%m ;
    }
    return temp ;
}


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int x = 0, n = 0, m = 0 ;
    cin>>x>>n>>m ;

    int ans = modular(x,n,m) ;
    cout<<"reminder when "<<x<<" power "<<n<<" is divided by "<<m<<" is : " ;
    cout<<ans<<endl ;
    return 0 ;
}