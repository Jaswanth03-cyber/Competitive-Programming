#include <bits/stdc++.h>
using namespace std ;

void solve(vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited, int n, vector<int> &nums){
    int size = temp.size() ;
    if(size == n){
        ans.push_back(temp) ;
    }
    else{
        for(int i = 0 ; i < n ; i++){
            if(visited[i]){
                continue ;
            }
            visited[i] = true ;
            temp.push_back(nums[i]) ;
            solve(ans, temp, visited, n, nums) ;
            visited[i] = false ;
            temp.pop_back() ;
        }
    }
}

void permute(vector<int>& nums) {
    vector<vector<int>> ans ;
    int n = nums.size() ;
    vector<int> temp ;
    vector<bool> visited(n, false) ;
    solve(ans, temp, visited, n, nums) ;
}

int main(){
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;

    int n = 0 ;
    cin>>n ;
    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    } 

    solve(arr) ;
}