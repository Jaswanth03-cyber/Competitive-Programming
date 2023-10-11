#include <bits/stdc++.h>
using namespace std ;


/*
Let X = {0...n−1}, and each subset S ⊂ X is assigned an integer value[S]. Our task is to calculate for each S

sum(S) = sum(value[A]) for all A⊂S,

Let partial(S,k) denote the sum of values of subsets of S with the restriction
that only elements 0...k may be removed from S. For example,

                |    partial(S,k −1) k ∉ S
partial(S,k) =  |             
                |    partial(S,k −1)+partial(S \ {k},k −1) k ∈ S
*/

void solve(){
    int n = 0 ;
    cin>>n ;
    vector<int> values(1<<n, 0) ;
    for(int i = 0 ; i < (1<<n) ; i++){
        cin>>values[i] ;
    }

    vector<int> sum(1<<n, 0) ;
    for(int i = 0 ; i < (1<<n); i++){
        sum[i] = values[i] ;
    }

/*
this ensures we are adding value of each subset of a subset in an order for example lets say 
for sum({1,2}) that is for j = 3 we have to calculate

i = 0 no execution as j&(1<<i) is false 
i = 1 j^(1<<i) = 2 so sum[2] is added to it -> at this point of time sum[2] is still values[2] as this before this iteration i = 0 executed not change in it
i = 2 j^(1<<i) = 1 so sum[1] is added to it -> at this point of time sum[1] is values[1] 
i = 3 j^(1<<i) = 0 so sum[0] is added to it -> at this point of time sum[0] is values[0]
rest all no execution as they are not in the set 
*/
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < (1<<n) ; j++){
            if(j&(1<<i)){
                cout<<i<<" "<<j<<" "<<(j^(1<<i))<<" "<<sum[j^(1<<i)]<<endl  ;
                sum[j] = sum[j] + sum[j^(1<<i)] ;
            }
        }
    }

    for(int i = 0 ; i < (1<<n); i++){
        cout<<sum[i]<<" " ;
    }
    cout<<endl ;

/*
In this computation values are being repeated after calculating the total value and if we add the value then lets say value(phi)(value of empty set) is added many times
*/
    vector<int> sum1(1<<n, 0) ;
    for(int i = 0 ; i < (1<<n); i++){
        sum1[i] = values[i] ;
    }

    for(int i = 0 ; i < (1<<n) ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i&(1<<j)){
                sum1[i] += sum1[i^(1<<j)] ;
            }
        }
    }
    cout<<"second computation : " ;
    for(int i = 0 ; i < (1<<n); i++){
        cout<<sum1[i]<<" " ;
    }
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}