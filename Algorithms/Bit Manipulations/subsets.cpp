#include <bits/stdc++.h>
using namespace std ;

/*
Note always we need not have j < 32 we can have j < n where n is the size of the original set as
number of possible subsets is power(2, n) 
*/

/*
Every subset of a set {0,1,2,...,n−1} can be represented as an n bit integer whose
one bits indicate which elements belong to the subset. This is an efficient way to
represent sets, because every element requires only one bit of memory, and set
operations can be implemented as bit operations.
For example, since int is a 32-bit type, an int number can represent any
subset of the set {0,1,2,...,31}. The bit representation of the set {1,3,4,8} is
to process through all the subsets of 

For example, since int is a 32-bit type, an int number can represent any
subset of the set {0,1,2,...,31}. The bit representation of the set {1,3,4,8} is
00000000000000000000000100011010
indexing from left to right 32-0
{0, 1, 2, 3, ... n-1}
where n is the size and n <= 32 

to process a subset x which is a subset of a vector data which has some n elements and n <= 32
for(int i = 0 ; i < 32 ; i++){
    if(x&(1<<i)){
        cout<<data[i]<<" " ;
    }
}
cout<<endl ;
*/

void represent(){
    int x = 0 ;
    x = x|(1<<1) ;
    x = x|(1<<3) ;
    x = x|(1<<4) ;
    x = x|(1<<8) ;

// print an x that can contain elements {1, 3, 4, 8}
    cout<<x<<" "<<__builtin_pocount(x)<<endl; 

    for(int i = 0 ; i < 32 ; i++){
        if(x&&(1<<i)){
            cout<<i<<" " ;
        }
    }
    cout<<endl ;
}
void func(int n){
    vector<vector<int>> powerset ;
    for(int i = 0 ; i < (1<<n) ; i++){  // so i < (1<<n) which means i is less than power(2, n) so from i = 0 to power(2,n) we go through all the subsets
        vector<int> subset ;
        for(int j = 0 ; j < 32 ; j++){
            if(i&(1<<j)){             // as i is of 32 bit representation so if jth bit is zero that number is present in the current subset we are processing
                subset.push_back(j) ;
            }
        }
        powerset.push_back(subset) ;
    }
}
/*
we can extend to this to a vector of n elements so a jth element of a vector will be in the ith subset if
(i&(1<<j)) is one 
*/

void solve(int n, vector<int> &data){
    vector<vector<int>> powerset ;

    for(int i = 0 ; i < (1<<n) ; i++){
        vector<int> subset ;
        for(int j = 0 ; j < 32 ; j++){
            if(i&(1<<j)){
                subset.push_back(data[j]) ;
            }
        }
        powerset.push_back(subset) ;
    }
}

/*
lets say we have elements from 1 to 32 and we want to remove an element i form a particular subset so i will be corresponding to the i-1th bith from 
right so lets take the binary representation of it which is 1<<(i-1) now this is a set we have two sets we need a-b so do a^b similarly
for lets say a vector of elements first find the bit which represents the element and do corresponding operations. if we want to add an element
then do or. two sets a and b a union b. 
if you want to remove an element from a subset lets say an element i 
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

this can be used to process through the subsets who size is either even or odd
• __builtin_parity(x): the parity (even or odd) of the number of ones


*/

void solve_k(int n, vector<int> &data, int k){
    vector<vector<int>> subsets_k ; // subsets of size k 

    for(int i = 0 ; i < (1<<n) ; i++){
        vector<int> subset ;
        if(__builtin_popcount(i) == k){ // porcess the subsets whose count will be k that is bit representations of i must have exactly k 1s
            for(int j = 0 ; j < 32 ; j++){
                if(i&(1<<j)){
                    subset.push_back(data[j]) ;
                }
            }
        }
        subsets_k.push_back(subset) ;
    }
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    int k = 0 ;

    vector<int> data(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>data[i] ;
    }

    func(n) ;
    solve(n, data) ;
    solve_k(n, data, k) ;
    return 0 ;
}

/*
It is also possible to modify single bits of numbers using similar ideas. For
example, the formula x | (1 << k) sets the kth bit of x to one, the formula x &
~(1 << k) sets the kth bit of x to zero, and the formula x ^ (1 << k) inverts the
kth bit of x.

The formula x & (x−1) sets the last one bit of x to zero, and the formula x &
−x sets all the one bits to zero, except for the last one bit. The formula x | (x−1)
inverts all the bits after the last one bit. Also note that a positive number x is a
power of two exactly when x & (x−1) = 0.
~x = (-x-1)

 
n & (n + 1) clears all trailing ones:  
00110111 -> 00110000 .
 
n | (n + 1)  sets the last cleared bit:  
00110101 -> 00110111
 
n & -n  extracts the last set bit:  
00110100 -> 00000100 .
n         = 01011000
n-1       = 01010111
--------------------
n & (n-1) = 01010000
n         = 01011000
n-1       = 01010111
--------------------
n | (n-1) = 01011111
n         = 01011000
n-1       = 01010111
--------------------
n ^ (n-1) = 00001111
n         = 01011000
--------------------
~n        = 10100111

*/