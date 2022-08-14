/*
Here in this method basically we use hashing we will be given a substring and text if we have string s in t then we have to print the
starting indexes in the t where string s is present 
*/
#include<bits/stdc++.h>
using namespace std ;

vector<int> rabin_karp(string s, string t){
    vector<int> result ;
    long long int p = 31 ;
    long long int m = 1e9 + 9 ;

    if(s.size() == 1){
        for(int i = 0 ; i < t.size() ; i++){
            if(t[i] == s[0]){
                result.push_back(i) ;
            }
        }
        return result ;
    }

    vector<long long int> pow_p(max(s.size(), t.size())) ;
    pow_p[0] = 1 ;
    for(int i = 1 ; i < pow_p.size() ; i++){
        pow_p[i] = (pow_p[i-1]*p)%m ;
    }

    long long int hash_s = 0 ;
    for(int i = 0 ; i < s.size() ; i++){
        hash_s = hash_s + (pow_p[i]*(s[i] - 'a' + 1))%m ;
    }

    vector<long long int> hash_t(t.size(), 0) ;
    hash_t[0] = (t[0] - 'a' + 1)%m ;
    for(int i = 1 ; i < hash_t.size() ; i++){
        hash_t[i] = (hash_t[i-1] + pow_p[i]*(t[i] - 'a' + 1))%m ;
    }

    long long int current_hash = hash_t[s.size() - 1] ;
    long long int current_hash_s_0 = (hash_s)*pow_p[0] ;
    if(current_hash == current_hash_s_0){
        result.push_back(0) ;
    }
    for(int i = 1 ; i <=t.size() - s.size() ; i++){
        long long int current_hash = (hash_t[i + s.size() - 1] - hash_t[i-1])%m ;
        long long int current_hash_s_i = (hash_s*pow_p[i])%m ;
        if(current_hash == current_hash_s_i){
            result.push_back(i) ;
        }
    }
    return result ;
}


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    string s = "ab" ;
    string text = "abccbaabcccabcab" ;

    vector<int> result = rabin_karp(s, text) ;

    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}