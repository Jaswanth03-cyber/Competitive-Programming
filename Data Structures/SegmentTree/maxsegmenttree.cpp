#include <bits/stdc++.h>
using namespace std ;

/*
this is just used to find the max in arange similarly we can change it to get min in a range and also we can get number of times min/maximum 
has occured in place of sum we have to a different operation so the operation is nothing but combine() which takes two childs of a segment 
now if first pair is maximum that is given back if not second is maximum that is returned back if in case both values are same then we return 
the sum of frequencies, rest all is pretty much the same.
*/
typedef pair<int, int> pi ;
class segmenttree{
    vector<pi> tree ;
    int size ;
    public:
    segmenttree(vector<int> &arr){
        int n = arr.size() ;
        size = 4*n ;
        tree.resize(size, 0) ;
        build(arr, 0, n-1, 0) ;
    }

    pi combine(pi a, pi b){
        if(a.first > b.first){
            return a ;
        }
        else if(b.first > a.first){
            return b ;
        }
        return {a.first, a.second + b.second} ;
    }

    void build(vector<int> &arr, int segleft, int segright, int index){
        if(segleft == segright){
            tree[index] = {arr[left], 1} ;
        }
        else{
            int mid = (segleft+segright)/2 ;
            build(arr, segleft, mid, 2*index+1) ;
            build(arr, mid+1, segright, 2*index+2) ;
            tree[index] = combine(tree[2*index+1], tree[2*index+2]) ;
        }
    }

    pi rmq(int index, int segleft, int segright, int left, int right){
        if(segleft > segright){
            return {INT_MIN, 0} ;
        }
        else if(left == segleft && right == segright){
            return tree[index] ;
        }
        int mid = (segleft+segright)/2 ;
        pi one = rmq(2*index+1, segleft, min(right, mid), left, right) ;
        pi two = rmq(2*index+2, max(mid+1, segleft), segright, left, right) ;
        pi ans = combine(one, two) ;
        return ans ;
    }

    void update(int index, int segleft, int segright, int pos, int value){
        if(segleft == segright){
            return {value, 1} ;
        }
        int mid = (segleft+segright)/2 ;
        if(mid >= pos){
            update(2*index+1, segleft, mid, pos, value) ;
        }
        else{
            update(2*index+2, mid+1, segright, pos, value) ;
        }
        tree[index] = combine(tree[2*index+1], tree[2*index+2]) ;
    }
};