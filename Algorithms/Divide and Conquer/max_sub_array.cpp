/*
Basically we are having an array of elements we have to write an algorithm which gives us the sub array among all the 
sub arrays possible which has the highest sum here subarray means continuous set of elements of the original array

Use of this algorithm if u have n days price of a particular item we need to find the time interval in which a person can make profit 
Here seller first has to buy the stick and then has to sell it, so we need to find a day where the amount is less and we need to find
a day that comes after buying so that in this period he can make profit. so if u find a sub array say A[i...j] starting at i

then if we buy at before i and sell after j we will get profit,  see here array does not refer to prices on that day, we will make
a new array whose elemnts are the rise of price its before day and that day...

Here array contains negative integers too otherwise its just total array sub array will be total array
*/

/*
input ; an array of n integers 
output a vector containg three elements first starting index of the subarray, second element last index and the third element is 
the sum of that sub array

three cases :
case1 : the subarray completely lies between low to mid 
case2 : the subarray completely lies between mid +1 to high 
case3: starts at i and ends at j where i is in between low and mid and j is between mid +1 and high i can be mid and j can be mid +1

We are solving using Divide and Conquer 

*/


#include<iostream>
#include<vector>
using namespace std ;

#define MAX 1e5    // assuming we do not have values in the array that high does not need this though
#define MIN -1e5   // assuming we do not have values less than this 


/*
This function is to find for the case_3 
*/


template<typename T> vector<T> brute_force(T arr[], int low, int high){
    vector<T> res ;
    res.resize(3) ;
    int min_sum = MIN ;
    for(int i = low ; i < high ; i++){
        int sum = 0 ;
        for(int j = i ; j < high ; j++){
            sum = sum + arr[j] ;
            if(sum > min_sum){
                min_sum = sum ;
                res[0] = i ;
                res[1] = j ;
                res[2] = min_sum ;
            }
        }
    }
    return res ;
}


template<typename T> vector<T> max_crossing_sub_array(T arr[], int low, int mid, int high){

    vector<T> res ;
    res.reserve(3) ;     // we need a vector of size 3 as the output 
/*
Finding the index in the left array for the overlapped subarray
*/
    int left_max_sum = MIN ;       
    int sum_left = 0 ;
    for(int i = mid ; i >= low ; i--){
        sum_left = sum_left + arr[i] ;
        if( sum_left > left_max_sum){
            left_max_sum  = sum_left ;
            res[0] = i ; 
        } 
    }

/*
Finding the index in the right array for the overlapped subarray
*/
    int right_max_sum = MIN ;
    int sum_right = 0 ;
    for(int i = mid + 1 ; i <= high ; i++){
        sum_right = sum_right + arr[i] ;
        if(sum_right > right_max_sum){
            right_max_sum = sum_right ;
            res[1] = i ;     
        }
    }
    res[2] = left_max_sum + right_max_sum ;

    return res ;

}

/*
This is the main function where 
*/
template<typename T> vector<T> max_sub_array(T arr[], int low, int high){

    vector<T> res ;

    vector<T> max_res_left ;
    vector<T> max_res_right ;
    vector<T> max_res_cross ;

    // base case 
    
    if(low == high){
        res.resize(3) ;
        res[0] = 0 ;
        res[1] = 0 ;
        res[2] = arr[0] ;
        return res ;
    } 
    else{

        int mid = (low + high)/2 ;

        max_res_left = max_sub_array(arr, 0, mid) ; // dividing into subcases

        max_res_right = max_sub_array(arr, mid +1, high) ; // dividing into subcases

        max_res_cross = max_crossing_sub_array(arr, low, mid, high) ;


        // finally combining all of them 

        if((max_res_left[2] >= max_res_right[2]) && (max_res_left[2] > max_res_cross[2])){
            res.resize(3) ;
            for(int i = 0 ; i < 3 ; i++){
                res[i] = max_res_left[i] ;
            }
            return res ;
        }
        else if((max_res_right[2] >= max_res_left[2]) && (max_res_right[2] >= max_res_cross[2])){
            res.resize(3) ;
            for(int i = 0 ; i < 3 ; i++){
                res[i] = max_res_right[i] ;
            }
            return res ;
        }
        else{
            res.resize(3) ;
            for(int i = 0 ; i < 3 ; i++){
                res[i] = max_res_cross[i] ;
            }
            return res ;
        }
    } 
}

int main(){
    vector<int> res_1 ;
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    res_1 = max_sub_array<int>(arr, 0 ,n -1) ;

    cout<<"The starting index of the max_sub array is "<<res_1[0]<<" and ends at the index "<<res_1[1]<<" and the sum of the elements is "<<res_1[2]<<endl ;


    vector<int> res_2 ;
    int arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9} ;
    int n_1 = sizeof(arr_1)/sizeof(arr_1[0]) ;
    res_2 = max_sub_array<int>(arr_1, 0 ,n_1 -1) ;

    cout<<"The starting index of the max_sub array is "<<res_2[0]<<" and ends at the index "<<res_2[1]<<" and the sum of the elements is "<<res_2[2]<<endl ;

    vector<int> res_3 ;
    int arr_2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9} ;
    int n_2 = sizeof(arr_1)/sizeof(arr_1[0]) ;
    res_3 = max_sub_array<int>(arr_2, 0 ,n_2 -1) ;

    cout<<"The starting index of the max_sub array is "<<res_3[0]<<" and ends at the index "<<res_3[1]<<" and the sum of the elements is "<<res_3[2]<<endl ;

    vector<int> res_4 ;
    res_4 = brute_force<int>(arr, 0, n) ;
    cout<<"The starting index of the max_sub array is "<<res_4[0]<<" and ends at the index "<<res_4[1]<<" and the sum of the elements is "<<res_4[2]<<endl ;

    return 0 ;
}

