/*
Given a list of weights
[w1,w2,...,wn], determine all sums that can be constructed using the weights.
For example, if the weights are [1,3,3,5], the following sums are possible:
0 1 - 3 4 5 6 7 8 9 - 11 12
To solve the problem, we focus on subproblems where we only use the first k
weights to construct sums. Let possible(x,k) = true if we can construct a sum x
using the first k weights, and otherwise possible(x,k) = false. The values of the
function can be recursively calculated as follows:
possible(x,k) = possible(x−wk,k −1) || possible(x,k −1)
The formula is based on the fact that we can either use or not use the weight wk
in the sum. If we use wk, the remaining task is to form the sum x−wk using the
first k−1 weights, and if we do not use wk, the remaining task is to form the sum
x using the first k −1 weights.
*/

#include<bits/stdc++.h>
using namespace std ;

/*arr is the n weights [w1, w2, w3, ... wn] to avoid confusion I have created a new array in the function as indexes
might confuse
*/
bool find(int arr[], int n, int sum){

    int *new_weights ;

    new_weights = new int[n + 1] ;      // I have introduced these so that no confusion as we generally write [w1,...wn]

    new_weights[0] = -1 ;

    for(int i = 1 ; i <= n ;i++){
        new_weights[i] = arr[i-1] ;
    }

    bool **possible ;

    possible = new bool*[n + 1] ;

    for(int i = 0 ; i <= n ; i++){
        possible[i] = new bool[sum + 1] ;
    }

    for(int i = 0 ; i <=n ; i++){
        possible[i][0] = true ;            // as sum 0 is possible even with n weights or no weights so all true as empty set
    }

    for(int j = 1; j <= sum ; j++){
        possible[0][j] = false ;        // with no weights we can not form sums > 0 so false 
    }

    for(int x = 1 ; x <= n ; x++){
        for(int y = 1 ; y <= sum ; y++){
            if(new_weights[x] > y){
                possible[x][y] = possible[x-1][y] ;
            } 
            else{
                possible[x][y] = ((possible[x-1][y]) || (possible[x-1][y - new_weights[x]])) ;
            }
        }
    }

    bool result = possible[n][sum] ;

    for(int i = 0 ; i <=n ; i++){
        delete[] possible[i] ;
    }
    delete[] possible ;
    delete[] new_weights  ;

    return result ;
}
/*
I can even write 
possible[x][y]  = max(possible[x][y-1], possible[x][y - new_weights[x]]) 
instead of (possible[x-1][y]) || (possible[x-1][y - new_weights[x]])

here possible[x][y] means considering [w1,w2,w3,...wx] can we have a subset in this whose sum can be y
*/
int main(){
    int arr[] = {1, 3, 3, 5} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    for(int i = 0 ; i < 13 ; i++){
        cout<<find(arr, n, i)<<" " ;
    }
    cout<<endl ;
    return 0 ;
}