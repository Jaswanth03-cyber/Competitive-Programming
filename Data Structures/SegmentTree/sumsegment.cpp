#include <bits/stdc++.h>
using namespace std ;


class segmenttree{
    vector<int> tree ;
    int size ;
    public:
    segmenttree(vector<int> &arr){
        int n = arr.size() ;
        size = 4*n ;
        tree.resize(size) ;
        build(arr, 0, 0, n-1) ;
    }

    void build(vector<int> &arr, int index, int left, int right){
        if(left == right){
            tree[index] = arr[left] ;
        }
        else{
            int mid = (left+right)/2 ;
            build(arr, 2*index+1, left, mid) ;
            build(arr, 2*index+2, mid+1, right) ;
            tree[index] = tree[2*index+1] + tree[2*index+2] ;
        }
    }

    int sum(int index, int segleft, int segright, int left, int right){
        if(left > right){
            return 0 ;
        }
        if(segleft == left && segright == right){
            return tree[index] ;
        }
        int mid = (segleft + segright)/2 ;
        int ans = sum(2*index+1, segleft, mid, left, min(right, mid)) + sum(2*index+2, mid+1, segright, max(left, mid+1), right) ;
        return ans ;
    }

    void update(int index, int segleft, int segright, int value, int pos){
        if(segleft == segright){
            tree[index] = value ;
        }
        else{
            int mid = (segleft+segright)/2 ;
            if(pos <= mid){
                update(2*index+1, segleft, mid, value, pos) ;
            }
            else{
                update(2*index+2, mid+1, segright, value, pos) ;
            }
            tree[index] = tree[2*index+1] + tree[2*index+2] ;
        }
    }

    void display(){
        for(int i = 0 ; i < size ; i++){
            cout<<tree[i]<<" " ;
        }
        cout<<endl ;
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

    segmenttree nodes(arr) ;
    nodes.display() ;
    return 0 ;
    

}