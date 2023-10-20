#include <bits/stdc++.h>
using namespace std ;

/*
https://www.interviewbit.com/problems/snake-ladder-problem/
*/

int bfs(vector<vector<int>> &a, vector<vector<int>> &b){
    map<int, int> ladders ;
    map<int, int> snakes ;
    vector<bool> visited(101, false) ;
    int size = a.size() ;
    int i = 0 ;
    while(i < size){
        ladders.insert({a[i][0], a[i][1]}) ;
        i++ ;
    }
    i = 0 ;
    size = b.size() ;
    while(i < size){
        snakes.insert({b[i][0], b[i][1]}) ;
        i++ ;
    }
    queue<pair<int, int>> pq ;
    pq.push(make_pair(0, 1)) ;
    while(!pq.empty()){
        int step = pq.front().first ;
        int node = pq.front().second ;
        pq.pop() ;
        if(node == 100){
            return step ;
        }
        visited[node] = true ;
        if(ladders.find(node) != ladders.end()){
            pq.push(make_pair(step, ladders[node])) ;
            visited[ladders[node]] = true ;
            continue ;
        }
        else if(snakes.find(node) != snakes.end()){
            pq.push(make_pair(step, snakes[node])) ;
            visited[snakes[node]] = true ;
            continue ;
        }
        for(int j = 1 ; j < 7 ; j++){
            if(node+j <= 100){
                
            
                if(!visited[node+j]){
                    pq.push(make_pair(step+1, node+j)) ;
                    visited[node+j] = true ;
                }
            }
        }
    }
    return -1 ;
}
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    int ans = bfs(A, B) ;
    return ans ;
}

/*
having snakes and ladder as a map which will be easy to access whether there is a ladder or a snake at a cell so if we reach cell 100 return steps
if we find a ladder at a node move to the ending cell of the ladder and update the distance of it and also make it visited if snake is present go 
to the tail update the distance over there if not both then go with the dice if not visited then that will be the minimum distance just push to the 
queue and update visited in the array if so 100 is not visited return -1, even though whenever you reach the same cell again it will either take you 
same number of steps or take more number of steps to reach that cell than before.
*/