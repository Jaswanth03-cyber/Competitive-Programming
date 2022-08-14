#include<bits/stdc++.h>
using namespace std ;

int main(){
    long long n ;
    cin>>n ;

    if((n == 2) || (n == 3)){
        cout<<"NO SOLUTION"<<endl ;
    }
    else{
        vector<long long> result ; 
        for(int i = n ; i >= 1 ; i--){
            if(i%2 == 0){
                result.push_back(i) ;
            }
        }
        reverse(result.begin(), result.end()) ;
        vector<long long> result_1 ;
        for(int i = n ; i>= 1 ; i--){
            if(i%2 !=0){
                result_1.push_back(i) ;
            }
        }
        reverse(result_1.begin(), result_1.end()) ;
        int n = result.size() ;
        for(int i = 0 ; i < n  ; i++){
            cout<<result[i]<<" " ;
        }
        int n1 = result_1.size() ;
        for(int i = 0 ; i < n1  ; i++){
            cout<<result_1[i]<<" " ;
        }
        cout<<endl ;
    }
    return 0 ;
}