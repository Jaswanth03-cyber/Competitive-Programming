#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/k-closest-points-to-origin/
*/

typedef pair<int, vector<int>> pi ;
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi, vector<pi>, greater<pi>> pq ;
        int distance = 0 ;
        vector<vector<int>> ans ;
        for(int i = 0 ; i < points.size() ; i++){
            distance = (points[i][0]*points[i][0] + points[i][1]*points[i][1]) ;
            pq.push(make_pair(distance, points[i])) ;
        }
        int i = 0 ;
        while(i < k){
            ans.push_back(pq.top().second) ;
            pq.pop() ;
            i++ ;
        }
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}