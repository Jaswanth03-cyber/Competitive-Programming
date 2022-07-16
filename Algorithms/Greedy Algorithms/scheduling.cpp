/*
Let us now consider a problem where we are given n tasks with durations and
deadlines and our task is to choose an order to perform the tasks. For each task,
we earn d − x points where d is the task’s deadline and x is the moment when we
finish the task. What is the largest possible total score we can obtain?

Surprisingly, the optimal solution to the problem does not depend on the
deadlines at all, but a correct greedy strategy is to simply perform the tasks
sorted by their durations in increasing order. The reason for this is that if we
ever perform two tasks one after another such that the first task takes longer
than the second task, we can obtain a better solution if we swap the tasks. For
example, consider the following schedule:

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std ;

vector<char> scheduling(int duration[], int deadlines[], char task[], int n){
    vector<tuple<int, int, char>> schedule(n) ;

    for(int i = 0 ; i < n ; i++){
        schedule[i] = {duration[i], deadlines[i], task[i]} ;
    }

    sort(schedule.begin(), schedule.end()) ;     // by  default sorted by the first one 

    vector<char> res ;

    for(int i = 0 ; i < n ; i++){
        res.push_back(get<2>(schedule[i])) ;
    }

    return res ;
}
// even if duration is same for two tasks it does not matter which u do first u will result in same cost/profit finally
int main(){
    int deadlines[] = {2, 5, 7, 5} ;
    int durations[] = {4, 3, 2, 4} ;
    char tasks[] = {'A', 'B', 'C', 'D'} ;
    int n = sizeof(deadlines)/sizeof(deadlines[0]) ;
    vector<char> final ;
    final = scheduling(durations, deadlines,tasks, n ) ;

    for(int i = 0 ; i < final.size() ; i++){
        cout<<final[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}