#include<bits/stdc++.h>
using namespace std ;

/*
The Hamming distance hamming(a,b) between two strings a and b of equal
length is the number of positions where the strings differ. For example,
hamming(01101,11001) = 2.
Consider the following problem: Given a list of n bit strings, each of length k,
calculate the minimum Hamming distance between two strings in the list. For
example, the answer for [00111,01101,11110] is 2, because
• hamming(00111,01101) = 2,
• hamming(00111,11110) = 3, and
• hamming(01101,11110) = 3.


*/

int hamming(string a, string b) {
    int d = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] != b[i]) d++;
    }
    return d;
}

// if k is small we can use this 
int hamming(int a, int b) {
    return __builtin_popcount(a^b); // a^b sets one wherever there is a difference so we will count number of ones at the end
}
