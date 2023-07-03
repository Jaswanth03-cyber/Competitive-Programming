#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/valid-sudoku/
*/

/*
What I have done is that I have taken a character sets of row and column and I am re using those every time 
if there is no dot then just checked if that number is already there then set the stop to be true and broke the inside loop so if stop is true 
then we have to return so I am using this top variable if this stop is true then return false so I have broken the loop 

and for each box I have maintained a character set in a matrix 
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool stop = false ;
        bool ans = true ;
        set<char> row ;
        set<char> column ;
        vector<vector<set<char>>> box ;
        box.resize(3) ;
        for(int i = 0 ; i < 3 ; i++){
            box[i].resize(3) ;
        }
        int a = 0 ;
        int b = 0 ;
        for(int i = 0 ; i < 9 ; i++){
            a = i/3 ;
            for(int j = 0 ; j < 9 ; j++){
                b = j/3 ;
                if(board[i][j] != '.'){
                    if(row.count(board[i][j]) == 1){
                        stop = true ;
                        break ;
                    }
                    else{
                        row.insert(board[i][j]) ;
                    }
                    if(box[a][b].count(board[i][j]) == 1){
                        stop = true ;
                        break ;
                    }
                    else{
                        box[a][b].insert(board[i][j]) ;
                    }
                }
                if(board[j][i] != '.'){
                    if(column.count(board[j][i]) == 1){
                        stop = true ;
                        break ;
                    }
                    else{
                        column.insert(board[j][i]) ;
                    }
                }
            }
            if(stop){
                ans = false ;
                break ; 
            }
            row.clear() ;
            column.clear() ;
        }
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    vector<vector<char>> board ;
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cin>>board[i][j] ;
        }
    }

    Solution ans ;
    bool result = ans.isValidSudoku(board) ;

    cout<<result<<endl ;
    return 0 ;
}