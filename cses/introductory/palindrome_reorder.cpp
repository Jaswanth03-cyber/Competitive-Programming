#include <bits/stdc++.h>
using namespace std ;

string palindrome(string &arr){
    string no = "NO SOLUTION" ;
    int n = arr.size() ;
    map<char, int> freq ;

    for(int i = 0 ; i < 26 ; i++){
        char ch = i + 65 ;
        freq.insert({ch, 0}) ;
    }
    for(int i = 0 ; i < n ; i++){
        auto it = freq.find(arr[i]) ;
        it->second++ ;
    }

    string start = "" ;
    string ending = "" ;
    string middle = "" ;
    int count = 0 ;
    for(auto it = freq.begin() ; it != freq.end() ; it++){
        if(it->second == 0){
            continue ;
        }
        if(it->second%2 == 1){
            count++ ;
            if(n%2 == 1){
                if(count > 1){
                    return no ;
                }
            }
            else{
                if(count >= 1){
                    return no ;
                }
            }
            string str(it->second, it->first) ;
            middle = middle + str ;
        }
        else{
            string str(it->second/2, it->first) ;
            start = start + str ;
            ending = ending + str ;
        }
    }

    reverse(ending.begin(), ending.end()) ;

    string result = start + middle + ending ;

    return result ; 
}


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string input ; 
    cin>>input ; 

    string result = palindrome(input) ;
    cout<<result<<endl ;


    return 0 ;
}