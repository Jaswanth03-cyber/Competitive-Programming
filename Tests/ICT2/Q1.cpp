#include <bits/stdc++.h>
using namespace std ;


/*
we are having an array of elements we can only swap the elements which are not co prime we can do this as many times as we want and check if we can 
sort the array 

so what we are doing is that for every element we are taking all the elements which are not co prime to it and also we are maintaining the indices
from which we are taking and indices we are stroing in a indices array and elements in the temp array now we can sort this temp array as we can do
swaps in this array as none of them are co prime and now at the indices which are in increasing order we are placing all these in the original array
in the positions from which we have taken now after this is done for all vertices and now just check finally arr is sorted or not.
*/
int gcd(int a, int b){
    if(b > a){
        int temp = a ;
        a = b ;
        b = temp ;
    }
    if(b == 0){
        return a ;
    }

    while(b > 0){
        int temp = a%b ;
        a = b ;
        b = temp ;
    }

    return a ;
}
void solve(){
    int n = 0 ;
    cin>>n ;

    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    for(int i = 0 ; i < n ; i++){
        vector<int> temp ;
        vector<int> indices ;
        for(int j = 0 ; j < n ; j++){
            if(gcd(nums[i], nums[j]) != 1){
                indices.push_back(j) ;
                temp.push_back(nums[j]) ;
            }
        }

        int size = temp.size() ;
        sort(temp.begin(), temp.end()) ;
        for(int i = 0 ; i < size ; i++){
            nums[indices[i]] = temp[i] ;
        }
    }

    bool ans = true ;
    for(int i = 1 ; i < n ; i++){
        if(nums[i-1] > nums[i]){
            ans = false ;
            break ;
        }
    }

    if(ans){
        cout<<"true"<<endl ;
    }
    else{
        cout<<"false"<<endl ;
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int t = 0;
    cin>>t ;

    while(t--){
        solve() ;
    }

    return 0 ;
}