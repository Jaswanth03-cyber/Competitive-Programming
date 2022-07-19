/*
The rod-cutting problem is the following. Given a rod of length n inches and a
table of prices pi for i = 1,2,3...,n. determine the maximum revenue rn obtain-
able by cutting up the rod and selling the pieces. Note that if the price pn for a for a rod
of length n is large enough, an optimal solution may require no cutting at all.

r[n] = max(p[i] + r[n-i]) for all i in [1,n]

dividing into subproblems if we divide the rod into two parts for total to have a maximum we need to have maximum for both the
parts too thats the optimal substructure 
*/

#include<iostream>
using namespace std ;
#define MIN -1e5 ;

void print(int arr[], int n){

    for(int i = 1 ; i <= n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;

}

int rod_cut(int price[], int n){ // here n is the size of the rod 

    int *new_price ;

    new_price = new int[n+1] ;

    new_price[0] = -1 ;      // this is just a dummy variable to avoid confusion of indexes later in the for loop 

    for(int i = 1 ; i <= n ; i++){
        new_price[i] = price[i-1] ;
    }

    int *revenue ;

    revenue = new int[n+1] ;         // this is the maximum value for rod size i where i ranging from 1 to n and making 0 for 0

    revenue[0] = 0 ;

    int *size ;

    size = new int[n+1] ;

    size[0] = 0 ;

    for(int i = 1 ; i <= n ; i++){
        revenue[i] = MIN ;
        for(int j = 1 ; j <=i ; j++){
            int a = new_price[j] + revenue[i-j] ;
            if(revenue[i] < a){
                revenue[i] = a ;
                size[i] = j ; 
            }
        }
    }

    int result ;

    result = revenue[n] ;

    print(size, n) ;

    delete[] revenue ;
    delete[] new_price ;
    delete[] size ;

    return result ;
}

/*
Here defined a new_price array to avoid confusion thats all nothing much and revenue array corresponds to the max value we get
for rod of size i here i goes from 1 to n for rod of size 0 we take it as 0 

so in second loop that corresponds to the following 

we go through all the partitions for rod of size i from 1 to i 
be carefull its not i = 0 to i-1, it makes a lot of difference because to avoid that confusion only we defined new_price

see it starts from new_price[1] as our rod starts from size 1 not 0 we dont want 0 sized rod 

Here size array is the length of the first piece cut off for each i where i goes from 1 to n(size of the given rod)

we are making a rod into two rods and these two rods should give high revenue tooo 
here size gives the length of the first rod, there is no need to further partition this but we might do for second rod obtained
*/

int main(){

    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30} ;
    int n = sizeof(price)/sizeof(price[0]) ;

    int value = rod_cut(price, n) ;

    cout<<"so the maximum revenue that can be obtained from the rod is : "<<value<<endl ;

    return 0 ;
}