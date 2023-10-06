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
void numberofsubstrings(string s){
    vector<int> pi = prefix_function(s) ;
    int n = s.length() ;
    // ans[i] denotes number of times substring from 0 to i occurs in the string
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++; // so this is clear counting number of times the prefix of length pi[i] occurs as a suffix in the substring 0 to i 
    for (int i = n-1; i > 0; i--)
        ans[pi[i-1]] += ans[i]; 
    for (int i = 0; i <= n; i++)
        ans[i]++; // this is the original substring itself
/*
for second loop
so now if we see that for a position at i if pi[i] is the length of the prefix of the substring the contains in s[0...i], 
we can also see that pi[i-1] length substring is also contained in s[0...i] so we are counting those we are counting from back to 
not include some substrings multiple times. 
as for example if you do from 0 then every prefix includes two times 
*/
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