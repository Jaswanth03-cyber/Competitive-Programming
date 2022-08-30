#include<bits/stdc++.h>
using namespace std ;


int solve(int rows, int columns){

    if(columns > rows){
        int temp = columns ; 
        columns = rows ; 
        rows = temp ;
    }

    vector<vector<int>> min_cuts ;

    min_cuts.resize(rows + 1) ;
    int max_value = 1e9 ;
    for(int i = 0 ; i <= rows ; i++){
        min_cuts[i].resize(columns + 1) ;
        fill(min_cuts[i].begin(), min_cuts[i].end(), max_value) ;
    }

    for(int i = 1 ; i <= rows ; i ++){
        for(int j = 1 ; j <= columns ; j++){
            if(i == j){
                min_cuts[i][j] = 0 ;
            }
            else{
                // horizontal cut 

                for(int k = 1 ; k < i ; k++){
                    int cut = 1 + min_cuts[k][j] + min_cuts[i-k][j] ;
                    min_cuts[i][j] = min(min_cuts[i][j], cut) ;
                }
                // vertical cut
                for(int k = 1 ; k < j ; k++){
                    int cut = 1 + min_cuts[i][k] + min_cuts[i][j-k] ;
                    min_cuts[i][j] = min(min_cuts[i][j], cut) ;
                }
            }
        }
    }

    return min_cuts[rows][columns] ;
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int rows ; 
    int columns ; 

    cin>>rows ;
    cin>>columns ;

    int result = solve(rows, columns) ;

    cout<<result<<endl ;
    return 0 ;
}