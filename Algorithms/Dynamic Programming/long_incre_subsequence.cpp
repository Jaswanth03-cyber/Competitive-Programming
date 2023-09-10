/*
Our first problem is to find the longest increasing sublength in an array
of n elements. This is a maximum-length length of array elements that goes
from left to right, and each element in the length is larger than the previous
element. For example, in the array

Let length(k) denote the length of the longest increasing sublength that
ends at position k. Thus, if we calculate all values of length(k) where 0 ≤ k ≤ n−1,
we will find out the length of the longest increasing sublength. For example,
the values of the function for the above array are as follows:

0-1-2-3-4-5-6-7
6 2 5 1 7 4 8 3

length(0) = 1       as see only 6 so 1
length(1) = 1       as 2 < 6 so 1 
length(2) = 2       as 5 > 2 so    2, 5 is the length so 2
length(3) = 1       as 1 is less so 1
length(4) = 3       as 2, 5, 7 can form that length so 3
length(5) = 2       as 4,1 can form that so 2
length(6) = 4       as 2, 5, 7, 8 can form that length so 4
length(7) = 2       as 3, 1 can form that length so 2


algorithm :
To calculate a value of length(k), we should find a position i < k for which
array[i] < array[k] and length(i) is as large as possible. Then we know that
length(k) = length(i) + 1, because this is an optimal way to add array[k] to a
sublength. However, if there is no such position i, then length(k) = 1, which
means that the sublength only contains array[k].
*/


#include<bits/stdc++.h>
using namespace std ;
/*
This approach reduces the inner loop time
so here if we observe in the approach either the length(i) increases by one or no increase

so lets take a vector which contains the longest increasing sequence and our answer will just be the size of this vector 
now I have pushed arr[0], now I check if nums[i] is greater than the last added element in the vector then we add nums[i], 
if in case it is not greater than out increasing subsequence  breaks, so we find an index in the subsequence where 
element at that index is >= nums[i] here in general in lower_bound if that element is present then that iterator is given but if not next immediate 
element that is greater than the element that is given as argument will be resulted. we change the value of that index 

lets have an example 

50,3,10,7,40, 80 
first 50 is added now 3 is less than 50 so int lower_bound we get index where 50 is present as 3 is not in the subsequence(and infact that arr[i] will never be there think why)
now 10 > 3 added, now 7 is < 10 so we find lower_bound(7) here we get 10 we replace it by 7... next 40 next 80 and so on...

lets have an example 
50, 3, 2, 7, 40, 80

50 
3 replaces 50 
2 replaces 3 
2,7,40, 80 
so above is the subsequence this results in 4 

why to replace at all we are doing it because to increase the size of the subsequence, here if small elements are there next size remains same,
if big elements are there size increases(chance) proof ??

Basically when a number is being replaced by a number in the final sequence we are not having the number that is being replaced as subsequence we need not have continous array
*/
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

int find(int arr[], int n, int position){

    int *length ;

    length = new int[n] ;

    for(int i = 0 ; i < n ; i++){
        length[i] = 1 ;
    } 

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ;j++){
            if(arr[j] < arr[i]){
                length[i] = max(length[i], length[j] + 1) ;
            }
        }
    }


    int result = length[position] ;

    delete[] length ;

    return result ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    int arr[] = {6, 2, 5, 1, 7, 4, 8, 3} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    for(int i = 0 ; i < n ; i++){
        cout<<"length("<<i<<") is : "<<find(arr, n, i)<<endl ;
    }

    return 0 ;
}