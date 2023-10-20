#include <bits/stdc++.h>
using namespace std ;


void solve(){
    int n = 0 ;
    cin>>n ;
    int k = 0 ;
    cin>>k ;
    vector<int> stones(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>stones[i] ;
    }

    vector<int> dp(k+1, false) ;

    for(int i = 1 ; i <= k ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i - stones[j] < 0){
                break ;
            }
            else{
                if(!dp[i-stones[j]]){
                    dp[i] = true ;
                    break ;
                }
            }
        }
    }

    if(dp[k]){
        cout<<"First"<<endl ;
    }
    else{
        cout<<"Second"<<endl ;
    }
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}

/*
here the logic is simple so here 

if dp[i] is true then who ever wins first is the winner else second guy so the logic is that lets say 
we are having true at 2 now lets say 4 is the value of k and 2, 3 are there now 
if first user removes 2 from k now second user ends up with 2 assume there was not any first removal so now k is 2 and second user is the one 
who picks first and first user has not picked up yet so now as dp[2] is true second user when as dp[2] is true dp[4] will be false that is the 
actual first user looses but we can not conclude here we have to check all the possibilities check removing 3 so now if the first user
removes 3 now 1 stone is left so now same second user is the first guy and he is picking first time so as dp[1] is false he looses 
so actual second user loses  so we have to check all the possibilities even if in one possibility dp[i-stones[j]] is false dp[i] will be true

its like we are starting with a value now first guy picks stones now the value will be some new value say b so if dp[b] is false virtual first guy
that is the second guy looses because he is starting with a value b that will end him in loosing the game that is what dp[i] denotes 
but if dp[b] is true now so he is starting with a value where he will end up winning 

so every time when a stone is being picked assuming it is the first time he is picking and he is the first guy who is picking.
this way it goes in an optimal manner.
*/