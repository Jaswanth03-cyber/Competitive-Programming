#include<bits/stdc++.h>
using namespace std ;

typedef pair<int, int> pi ;
int gcd(int x, int y){
    int a, b, r;
    if(x > y){
        a = x;
        b = y;
    }
    else{
        a = y;
        b = x;
    }
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
class Solution {
public: 
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1){
            return 1 ; 
        }
        if(points.size() == 2){
            return 2 ;
        }
        map<pi, int> mp ;
        int maximum = -1 ;
        int temp = 0 ;
        pi point ;
        for(int i = 0 ; i < points.size() ; i++){
            for(int j = 0 ; j < points.size() ; j++){
                if(j != i){
                    if(points[j][0] == points[i][0]){
                        point = {0,0} ;
                        if(mp.count(point) == 0){
                            mp.insert({point,2}) ;
                        }
                        else{
                            mp.find(point)->second++ ;
                        }
                        continue ;
                    }
                    temp = gcd(points[j][0] - points[i][0],points[j][1] - points[i][1]) ;
                    point = {points[j][0] - points[i][0]/temp,points[j][1] - points[i][1]/temp} ;
                    if(mp.count(point) == 0){
                        mp.insert({point,2}) ;
                    }
                    else{
                        mp.find(point)->second++ ;
                    }
                }
            }
            for(auto it = mp.begin(); it != mp.end() ; it++){
                maximum = max(maximum, it->second) ;
                cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl; 
            }
            mp.clear() ;
        } 
        return maximum ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ; 
    cin>>n ; 

    vector<vector<int>> points ;
    points.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        points[i].resize(2) ;
        cin>>points[i][0] ;
        cin>>points[i][1] ;
    }

    Solution ans ;
    int result = ans.maxPoints(points) ;

    cout<<result<<endl ;
    return 0 ;
}