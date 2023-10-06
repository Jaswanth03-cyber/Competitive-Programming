#include <bits/stdc++.h>
using namespace std ;


/*
We are given the prices of k
products over n days, and we want to buy each product exactly once. However,
we are allowed to buy at most one product in a day. What is the minimum total
price? For example, consider the following scenario (k = 3 and n = 8):
*/

/*
Logic :-
so there are many possibilities that we can but a product on a particular day or may not so like on a day there 2^k possibilities 
as for k products total number of subsets is the number of possibilities and also we have to check if in case product[i] has been bought 
some previous day before then we can not buy that product this day so the approach is that we maintain a dp table which is of size (1<<k)*n 
(1<<k) possibilities for each day and there are n days so that many possibilities are being maintained.   

so now dp[i][j] represents minimum cost to buy products (a,b,c..d)(set represented as a number i) on day d. set bits of i denotes hwich products we are
buying on that day. 

line no 55: so now the base case is that on day0 for all the products if you are taking only single product (1<<i) for all 0<= i< k will be the price of 
the product on day 0 itself that is price[i][0]

line no 59: for 0(denoting no products no need to buy any product) min cost for all days will be zero

line 62: now for each day from 2 to n (indexing 1 to n-1)

line 63: for each possibility of the subsets that means the set bits in j will tel whether to buy a product or not 

line 64: on day i we can choose the buy the set of products j or we can choose to not buy any product on that day so we set dp[j][i] = dp[j][i-1]

line 65: now for each product l 0 <= l < k

line 66: if a set bit is one that is in this possibility we want to buy product l so we are taking that product this day and adding its price 
         on this day to the dp[j^(1<<l)][i-1] which denotes we have choosen to buy this product on day i so in previous days we should not buy this
         product so thats why xor of j^(1<<l) and previous days i-1   so taking minimum of these 

final result is that dp[(1<<k)-1][n-1] buying all products and on day n what is the minimum cost 

this recursive relation is nothing but 
total(S,d) = min(total(S,d −1), minx∈S(total(S \ x,d −1)+price[x][d]))

This means that we either do not buy any product on day d or buy a product x
that belongs to S. In the latter case, we remove x from S and add the price of x
to the total price 
If in case we are buying any product on day d we take the minimum of buying a particualr product on day d thats why minx∈S(total(S \ x,d −1)+price[x][d])
*/
void solve(vector<vector<int>> &prices){
    int k = prices.size() ;
    int n = prices[0].size() ;

    vector<vector<int>> dp(1<<k, vector<int>(n, INT_MAX)) ;

    for(int i = 0 ; i < k ; i++){
        dp[(1<<i)][0] = prices[i][0] ;
    }

    for(int i = 0 ; i < n ; i++){
        dp[0][i] = 0 ;
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < (1<<k); j++){
            dp[j][i] = dp[j][i-1] ;
            for(int l = 0 ; l < k ; l++){
                if(j&(1<<l)){
                    if(dp[j^(1<<l)][i-1] != INT_MAX){
                        dp[j][i] = min(dp[j][i], prices[l][i] + dp[j^(1<<l)][i-1]) ;
                    }
                }
            }
        }
    }

    for(int i = 0 ; i < (1<<k) ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<dp[i][j]<<" " ;
        }
        cout<<endl ;
    }

    cout<<dp[(1<<k)-1][n-1]<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    int k = 0 ;
    cin>> k ;
    vector<vector<int>> prices(k, vector<int>(n, 0)) ;
    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>prices[i][j] ;
        }
    }

    solve(prices) ;
    return 0 ;
}

/*
line 69: pls do check that dp[j^(1<<l)][i-1] is not INT_MAX or else overflow and negative values or either keep the starting values as 1e9 instead of INT_MAX
*/