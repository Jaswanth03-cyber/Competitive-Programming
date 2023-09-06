#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/verifying-an-alien-dictionary/
*/
/*
Just I have implemented the brute force solution that had a map which has the priority according to the given order
now iterated through the pairs from left to right taking two at a time just checked whether they are in lexicographical order or not 
*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        bool ans = true ;
        bool stop = false ;
        map<char, int> mp;
        int size = order.size() ;
        for(int i = 0 ; i < size ; i++){
            mp[order[i]] = i ;
        }

        size = words.size() ;
        int i = 0 ; 
        int j = 0 ;
        string one = "" ;
        string two = "" ;
        int size1 = 0 ;
        int size2 = 0 ;
        for(int k = 1 ; k < size ; k++){
            i = 0 ;
            j = 0 ;
            one = words[k-1] ;
            two = words[k] ;
            size1 = words[k-1].size() ;
            size2 = words[k].size() ;
            while(i < size1 && j < size2){
                if(mp[one[i]] == mp[two[j]]){
                    i++ ; 
                    j++ ;
                }
                else if(mp[one[i]] < mp[two[j]]){
                    break ;
                }
                else{
                    stop = true ;
                    break ;
                }
            }
            // this is when apple and app this type occur where first word is still there but second word completed but second word and first word
            //overlaped till there, so this will be the case as given in the question that alphabet > empty character so apple should be after app.
            if(j == size2){
                if(i < size1){
                    ans = false;
                    break ;
                }
            }
            if(stop){
                ans = false ;
                break ;
            }
        }
        return ans ;
    }
};