#include <bits/stdc++.h>
using namespace std ;

/*
my implementation is bit different from the diagram 
*/
class Player{
    int id ;
    string name ;
    int currposition ;
    public:
    Player(int a, string s){
        this->id  = a ;
        this->name = s ;
        this->currposition = 1 ; 
    }

    void setposition(int value){
        this->currposition = value ;
    }

    string Name(){
        return this->name ;
    }

    int Position(){
        return this->currposition ;
    }
};

class Players{
    int noofplayers ;

    public:
    queue<Player> playersqueue ;

    Players(vector<string> &playernames){
        int counter = 1 ;
        int m = playernames.size() ;
        noofplayers = m ;
        for(int i = 0 ; i < m ; i++){
            playersqueue.push(Player(counter++, playernames[i])) ;
        }
    }
};
class Dice{
    int noofdice ;
    public:
    Dice(int n){
        noofdice = n ;
    }

    int rolldice(){
        srand(time(0)) ;
        int up = 6*n ;
        int low = n ;
        int num = rand()%(up - low + 1) + low ;
        return num ;
    }
};

class Jumper{

    map<int, int> mp ;

    public:

    void add(int src, int dest){
        mp.insert({src, dest}) ;
    }

    Jumper(vector<vector<int>> &positions){
        mp.clear() ;
        int m = positions.size() ;
        for(int i = 0 ; i < m ; i++){
            add(positions[i][0], positions[i][1]) ;
        }
    }

    int check(int src){
        if(mp.find(src) != mp.end()){
            return mp.find(src)->second ;
        }
        return 0 ;
    }
};

class Board{
    int size ;
    Jumper* snakes ;
    Jumper* ladders ;

    public:
    Board(int n, vector<vector<int>> &snakepositions, vector<vector<int>> &ladderpositions){
        this->size = n ;
        snakes = new Jumper(snakepositions) ;
        ladders = new Jumper(ladderpositions) ;
    }

    int Size(){
        return this->size ;
    }

    int checksnake(int src){
        return snakes->check(src) ;
    }

    int checkladder(int src){
        return ladders->check(src) ;
    }
};

class Game{

    Board *board ;
    Dice *dice ;
    Players* players ;

    public:

    Game(int noofdice, int sizeofboard, vector<vector<int>> &snakepositions, vector<vector<int>> &ladderpositions, vector<string> &playernames){
        dice = new Dice(noofdice) ;
        board = new Board(sizeofboard, snakepositions, ladderpositions) ;
        players = new Players(playernames) ;
    }

    void play(){
        int standing = 1 ;
        while(players->playersqueue.size() > 1){
            Player currplayer = players->playersqueue.front() ;
            players->playersqueue.pop() ;

            cout<<currplayer.Name() + " its your turn: "<<endl ;
            int dicevalue = dice->rolldice() ;
            int currposition = currplayer.Position() ;

            int nextposition = dicevalue + currposition ; 
            if(nextposition == board->Size()){
                cout<<"Congratulations !!! You have finished the game with the position "<<standing++<<endl ;
            }
            else if(nextposition > board->Size()){
                playersqueue.push(currplayer) ;
            }
            else{
                if(board->checksnake(nextposition)){
                    int finalposition = nextposition - board->checksnake(nextposition) ;
                    currplayer.setposition(finalposition) ;
                    cout<<"You have been bit by a snake you have to move to "<<finalposition<<endl ;
                    players->playersqueue.push(currplayer) ;
                }
                else if(board->checkladder(nextposition)){
                    int finalposition = nextposition  - board->checkladder(nextposition) ;
                    cout<<"You have to climb a ladder which takes you to the position "<<finalposition<<endl ;
                    if(finalposition == board->Size()){
                        cout<<"Congratulations !!! You have finished the game with the position "<<standing++<<endl ;
                    }
                    else{
                        currplayer.setposition(finalposition) ;
                        players->playersqueue.push(currplayer) ;
                    }
                }
                else{
                    players->playersqueue.push(currplayer) ;
                }
            }
        }
    }
};