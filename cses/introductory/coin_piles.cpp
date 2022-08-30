#include<bits/stdc++.h>
using namespace std ;

string solve(int a, int b){
    string yes = "YES" ;
    string no = "NO" ;

    if((2*a == b) || (2*b == a)){
        return yes ;
    }
    else if((2*a - b < 0) || (2*b - a < 0)){
        return no ;
    }
    else{
        if(((2*a - b)%3 != 0) || ((2*b - a)%3 != 0)){
            return no ;
        }
        else{
            return yes ;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int t ; 
    cin>>t ; 

    for(int i = 1 ; i <= t ; i++){
        int a ; 
        int b ; 
        cin>>a>>b ;

        string result = solve(a,b) ;

        cout<<result<<endl ;
    }

    return 0 ;
}