/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed 
by a single person, assuming that a person can only work on a single activity at a time. 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

template<typename T> vector<T> activity_selection(T s[], T f[], int n){

    sort(f, f + n) ;

    vector<T> res ;

    int i = 0 ; 
    res.push_back(i) ;
    for(int j = 1 ; j < n ; j++){
        if(s[j] >= f[i]){
            i = j ;
            res.push_back(i) ;
        }
    }
    return res ;
}

int main(){
    
    int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12} ;
    int f[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int n = sizeof(f)/sizeof(f[0]) ;
    vector<int> res = activity_selection<int>(s, f, n) ;
    cout<<"Total of "<<res.size()<< " and the activities are as follows : " ;
    for(int i = 0 ; i < res.size() ; i++){
        cout<<"a["<<res[i] + 1<<"] " ;
    }
    cout<<endl ;

    return 0 ;
}