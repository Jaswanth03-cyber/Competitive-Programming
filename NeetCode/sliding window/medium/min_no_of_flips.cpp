#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
*/

class Solution {
public:
    int minFlips(string s) {
        int n = s.length() ;
        string alt1 = "", alt2 = "" ;
        string text = s + s ;
        for(int i = 0 ; i < 2*n ; i++){
            if(i%2 == 0){
                alt1 += '0' ;
                alt2 += '1' ; 
            }
            else{
                alt1 += '1' ;
                alt2 += '0' ;
            }
        }
        int ans = 2*n ;
        int l = 0 ;
        int r = 0 ;
        int diff1 = 0, diff2  = 0 ;
        while(r < 2*n){
            if(text[r] != alt1[r]){
                diff1++ ;
            }
            if(text[r] != alt2[r]){
                diff2++ ;
            }

            if(r - l + 1 > n){
                if(text[l] != alt1[l]){
                    diff1-- ;
                }
                if(text[l] != alt2[l]){
                    diff2-- ;
                }
                l++ ;
            }

            if(r-l+1 == n){
                ans = min(ans, diff1) ;
                ans = min(ans, diff2) ;
            }
            r++ ;
        }
        return ans ;
    }
};

/*
so for a given length we can have only two alternating strings so we have to try to convert the given string into one of these which 
takes min number of operations 

so basically there are two operations that can be done shift the first index to last so if we shift the first index we will end up with a new 
string if we shift first two we will end up with another and so on that way...

so basically if we shift all the starting ones we will end up with the same string itself so if we have a text = s + s all possible
substrings of length n is the total possible strings after performing operation 1 now for each of the substring if we calculate the min no of 
type 2 operations we will get the result 

actually if we take every substring and calculate the min possible flips of type 2 we will end up with O(n^2) which will not pass so we need O(n)
sliding window for the rescue go through text until string length is n so as soon as string length exceeds n increment the l now if in case 
last position of l was differing decrement the count if not no need and also see we are having the lengths of alternating strins as 2*n itself.

we need to take the answer when string length is n i.e when r-l+1 is n
*/

