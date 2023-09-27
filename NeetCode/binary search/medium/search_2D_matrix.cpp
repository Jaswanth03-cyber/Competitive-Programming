#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/search-a-2d-matrix/description/
*/
/*
Bruteforce will obv be O(m*n)
n = numberofrows,  m = numberofcolumns 
now we need to do better we can use first given property that every row is sorted sor for every row have a binary search then now 
we can have an efficient than the before one whose complexity is as shown O(m*log(n)) we can still do this better as given that last word of a previous
rows is greater than the next row first one, so what we do is first run a binary search to know in which row target can be 


so in the first binary search we will check in which row first if so target > matrix[mid][m-1] then target will be in next rows so top = mid+1
if so target < matrix[mid][0] then then target is below mid so check in 0 to mid -1 but if not 
matrix[mid][0] < target < matrix[mid][m-1] then it means target can be in this row now we have got in which row we have to search the element 

this can be the case first loop can end in no result that searchrow is still -1 that is top > bottom but still we can not find which row so 
which means target is not there in the matrix so this is also checked now as we got the row now its a normal binary search.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        int top = 0, bottom = n-1 ;
        int mid = 0 ;
        int searchrow = -1 ;
        while(top <= bottom){
            mid = top + (bottom-top)/2 ;
            if(matrix[mid][m-1] < target){
                top = mid + 1 ;
            }
            else if(matrix[mid][0] > target){
                bottom = mid - 1 ;
            }
            else{
                searchrow = mid ;
                break ;
            }
        }
        if(searchrow < 0){
            return false ;
        }
        int left = 0, right = m-1 ;

        while(left <= right){
            mid = left + (right-left)/2 ;
            if(matrix[searchrow][mid] > target){
                right = mid - 1 ;
            }
            else if(matrix[searchrow][mid] < target){
                left = mid + 1 ;
            }
            else{
                return true ;
            }
        }
        return false ;
    }
};