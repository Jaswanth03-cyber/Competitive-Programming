#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/seat-reservation-manager/
*/

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> pq ;
public:
    SeatManager(int n) {
        for(int i = 1 ; i <= n ; i++){
            pq.push(i) ;
        }   
    }
    int reserve() {
        int a = pq.top() ;
        pq.pop() ;
        return a ;   
    }
    void unreserve(int seatNumber) {
        pq.push(seatNumber) ;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}