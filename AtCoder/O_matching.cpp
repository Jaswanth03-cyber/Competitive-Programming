#include <bits/stdc++.h>
using namespace std ;

/*
I have written down(commented) code first, if we can see there I am checking for all men and all women so that will lead to 
O(n^22^n) we can do it still efficient by only considering men which can be matched with the ith women like a graph it is optimised then
the time complexity will be O((n+m)2^n) but there is one more condition that we need to count, condition is that number of men must be equal 
to number of women we have to consider only those cases we need not calculate for all the subsets we need to consider those sets whose total 
count of men is same as number of women

so coming to the logic 
dp[s][i] denotes number of ways we can match women 0 till i(1 to i+1) with the persons in the set s
so 
dp[s][i] = sum(dp[s-j][i-1]) for a valid jth person here valid in the sense j should be compatible to match with i and also j should be in the set
so remaining persons can be matched in dp[s-j][i-1] which is matching 0 to i-1 members with the men who are in the set s-j so adding that.
*/
class graph{
    int women ;
    vector<vector<int>> adjlist ;
    public:
    graph(int n){
        women = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
    }

    void solve(){
        int n = women ;
        vector<vector<int>> dp((1<<n), vector<int>(n, 0)) ;
        int size = adjlist[0].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[0][i] ;
            dp[1<<node][0] = 1 ;
        }

        int mod = 1e9+7 ;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < (1<<n) ; j++){
                if(__builtin_popcount(j) == i+1){
                    int size = adjlist[i].size() ;
                    for(int k = 0 ; k < size ; k++){
                        int node = adjlist[i][k] ;
                        if(j&(1<<node)){
                            dp[j][i] = (dp[j][i] + dp[j^(1<<node)][i-1])%mod ;
                        }
                    }
                }
            }
        }
        cout<<dp[(1<<n)-1][n-1]<<endl ;
    }

};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int n = 0;
    cin>>n ;

    vector<vector<int>> match(n, vector<int>(n, 0)) ;
    graph g(n) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>match[i][j] ;
            if(match[i][j]){
                g.add(j, i) ;
            }
        }
    }
    g.solve() ;
    return 0 ;
}


/*
#include <bits/stdc++.h>
using namespace std ;

void solve(vector<vector<int>> &match){
    int n = match.size() ;
    vector<vector<int>> dp((1<<n), vector<int>(n, 0)) ;
    for(int i = 0 ; i < n ; i++){
        if(match[i][0]){
            dp[1<<i][0] = 1 ;
        }
    }
    int mod = 1e9+7 ;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < (1<<n) ; j++){
            for(int k = 0 ; k < n ; k++){
                if(j&(1<<k)){
                    if(match[k][i]){
                        dp[j][i] = (dp[j][i] + dp[j^(1<<k)][i-1])%mod ;
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1]<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int n = 0;
    cin>>n ;

    vector<vector<int>> match(n, vector<int>(n, 0)) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>match[i][j] ;
        }
    }
    solve(match) ;
    return 0 ;
}
*/