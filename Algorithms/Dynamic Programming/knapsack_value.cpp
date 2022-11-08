/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items 
respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] 
such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the 
complete item or don’t pick it (0-1 property).


In the Dynamic programming we will work considering the same cases as mentioned in the recursive approach. In a DP[][] table let
us consider all the possible weights from ‘1’ to ‘W’ as the columns and weights that can be kept as the rows. 
The state DP[i][j] will denote maximum value of ‘j-weight’ considering all values from ‘1 to ith’. So if we consider 
‘wi’ (weight in ‘ith’ row) we can fill it in all columns which have ‘weight values > wi’. Now two possibilities can take place: 

Fill ‘wi’ in the given column.
Do not fill ‘wi’ in the given column.
Now we have to take a maximum of these two possibilities, formally if we do not fill ‘ith’ weight in ‘jth’ column 
then DP[i][j] state will be same as DP[i-1][j] but if we fill the weight, DP[i][j] will be equal to the value of 
‘wi’+ value of the column weighing ‘j-wi’ in the previous row. So we take the maximum of these two possibilities 
to fill the current state.   
*/

#include<bits/stdc++.h>
using namespace std ;


int naive(int val[], int weights[], int n, int sum){

    if((n == 0) || (sum == 0)){
        return 0 ;
    }

    if(weights[n-1] > sum){
        return naive(val, weights, n-1, sum) ;
    }
    else{

        int possible ;

        possible = max(naive(val, weights, n-1, sum), val[n - 1] + naive(val, weights, n-1, sum - weights[n-1])) ;

        return possible ;
    }
/*
basically nothing but one of the two cases if w[n-1] > sum not consider in the set if not then either it can be in the set or 
not in the set so we will take maximum of those two
*/
}

/*
You know the problem with this approach is recomputes everytime evn though computed before and time complexity is exponential
*/


int dynamic(int val[], int weights[], int n, int sum){

    int *new_value ;          
    new_value = new int[n + 1] ;        // I have introduced these so that no confusion as we generally write [w1,...wn]
    new_value[0]  = -1 ;
    for(int i = 1 ; i <= n ;i++){
        new_value[i] = val[i-1] ;
    }

    int *new_weight ;
    new_weight = new int[n + 1] ;    // I have introduced these so that no confusion as we generally write [w1,...wn]
    new_weight[0] = -1 ;
    for(int i = 1; i <= sum ; i++){
        new_weight[i] = weights[i-1] ;
    }

    int **maximum_sum ;
    maximum_sum = new int*[n+1] ;

    for(int i = 0 ; i <=n ; i++){
        maximum_sum[i] = new int[sum + 1] ;
    }

    for(int i = 0 ; i <= n ; i++){
        maximum_sum[i][0] = 0 ;          //with weight 0 we can not have any sum so max sum is 0
    }

    for(int j = 1 ; j <=sum ; j++){
        maximum_sum[0][j] = 0 ;        // with weight any value as no elements in it max sum will be 0 
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= sum ; j++){
            if(new_weight[i] > j){
                maximum_sum[i][j] = maximum_sum[i-1][j] ;
            }
            else{
                maximum_sum[i][j]  = max( (maximum_sum[i-1][j]) , ( (maximum_sum[i-1][j - new_weight[i]]) + (new_value[i]) ) ) ;
            }
        }
    }

    int result = maximum_sum[n][sum] ;

    for(int i = 0 ; i <= n ;i++){
        delete[] maximum_sum[i] ;
    }
    delete[] maximum_sum ;
    delete[] new_value ;
    delete[] new_weight ;
    return result ;
}

int dynamic_vector(int val[], int weights[], int n, int sum){

    vector<vector<int>> maximum_sum(n + 1, vector<int>(sum + 1)) ;                     // basically 2D vector n+1 rows and sum +1 columns

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum ; j++){
            if ( (i == 0) || (j == 0) ){
                maximum_sum[i][j] = 0;
            }
            else if (weights[i - 1] <= j){
                maximum_sum[i][j] = max( ( (val[i - 1]) + (maximum_sum[i - 1][j - weights[i - 1]]) ) ,  (maximum_sum[i - 1][j]) );
            }
            else{
                maximum_sum[i][j] = maximum_sum[i - 1][j] ;
            }
        }
    }

    return maximum_sum[n][sum];
}

/*
Here maximum_sum[i][j] represents maximum value of sum of values taken from val[1...i] with the condition that their corresponding 
weights total is less than or equal to a specified weight here that weight is the parameter sum to the functions .
n is the size of the values/weights array. 
*/

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int val[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout<<"Using Reccursion method : "<<naive(val, weight, n, W)<<endl ;
    cout<<"Using Dynamic Programming : "<<dynamic(val, weight, n, W)<<endl  ;
    cout<<"Using Dynamic Programming with 2D vector: "<<dynamic_vector(val,weight,n, W)<<endl ;

    return 0 ;
}