#include<bits/stdc++.h>
using namespace std ;

vector<int> prefix_function_brute_force(string s){
    int n = s.size() ;
    vector<int> pi(n, 0);
    for(int i = 0 ; i < n ; i++){
        for(int k = 0 ; k <= i ; k++){
            if(s.substr(0, k) == s.substr(i - (k -1), k)){ // here second argument is length 
                pi[i] = k ;
            }
        }
    }
    return pi ;
}

vector<int> prefix_function(string s){
    int n = s.size() ;
    vector<int> pi(n, 0) ;
    for(int i = 1 ; i < n ; i++){
        int j = pi[i-1] ;
        while((j > 0) && (s[j] != s[i])){
            j = pi[j-1] ;
        }
        if(s[j] == s[i]){
            pi[i] = j + 1 ;
            j++ ;
        }
    }
    return pi ;
}


vector<int> find_indexes(string s, string text){

    string total = s + "$" + text ;

    vector<int> prefix = prefix_function(total) ;

    vector<int> result ; 

    for(int i = s.size() + 1 ; i < total.size() ; i++){
        if(prefix[i] == s.size()){
            result.push_back(i - 2*s.size()) ;
        }
    }
    return result ;
}


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    string sub_string = "aab" ;
    string text = "aabxaabxcaabxaabxay" ;
    vector<int> z ; 
    z = prefix_function_brute_force(text) ;
    for(int i = 0 ; i < z.size() ; i++){
        cout<<z[i]<<" " ;
    }
    cout<<endl ;

    vector<int> z1 ; 
    z1 = prefix_function(text) ;
    for(int i = 0 ; i < z1.size() ; i++){
        cout<<z1[i]<<" " ;
    }
    cout<<endl ;

    vector<int> result = find_indexes(sub_string, text) ;
    cout<<"Positions in the "<<text<<" where "<<sub_string<<" will start is : " ;
    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;

    return 0 ;
}