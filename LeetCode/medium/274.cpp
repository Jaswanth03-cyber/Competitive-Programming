#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        priority_queue<int> pq ;
        int n = citations.size() ;
        int count = 0 ;
        sort(citations.begin(), citations.end()) ;
        for(int i = 0 ; i < n ; i++){
            if((n - i - 1) >= citations[i]){
                pq.push(citations[i]) ;
            }
        } 
        return pq.top() ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}