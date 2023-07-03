#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int squares(int n){
        int total = 0 ;
        while(n != 0){
            total = total + (n%10)*(n%10) ;
            n = n/10 ;
        }
        return total ;
    }
    bool isHappy(int n) {
        set<int> st ;
        int i = 0 ; 
        while((i < 1000) && (n < 1)){
            if(st.count(n) == 1){
                return false ;
            }
            st.insert(n) ;
            n = squares(n) ;
            i++ ;
        }
        return true ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}