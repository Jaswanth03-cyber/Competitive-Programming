#include <bits/stdc++.h>
using namespace std ;

/*
https://www.interviewbit.com/problems/min-cost-path/    
*/
int Solution::solve(int A, int B, vector<string> &C) {
    int n = A, m = B ;
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX)) ;
    distance[0][0] = 0 ;    
    set<pair<int, int>> st ;
    st.insert({0, 0}) ;
    
    while(!st.empty()){
        int x = st.begin()->first ;
        int y = st.begin()->second ;
        st.erase(st.begin()) ;
        
        if(x != 0){
            if(C[x][y] != 'U'){
                if(distance[x-1][y] > distance[x][y] + 1){
                    st.erase({x-1, y}) ;
                    distance[x-1][y] = distance[x][y] + 1 ;
                    st.insert({x-1, y}) ;
                }
            }
            else if(distance[x-1][y] > distance[x][y]){
                st.erase({x-1, y}) ;
                distance[x-1][y] = distance[x][y] ;
                st.insert({x-1, y}) ;   
            }
        }
        if(x != n-1){
            if(C[x][y] != 'D'){
                if(distance[x+1][y] > distance[x][y] + 1){
                    st.erase({x+1, y}) ;
                    distance[x+1][y] = distance[x][y] + 1 ;
                    st.insert({x+1, y}) ;
                }
            }
            else if(distance[x+1][y] > distance[x][y]){
                st.erase({x+1, y}) ;
                distance[x+1][y] = distance[x][y] ;
                st.insert({x+1, y}) ;   
            }
        }
        if(y != 0){
            if(C[x][y] != 'L'){
                if(distance[x][y-1] > distance[x][y] + 1){
                    st.erase({x, y-1}) ;
                    distance[x][y-1] = distance[x][y] + 1 ;
                    st.insert({x, y-1}) ;
                }
            }
            else if(distance[x][y-1] > distance[x][y]){
                st.erase({x, y-1}) ;
                distance[x][y-1] = distance[x][y] ;
                st.insert({x, y-1}) ;   
            }
        }
        if(y != m-1){
            if(C[x][y] != 'R'){
                if(distance[x][y+1] > distance[x][y] + 1){
                    st.erase({x, y+1}) ;
                    distance[x][y+1] = distance[x][y] + 1 ;
                    st.insert({x, y+1}) ;
                }
            }
            else if(distance[x][y+1] > distance[x][y]){
                st.erase({x, y+1}) ;
                distance[x][y+1] = distance[x][y] ;
                st.insert({x, y+1}) ;   
            }
        }
    }
    return distance[n-1][m-1] ;
}

/*
as it is 0/1 bfs we can use a set/dequeu anything is fine so whenever a less distance one is available just update it at the end just return 
the distance[n-1][m-1].     
*/
