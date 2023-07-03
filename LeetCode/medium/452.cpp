#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/

/*
I have sorted the points in the order of starting of x position so now what I have done is that I have checked the number of intervals that are 
in common so starting from first interval I have taken the end position of the first interval so now if the next balloon starting point is inside
the before balloons interval and if so the current second is also inside the before balloons interval then I have to change the second which is 
present in the else condition, if so the currents first is greater than the ending point of previous ballon then there is no overlap of intervals
so have to update the second and number of arrows also increases 


    lets say first ballon is from 1 to 11 
    and second balloon is from 2 to 4 and third balloon is from 5 to 8 
    so now if there is no else condition then what our logic will give is that for ballon 1,2,3 just one arrow is enough which is false
    we need two arrows as even though 2 is overlapping with 1 and 3 is overlapping with 1 2 and 3 are not so thats why I have kept another
    condition that if current is completely inside the before one I have updated the second to check next one 

    pls be careful for equality condition just check it properly 

    for first ballon 1 to 2 and next balloon 2-4 we just need 1 its enough it just touches at the edge so just pq.top().first > second so no need of =
    1  2  3  4  5  6  7  8  9  10  11  12  13  14
*/


typedef pair<int, int> pi ;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int first = 0 ;
        int second = 0 ;
        int ans = 1 ;
        priority_queue<pi, vector<pi>, greater<pi>> pq ;
        for(int i = 0 ; i < points.size() ; i++){
            pq.push(make_pair(points[i][0], points[i][1])) ;
        }
        first = pq.top().first ;
        second = pq.top().second ;
        pq.pop() ;
        while(!pq.empty()){
            if(pq.top().first > second){
                // first = pq.top().first ;
                second = pq.top().second ;
                ans++ ;
            }
            else{
                if(pq.top().second <= second){
                    second = pq.top().second ;
                }
            }
            pq.pop() ;
        }
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<vector<int>> points ;
    points.resize(n) ;
    int a = 0 ;
    int b = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin>>a ;
        cin>>b ;
        points[i].push_back(a) ;
        points[i].push_back(b) ;
    }
    Solution ans ;
    int result = ans.findMinArrowShots(points) ;
    cout<<result<<endl ;
    return 0 ;
}