#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-common-words-with-one-occurrence/description/
*/

class Solution {
public:
    bool check(string &s, vector<string> &arr){
        int n = arr.size() ;
        int l = 0, r = n-1 ;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(arr[mid] == s){
                if((mid > 0 && arr[mid-1] != arr[mid]) && (mid < n-1 && arr[mid] != arr[mid+1])){
                    return true ;
                }
                else if(mid == 0 && arr[mid] != arr[mid+1]){
                    return true ;
                }
                else if(mid == n-1 && arr[mid] != arr[mid-1]){
                    return true ;
                }
                else{
                    return false ;
                }
            }
            else if(lexicographical_compare(s.begin(), s.end(), arr[mid].begin(), arr[mid].end())){
                r = mid - 1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return false ;
    }
    int countWords(vector<string>& words1, vector<string>& words2) {
        int n = words1.size() ;
        int m = words2.size() ;
        sort(words1.begin(), words1.end()) ;
        sort(words2.begin(), words2.end()) ;
        int count = 0 ;
        if(n > m){
            for(int i = 0 ; i < m ; i++){
                if(check(words2[i], words1)){
                    if((i > 0 && words2[i] != words2[i-1]) && (i < m-1 && words2[i] != words2[i+1])){
                        count++ ;
                    }
                    else if(i == 0 && words2[i] != words2[i+1]){
                        count++ ;
                    }
                    else if(i == m-1 && words2[i] != words2[i-1]){
                        count++ ;
                    }
                }
            }
        }
        else{
            for(int i = 0 ; i < n ; i++){
                if(check(words1[i], words2)){
                    if((i > 0 && words1[i] != words1[i-1]) && (i < n-1 && words1[i] != words1[i+1])){
                        count++ ;
                    }
                    else if(i == 0 && words1[i] != words1[i+1]){
                        count++ ;
                    }
                    else if(i == n-1 && words1[i] != words1[i-1]){
                        count++ ;
                    }
                }
            }   
        }
        return count ; 
    }
};