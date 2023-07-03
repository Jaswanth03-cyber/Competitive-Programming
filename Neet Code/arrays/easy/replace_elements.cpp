#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr){   

        vector<int> ans ; 
        int n = arr.size() ;
        ans.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            ans[i] = arr[i] ;
        }   

        ans[n-1] = -1 ;
        int j = n - 2 ;
        priority_queue<int> pq ;
        pq.push(arr[j+1]) ;
        while(j >= 0){
            ans[j] = pq.top() ;
            pq.push(arr[j]) ;
            j-- ;
        } 

        return ans ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    Solution ans ; 
    int n ; 
    cin>>n ;
    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    } 

    vector<int> result = ans.replaceElements(arr) ;

    for(size_t i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" ";
    }
    cout<<endl ;
    return 0 ;
}