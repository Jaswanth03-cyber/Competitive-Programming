#include<bits/stdc++.h>
using namespace std ;


long long count(long long a){

    if(a < 0){
        return 0 ;
    }
    if(a == 0){
        return 1 ;
    }

    vector<long long> count_numbers(20,1) ;     // as at max 19 digits so starting from 0 digit number to 19 digit number

    count_numbers[0] = 1 ;
    count_numbers[1] = 9 ;
    for(int i = 2 ; i < 20 ; i++){
        count_numbers[i] = 9*count_numbers[i-1] ;
    } 

    long long num = a ;
    int no_of_digits = 0 ;
    vector<int> digits ;
    long long divisor = 10 ;
    while(num > 0){
        long long c = num%divisor ;
        digits.push_back(c) ;
        no_of_digits++ ;
        num = num/divisor ;
    }

    long long result = 0 ;

    for(int i = 0 ; i < no_of_digits ; i++){
        result = result + count_numbers[i] ;        // all possibilities till number of digits - 1 because we need to calculate from 0 till the number givenno_of_digits - 1
    }
    
    // for nth digit possibilities where n is number of digits in the given number
    for(int i = no_of_digits -1 ; i >= 0 ; i--){
        if(i == no_of_digits -1){
            result = result + (digits[i]-1)*count_numbers[i] ;
        }
        else{
            result = result + digits[i]*count_numbers[i] ;
        }
    }
    return result ;
}
long long solve(long long a, long long b){

    long long result ;

    result = count(a) - count(b) ;

    return result ;


}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    long long a ; 
    long long b ;
    cin>>a>>b ;

    long long result = solve(b, a -1);
    cout<<result<<endl ;
    return 0 ;
}