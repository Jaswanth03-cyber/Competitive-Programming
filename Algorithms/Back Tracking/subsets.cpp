#include <bits/stdc++.h>
using namespace std ;

/*
Given an integer array that has all its elements distinct we need to find all the possible subsets.
*/
void combinations(int n, int index, vector<int> &subset, vector<vector<int>> &powerset, vector<int> &arr){
    if(index == n){
        powerset.push_back(subset) ;
    }
    else{
        combinations(n, index+1, subset, powerset, arr) ;
        subset.push_back(nums[index]) ;
        combinations(n, index+1, subset, powerset, arr) ;
        subset.pop_back() ;
    }
}

void solve(vector<int> &arr){
    int n = arr.size() ;
    int index = 0 ;
    vector<vector<int>> powerset ;
    vector<int> subset ;
    combinations(n, index, subset, powerset, arr) ;
}

int main(){
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;

    int n = 0 ;
    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }

    void solve(arr) ;
    return 0 ;
}