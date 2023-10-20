#include <bits/stdc++.h>
using namespace std ;

typedef pair<int, int> pi ;

int gcd(int a, int b){
    if(a < b){
        int temp = a ;
        a = b ;
        b = temp ;
    }
    while(b > 0){
        int temp = b%a ;
        a = b ;
        b = temp ;
    }
    return a ;
}

pi change(pi a){
    int first = abs(a.first), second = abs(a.second) ;
    int hcf = gcd(first, second) ;
    pi ans ;
    if(a.first*b.first < 0){
        ans = {-(first/hcf), (second/hcf)} ;
    }
    else{
        ans = {first/hcf, second/hcf} ;
    }
    return ans ;
}
struct comp{
    bool operator()(const pi& a, const pi &b)const{
        return change(a) < change(b) ;
    }
};

struct comp2{
    bool operator()(float & a, float  &b)const{
        return fabs(a-b) < FLT_EPSILON ;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        map<pair<int, int>, int, comp> mp ;
        map<float, int, comp2> mp1 ;
        int incount = 0, zerocount = 0 ;

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                pi temp = {points[i].second - points[j].second, points[i].first - points[j].first} ;
                if(points[i].second == points[j].second){
                    zerocount++ ;
                    continue ;
                }
                if(points[i].first == points[j].first){
                    infcount++ ;
                    continue ;
                }
                mp1[float((points[i].second - points[j].second)/(points[i].first - points[j].first))]++ ;
                // mp[temp]++ ;
            }
        }
        int ans = 0 ;
        for(auto it = mp1.begin() ; it != mp1.end() ; it++){
            ans = max(ans, it->second) ;
        }
        int sqr = sqrt(1+8*ans) ;
        int res = (1+sqr)/2 ;
        return res ;
    }
};