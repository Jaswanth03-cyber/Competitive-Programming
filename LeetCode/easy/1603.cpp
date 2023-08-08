#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/design-parking-system/
*/
class ParkingSystem {
public:
    map<int, int> mp ;
    ParkingSystem(int big, int medium, int small) {
        mp.insert({1, big}) ;
        mp.insert({2, medium}) ;
        mp.insert({3, small}) ;
    }
    bool addCar(int carType) {
        if(mp.find(carType)->second > 0){
            mp[carType]-- ;
            return true ;
        }    
        return false ;
    }
};