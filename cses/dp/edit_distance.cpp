#include<bits/stdc++.h>
using namespace std ;
#define MAX 1e5 
int edit_distance(string a, string b){

    vector<vector<int>> distance ;
    string input_1 = " " + a ;
    string input_2 = " " + b ;

    int n = input_1.size() ;
    int m = input_2.size() ;

    distance.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        distance[i].resize(m) ;
    }
    for(int i = 0 ; i < n ; i++){
        distance[i][0] = i ;
    }
    for(int i = 0 ; i < m ; i++){
        distance[0][i] = i ;
    }

    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            int cost ;
            if(input_1[i] == input_2[j]){
                cost = 0 ;
            }
            else{
                cost = 1 ;
            }
            int minimum ; 
            minimum = min(distance[i-1][j], distance[i][j-1]) +1 ;
            distance[i][j] = min(minimum, distance[i-1][j-1] + cost) ;
        }
    }

    return distance[n-1][m-1] ;
}



int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; 
    string a ;
    string b ; 
    cin>>a ; 
    cin>>b ; 
    int distance = edit_distance(a, b) ;
    cout<<distance<<endl ;
    return 0 ;
}