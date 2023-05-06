#include<bits/stdc++.h>
using namespace std ;

// if a number n can be written as n = a*b then either one of the following is true a <= sqrt(n) or b <= sqrt(n)
vector<int> factors(int n){
    vector<int> divisors ;
    for(int i = 1 ; i*i <= n ; i++){
        if(n%i == 0){
            divisors.push_back(i) ;
            if(i != n/i){
                divisors.push_back(n/i) ;
            }
        }
    }
    return divisors ;
}

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


/*
here while finding prime factorisation we know that prime factors can be till i where i*i <= n
so in the for loop first if 2 divides the given number then we insert 2 in the map and divided the number by 2 as we do not want that
factor 2 in further calculation not i*i iteration should be checked till sqrt(n) as n is changing as loop is gng on we have itroduced
a new variable temp we are dividing n/i as after i = 3 iteration if in case n is divided by 4 it also appears in prime factorisation
we do not want it so thats why removing all factors of 2 from n simillarly all factors of 3 so that no 9, 6 powers will come
we want only  prime factorization after completion of for loop we are adding one more condition as for example take n = 10 it checks only
till i =  3 but we need i = 5 as it is also a prime factor so if that condition is there in the sense that n value after the for loop is a prime number
*/
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

/*
we can check whether a number is prime or not, get factotrs of a number get prime factorization can get number of factors can get number of 
perfect divisors can get sum and product of divisors using prime factorization ... 

A number is said to be perfect number if sum of factors - given number should be the given number 

number of primes between 1 to n is approx n/ln(n)
*/
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    bool check = isprime(n) ;
    cout<<check<<endl ;
    vector<int> ans = factors(n) ;
    map<int, int> prime = primefactorisation(n) ;

    int size = ans.size() ;
    cout<<"Number of factotrs of "<<n<<" are as follows : " ;
    cout<<size<<endl ;
    cout<<"Factors of "<<n<<" are as follows : " ;
    for(int i = 0 ; i < size ; i++){
        cout<<ans[i]<<" " ;
    }
    cout<<endl ;
    cout<<"prime "<<"power :"<<endl ;
    for(auto it = prime.begin() ; it != prime.end() ; it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0 ;
}