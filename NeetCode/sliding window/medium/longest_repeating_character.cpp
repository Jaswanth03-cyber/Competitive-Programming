#include <bits/stdc++.h>
using namespace std ;

/*
Logic :-
Here we are following a sliding window approach we are taking a window and in that window lets take maximum frequency element now if the remaining 
elements are turned into this then we can get a maximum substring so we are checking if the remaining number of elements to be changed is <= k 
if yes then taking the maximum if not then we have to change the window so initially our l starts from 0, now as r goes l changes or remains the same
depending on the value of k and the frequencies of the elements. if so number of elements that need to be changed is greater than k then increment
the l as taking the previous l thats the maximum window we can get, so increasing that l and removing the character at l from the map.

for example
basically our sliding window length will be in a way that r-l+1 -maxfreq <= k(maxfreq is the max freq from l to r).
ABABBA k = 2 
now l = 0 and now as the loop progresses here basically our right end should reach n-1 that is our r.
l = 0 r = 0 
mp[A] = 1 maxfreq is 1 r-l+1(length of the substring)
r = 1 fine 
r = 2 fine 
r = 3 fine
r = 4 fine 
r = 5 here comes the case as r = 5 l = 0 maxfreq = 3 r-l+1 -maxfreq > k so here l++ remove that s[l] 
so now l = 1 and r = 5 r-l+1 -maxfreq = 2>= 2 so this is the maximum length in this window.
we have gone through all the possible substrings 
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
      map<char, int> mp ;
      int l = 0 ;
      int n = s.length() ;
      int maxfreq = 0 ;
      int ans = 0 ;
      for(int r = 0 ; r < n ; i++){
        mp[s[r]]++ ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
          maxfreq = max(maxfreq, it->second) ;
        }
        if(r-l+1 - maxfreq > k){
          mp[s[l]]-- ;
          l++ ;
        }
        ans = max(ans, r-l+1) ;
      }
      return ans ;
    }
};