#include <bits/stdc++.h>
using namespace std ;

bool check(int x, int y){
    if(x^y){
        return false ;
    }
    return true ;
}

// xor of two positive or two negative will be 0 where as opposite will be 1 