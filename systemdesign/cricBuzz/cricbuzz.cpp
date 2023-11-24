#include <bits/stdc++.h>
using namespace std ;

struct Address{
    string line1 ;
    string line2 ;
    string city ;
    string country ;
    string pincode ;
};

struct Person{
    string FirstName ;
    string LastName ;
    struct Address adress ;
    string DateOfBirth ;
};

enum MatchResult{
    Live,
    Finished,
    Drawn,
    Cancelled 
};

enum MatchFormat{
    ODI,
    T20,
    TEST
};

enum UmpireType{
    Field,
    Reserved,
    TV
};

enum WicketType{
    Bowled,
    Caught,
    Stumped,
    RunOut,
    LBW,
    RetiredHut,
    HitWicket,
    Obstructing,
    Timeout
};

enum BallType{
    Normal,
    Wide,
    Wicket,
    NoBall
};

enum RunType{
    Normal,
    Four,
    Six,
    LegBye,
    OverThrow,
    Bye
};

class PlayerContract{
    string startdate ;
    string enddate ;

    public:
    void CancelContract(){

    }
};

class Player{

    struct Person person ;
    list<PlayerContract> playerContracts ;
    public:

    void addConntract(){

    }
};

class BallBowled{
    Player BallBowledBy ;
    Player BallPlayedBy ;
    BallType balltype ;

    public:
    void addCommentry(){

    }
};

class Run{
    int totalruns ;
    RunType runtype ;
};

class Over{
    int overnumber ;
    
    public:
    void addBall(){} 
};

class Inning{
    int InningNumber ;
    string StartTime ;
    string EndTime ;

    public:
    void addOver(){} 
};

class Match{
    string Date ;
    MatchResult result ;

    public:
    void AssignStadium() ;
};

class Test : public Match{

};

class ODI : public Match{
    
};

class T20 : public Match{
    
};

class Admin{
    struct Person person ;

    public:

    void AddTeam() ;
    void AddPlayer() ;
    void AddMatch() ;
    void AddTournament() ;
    void AddStadium() ;
};

class Team{} 

class Tournament{} ;

class PointsTable{} ;

class Coach{} ;

class TournamentSquad{};

class PlayingSquad{};

class Stat {

    public:
    void addStat() ;
} ;

class Tournamenstat : public Stat {};

class MatchStat : public Stat {} ;

class TeamStat : public Stat {} ;

class PlayerStat : public Stat {} ;


