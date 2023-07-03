#include<bits/stdc++.h>
using namespace std ;

void Swap(char &a, char &b){
    char temp ;
    temp = b ;
    b = a ;
    a = temp ;
    return ;
}
void solve(string &s, set<string> &result, int low, int high){
    if(low == high){
        if(result.count(s) == 0){
            result.insert(s) ;
        }

        return ;
    }
    for(int i = low ; i <=high ; i++){
            Swap(s[low], s[i]) ;
            solve(s, result, low +1 , high) ;
            Swap(s[low], s[i]) ;
    }
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string arr ; 
    cin>>arr ; 

    int n = arr.size() ;

    set<string> result ;

    solve(arr, result, 0, n-1) ;

    cout<<result.size()<<endl ;

    for(auto it = result.begin() ; it != result.end() ; it++){
        cout<<*it<<endl ;
    }


    return 0 ;
}