#include <bits/stdc++.h>
using namespace std ;


/*
this is O(N^2) approach but if we consider this then it wont be accepted as if you see the constraints of n it will not be passed 
*/
int approach(vector<int> &arr){
    int n = arr.size() ;
    vector<int> length(n,1) ;
 
    int maximum = 1 ;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ;j++){
            if(arr[j] < arr[i]){
                length[i] = max(length[i], length[j] + 1) ;
            }
        }
        maximum = max(length[i], maximum) ;
    }
    return maximum ;
}

int solve(vector<int> &arr){
    int ans = 0 ;
    vector<int> subsequence ;

    int n = arr.size() ;
    subsequence.push_back(arr[0]) ;
    int top = 0 ;
    int index = 0 ;
    for(int i = 1 ; i < n ; i++){
        top = subsequence.back() ;
        if(arr[i] > top){
            subsequence.push_back(arr[i]) ;
        }
        else{
            index = lower_bound(subsequence.begin(), subsequence.end(), arr[i]) - subsequence.begin() ;
            subsequence[index] = arr[i] ;
        }
    }
    ans = subsequence.size() ;
    return ans ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }

    int ans = solve(arr) ;
    cout<<ans<<endl ;
    return 0 ;
}