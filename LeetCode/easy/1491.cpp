#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
*/

class Solution {
public:
    double average(vector<int>& salary) {
        priority_queue<int> arr ;
        int n = salary.size() ;
        for(int i = 0 ; i < n ; i++){
            arr.push(salary[i]) ;
        }
        arr.pop() ;
        int sum = 0 ;
        while(arr.size() > 1){
            sum = sum + arr.top() ;
            arr.pop() ;
        }
        double sum1 = sum ;
        double ans = sum1/(n-2) ;
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }
    Solution ans ;
    double res = ans.average(arr) ;

    cout<<res<<endl ;

    return 0 ;
}