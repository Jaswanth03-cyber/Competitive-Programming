#include<bits/stdc++.h>
using namespace std ;

/*
Euler totient rule
this formulae can be used to number of co primes of n between 1 and n 
*/
bool isprime(int n){
    bool ans = true ;
    for(int i = 2 ; i*i <= n ; i++){
        if(n%i == 0){
            ans = false ;
            break ;
        }
    }
    return ans ;
}

map<int, int> primefactorisation(int n){
    map<int, int> mp ;
    if(isprime(n)){
        mp.insert({1,1}) ;
        mp.insert({n,1}) ;
        return mp ;
    }
    int temp = n ;
    for(int i = 2 ; i*i <= temp ; i++){
        while(n%i == 0){
            if(mp.find(i) != mp.end()){
                mp[i]++ ;
            }
            else{
                mp.insert({i, 1}) ;
            }
            n = n/i ;
        }
    }
    if(n > 1){
        if(mp.find(n) != mp.end()){
            mp[n]++ ;
        }
        else{
            mp.insert({n, 1}) ;
        }
    }
    return mp ;
}

int findcoprimes(int n){
    map<int, int> factorisation ;
    factorisation = primefactorisation(n) ;
    int count = 1 ;
    for(auto it = factorisation.begin() ; it != factorisation.end() ; it++){
        count = count*(pow(it->first, it->second-1))*(it->first - 1) ;
    }
    return count ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    int ans = findcoprimes(n) ;
    cout<<"Number of coprimes of "<<n<<" between 1 and "<<n<<" is : " ;
    cout<<ans<<endl ;
    return 0 ;
}