#include <bits/stdc++.h>
using namespace std ;


/*
we can use this algorithm to find all the primes between 1 and n

using this 

here sieve[j] = 0 means it is prime if sieve[i] = 1 means it is not prime and inside for loop executes if i is a prime number 
for(int i = 2 ; i <= n ; i++){
    if(sieve[i]){
        continue ;
    }
    for(int j = 2*i ; j <= n ; j = j + i){
        sieve[j] = 1 ;
    }
}
we are taking into fact that if x is a prime then 2x,3x,4x... these are not primes so if a prime is found we added a loop to make all others > 0 
initially sieve[i] is 0 for all 
*/
// function that gives all primes from 1 to n 
vector<int> giveprimes(int n){
    vector<int> sieve(n + 1, 0) ;
    for(int i = 2 ; i <= n ; i++){
        if(sieve[i] > 0){
            continue ;
        }
        for(int j = 2*i ; j <= n ; j = j + i){
            sieve[j] = 1 ;
        }
    }
    vector<int> ans ;
    for(int i = 2 ; i <= n  ; i++){
        if(sieve[i] == 0){
            ans.push_back(i) ; // as i starting from 2... n vector indices from 0 to n -2
        }
    }
    return ans ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    vector<int> primes = giveprimes(n) ;

    int size = primes.size() ;
    cout<<"Prime numbers that lie between 1 and "<<n<<" are as follows : " ;
    for(int i = 0 ; i < size ; i++){
        cout<<primes[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}