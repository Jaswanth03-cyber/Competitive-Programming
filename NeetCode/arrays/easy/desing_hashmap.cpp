#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/design-hashmap/
*/

class MyHashMap {
public:
    map<int, int> mp ;
    MyHashMap() {
        mp.clear() ;   
    }
    
    void put(int key, int value) {
        if(mp.count(key) == 1){
            mp[key] = value ;
        }   
        else{
            mp.insert({key, value}) ;
        }
    }
    
    int get(int key) {
        if(mp.count(key) == 1){
            return mp[key] ;
        }  
        else{
            return -1 ;
        }
    }
    
    void remove(int key) {
        if(mp.find(key) != mp.end()){
            mp.erase(mp.find(key)) ; 
        }
        return ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}