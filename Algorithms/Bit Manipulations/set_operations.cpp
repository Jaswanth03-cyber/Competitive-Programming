#include<bits/stdc++.h>
using namespace std ;

/*
Set operations can be implemented as follows as bit operations:
set             syntax    bit syntax
intersection     a ∩ b      a & b
union            a ∪ b      a | b
complement         a¯         ~a
difference       a \ b      a & (~b)

For example, the following code first constructs the sets x = {1,3,4,8} and
y = {3,6,8,9}, and then constructs the set z = x∪ y = {1,3,4,6,8,9}:
*/

void func(){
    int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
    int y = (1<<3)|(1<<6)|(1<<8)|(1<<9);
    int z = x|y;
    cout << __builtin_popcount(z) << "\n"; // 6
    for(int i = 0 ; i < 32 ; i++){
        if(z&(1<<i)){
            cout<<i<<" " ;
        }
    }
    cout<<endl ;
}