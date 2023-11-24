#include <bits/stdc++.h>
using namespace std ;

/*
leetcode has this optimised check for two players
*/
class Player{
    string name ;
    char UserSymbol ;

    public:
    Player(string &Name, char PlayerCharacter){
        this->name = Name ;
        this->UserSymbol = PlayerCharacter  ;
    }

    char getUserSymbol(){
        return this->UserSymbol ;
    }

    string getName(){
        return this->name ;
    }
};

class Board{
    vector<vector<char>> CharBoard ;
    int size ;

    public:
    Board(int n){
        this->size = n ;
        CharBoard.resize(n, vector<char>(n, '-')) ;
    }

    void setSymbol(int x, int y, char UserSymbol){
        board[x][y] = UserSymbol ;
    }

    char getSymbol(int x, int y){
        return board[x][y] ;
    }

    bool IsOccupied(int x, int y){
        char symbol = getSymbol(x, y) ;
        return symbol != '-' ;
    }

    void DisplayBoard(){
        // display the board 
    }

    bool check(int x, int y, char UserSymbol){
        // just check for this row, column and if it is in the diagonal and anti diagonal he won or not if yes return true else 
        // return false 
    }
};

class Game{
    Board *board ;
    queue<Player> playersQueue ;

    public:
    Game(int size, vector<string> &PlayerNames){
        board = new Board(size) ;
        int characternumber = 0 ;
        char UserCharacter ;
        int n = PlayerNames.size() ;
        int i = 0 ;
        while(i < n){
            UserCharacter = 'A' + characternumber ;
            Player player(PlayerNames[i], UserCharacter) ;
            playersQueue.push(player) ;
            i++ ;
            characternumber++ ;
        }
    }

    void makeMove(Player player){
        cout<<"Now it is your turn "<<player.getName()<<endl ;
        int x ;
        int y ;
        while(true){
            cin>>x ;
            cin>>y ;
            if(board->IsOccupied(x, y)){
                continue ;
            }
            else{
                board->setSymbol(x, y, player.getUserSymbol()) ;
                if(board->check(player.getUserSymbol(), x, y)){
                    cout<<"Player won "<<endl ;
                }
                else{
                    playersQueue.push(player) ;
                }
                break ;
            }
        } 
    }

    void Play(){

        while(playersQueue.size() > 1){
            Player player = playersQueue.front() ;
            playersQueue.pop() ;
            makeMove(player) ;
            board->DisplayBoard() ;
            // pop the player 
            // tell him to make a move after the move check if he won 
            // if he did not then push him back to the queue if so has won the game
            // do not push him back to the game
        }
    }
};