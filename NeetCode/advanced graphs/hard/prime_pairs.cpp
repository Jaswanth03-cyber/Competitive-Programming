#include <bits/stdc++.h>
using namespace std ;

/*
nof of pairs (i,j) such that only one prime in the path between i and j
*/
vector<bool> isprime(1e5+2, true) ;
vector<int> primes ;
void sieve(){
    isprime[1] = false ;
    for(int i = 2 ; i*i <= 1e5+1 ; i++){
        if(isprime[i]){
            primes.push_back(i) ;
            for(int j = 2*i ; j <= 1e5+1 ; j = j + i){
                isprime[j] = false ;
            }
        }
    }
}
class disjoint_set{
    vector<int> parent ;
    vector<int> rank ;
    int vertices ;
    public:
    disjoint_set(int n){
        vertices = n ;
        parent.resize(n+1) ;
        rank.resize(n+1) ;
    }

    void make_set(int u){
        parent[u] = u ;
        rank[u] = 1 ;
    }

    void preprocess(){
        for(int i = 0 ; i <= vertices ; i++){
            make_set(i) ;
        }
    }

    int find_set(int u){
        if(u == parent[u]){
            return u ;
        }
        parent[u] = find_set(parent[u]) ;
        return parent[u] ;
    }

    void union_sets(int u, int v){
        int a = find_set(u) ;
        int b = find_set(v) ;

        if(a != b){
            if(rank[a] < rank[b]){
                swap(a, b) ;
            }
            parent[b] = a ;
            rank[a] += rank[b] ;
        }
    }

    int rankof(int u){
        return rank[u] ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    sieve() ;
    int n = 0 ;
    cin>>n ; 
    disjoint_set dsu(n) ;
    dsu.preprocess() ;
    int src, dest ;
    vector<vector<int>> adjlist ;
    adjlist.resize(n+1) ;
    for(int i = 0 ; i < n-1 ; i++){
        cin>>src>>dest ;
        if(isprime[src] && isprime[dest]){
            continue ;
        }
        else if(isprime[src]){
            adjlist[src].push_back(dest) ;
        }
        else if(isprime[dest]){
            adjlist[dest].push_back(src) ;
        }
        else{
            dsu.union_sets(src, dest) ;
        }
    }
    int size = primes.size() ;
    int ans = 0 ;
    for(int i = 0 ; i < size && primes[i] <= n ; i++){
        int count = 1 ;
        for(int j = 0 ; j < adjlist[primes[i]].size() ; j++){
            int node = adjlist[primes[i]][j] ;
            count += dsu.rankof(dsu.find_set(node)) ;
        }

        for(int j = 0 ; j < adjlist[primes[i]].size() ; j++){
            int node = adjlist[primes[i]][j] ;
            int one = dsu.rankof(dsu.find_set(node)) ;
            ans += (one)*(count - one) ;
            count -= one ;
        }
    }
    cout<<ans<<endl ;
}

/*
if both are not primes unite them if only one is prime than form an edge now after that 
following cases check the possibilities add calculate  according to it pls be careful about the repeating pairs
*/