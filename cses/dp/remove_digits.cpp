#include<bits/stdc++.h>
using namespace std ;
#define MAX 1e9


int solve(int n){
    vector<int> no_of_steps(n+1, MAX) ;
    no_of_steps[0] = 0 ;
    for(int i = 1 ; i <= n ; i++){
        int current_num = i ; 
        while(current_num > 0){
            int digit = current_num%10 ;
            no_of_steps[i] = min(no_of_steps[i], no_of_steps[i-digit] + 1) ;
            current_num = current_num/10 ;
        }
    }
    return no_of_steps[n] ;
}

/*
here dp[i] represents min steps for number i to become 0 so here we used dynamic programming for example
lets take 27 

so 27 can be made to 20 or 25 next 20 can be made 18 or kept as 20 itself now 18 can be made 10 or 17 now 10 can be made 9 or kept 
as 10 itself 9 can be made 0 directly 

so like for every digit every time take the maximum digit in the number and subtract it now min of dp[i] is nothing but dp[i-digit] +1
so for a number we go through each digit take min at every step we use dp for this.
*/

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    long long n ;
    cin>>n ;
    cout<<solve(n)<<endl ;
    return 0 ;
}