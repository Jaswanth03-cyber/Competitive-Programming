

#include<bits/stdc++.h>
using namespace std ;
#define MAX 1e7 

void print(int **s, int i, int j){
    if(i == j){
        cout<<"A["<<i<<"]" ;
    }
    else{
        cout<<"(" ;
        print(s, i, s[i-1][j-1]) ;
        print(s, s[i-1][j-1] +1, j) ;
        cout<<")" ;
    }
}

void matrix_chain_multiplication(int size[], int m){

    int n = m - 1 ;

    int **cost ;
    cost = new int*[n + 1] ;
    for(int i = 0 ; i <=n ; i++){
        cost[i] = new int[n + 1] ;
    }


    for(int i = 0 ; i <= n ; i++){
        cost[i][i] = 0 ;
    }

    int **index ;
    index = new int*[n] ;
    for(int i = 0 ; i < n ; i++){
        index[i] = new int[n] ;
    }

    for(int i = 0 ; i < n ; i++){
        index[n-1][i] = 0 ;
    }

    for(int j = 0 ;  j < n ; j++){
        index[j][0] = 0 ;
    }

    for(int length = 2 ; length <= n ; length++){     // length of the sequence of matrices we want to multiply

        for(int i = 1 ; i <= n - length + 1 ; i++){  // Here this( variable i) is the starting of index of A[i]...A[j] which we want to multiply and length l so j = i + length - 1 

            int j = i + length - 1   ;             // Here this( variable j) is the ending index of A[i]...A[j] which we we want to multiply and length l so j = i + length - 1 

            cost[i][j] = MAX ;

            for(int k = i ; k <=j-1 ; k++){   // Here k will be the variable at which we are exactly breaking the mutiplication sequence from i to j I mean place where we are placing the bracket

                int present_cost = cost[i][k] + cost[k+1][j] + size[i - 1]*size[k]*size[j] ;

                if(present_cost < cost[i][j]){
                    cost[i][j] = present_cost ;

                    index[i-1][j-1] = k ;
                }
            }
        }
    }

    print(index,1, 6) ;
    cout<<endl ;
}

/*
For index here i varies from 1 to 5 and j varies from 2 to 6 
so reduced 1 for each to avoid indexing problem So I have defined a 6 by 6 array in which for 5th row I have initialised 
all the column values to be 0 anyway we wont access this and similarly j j can not be 1 so for first column that is zeroth 
column I have made all the entries 0, here k is the point at which we break the mutiplication that is create brackets 
*/

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int size[] = {30, 35, 15, 5, 10, 20, 25} ;
    int n = sizeof(size)/sizeof(size[0]) ;

    matrix_chain_multiplication(size, n) ;

    int size1[] = {5, 10, 3, 12, 5, 50, 6} ;
    int m = sizeof(size1)/sizeof(size1[0]) ;

    matrix_chain_multiplication(size1, m) ;

    return 0 ;
}