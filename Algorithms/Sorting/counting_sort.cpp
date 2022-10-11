#include<bits/stdc++.h>
using namespace std ;

// used when we know that the numbers given are integers andlie between 1 and n, where n is given 
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    cin>>n ; 

    map<int, int> freq ;
    for(int i = 1 ; i <= n ; i++){
        freq.insert({i, 0}) ;
    }
    int m ; 
    cin>>m ; 
    for(int i = 0 ; i < m ; i++){
        int a ; 
        cin>>a ; 
        auto it = freq.find(a) ;
        it->second++ ;
    }

    vector<int> final ;

    for(auto it = freq.begin() ; it != freq.end() ; it++){
        int size = it->second ;
        int key = it->first ;
        for(int i = 0 ; i < size ; i++){
            final.push_back(key) ;
        }
    }

    for(unsigned int i = 0 ; i < final.size() ; i++){
        cout<<final[i]<<" " ; 
    }
    cout<<endl ;
    return 0 ; 
}