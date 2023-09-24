#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
*/

/*
couting keys with same width/height using map pair as key and comparator functions now after that in each category if there are 
n rectangles whose ratio is same then nc2 possible pairs adding all those
*/
int gcd(int a, int b){
    while(a != b){
        if(a > b){
            a = a - b ;
        }
        else{
            b = b - a ;
        }
    }
    return a ;
}
pair<int, int> simplify(const pair<int, int> &key){
    int one = key.first ;
    int two = key.second ;
    int hcf = gcd(one, two) ;
    return make_pair(one/hcf, two/hcf) ;
}
struct comp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
        return simplify(a) < simplify(b) ;
    }
};
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0 ;
        map<pair<int, int>, long long, comp> mp ;

        int n = rectangles.size() ;
        for(int i = 0 ; i < n ; i++){
            mp[{rectangles[i][0], rectangles[i][1]}]++ ;
        } 

        for(auto it = mp.begin() ; it != mp.end() ; it++){
            ans = ans + (it->second*(it->second-1))/2 ;
        }
        return ans ;   
    }
};