#include <bits/stdc++.h>
using namespace std ;


/*
https://codeforces.com/blog/entry/73490
*/

/*

if we want only the subsets of size k then we can do this 

can be used for subsets which does not contain first k values of the data given be carefull with the representation as it is 
32 bit representation all the 32 bits may not be used it depends on the size of the original set. 
• __builtin_clz(x): the number of zeros at the beginning of the number

can be used to subsets which does not contain last k values of the data given 
• __builtin_ctz(x): the number of zeros at the end of the number

can be used to process through the subsets of fixed size 
• __builtin_popcount(x): the number of ones in the number
  __builtin_popcountl(x) for long and __builtin_pocountll(x) for long long similarly for other

this can be used to process through the subsets who size is either even or odd
• __builtin_parity(x): the parity (even or odd) of the number of ones

*/

/*
compute the biggest power of x that divides x 
1<<__builtin_pocount(x) this will result 

compute the smallest power of 2 that is not smaller than x 
1 << (32 - __builtin_clz(x - 1))

but this is UB (undefined behavior) for x≤1
 so you'll often need an if for x==1
.
*/
