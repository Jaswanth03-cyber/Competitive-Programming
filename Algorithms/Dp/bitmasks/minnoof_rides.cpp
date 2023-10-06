#include<bits/stdc++.h>
using namespace std ;

void solve(vector<int> &weights, int capacity){

    int n = weights.size() ;
    vector<pair<int, int>> dp(1<<n, {n+1, 0}) ;
    dp[0] = {1, 0} ;

    for(int i = 1 ; i < (1<<n) ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i&(1<<j)){
                pair<int, int> prev = dp[i^(1<<j)] ;
                if(prev.second+weights[j] <= capacity){
                    prev.second = prev.second + weights[j] ;
                }
                else{
                    prev.first++ ;
                    prev.second = weights[j] ;
                }
                dp[i] = min(dp[i], prev) ;
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n= 0 ;
    cin>>n ;
    int capacity = 0;
    cin>>capacity ;
    vector<int> weights(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>weights[i] ;
    }
    solve(weights, capacity) ;

    return 0 ;
}

/*
So the logic is that for each set you are maintaining minimum number of rides required and in the all rides of this set in the last ride you try 
to keep the weight as minimum as possible so as for example if a new member gets added to this set and if his weight + last ride weight <= capacity
then for the new member there is no need of new ride he can go in the last ride of the previous set itself 

so the relation is simple take a set and now for each person who is in this set take a set in which he is not there but rest all presons are there
now we have previously computed minimum number of rides required for the new set and also calculated the minimum weight of the last ride in that new set
now if so in the last ride there is place for this person then just add this weight to the last ride and no need of extra rides but if in case the 
person does not fit then for sure we need a new ride and in the new ride the weight is this guy the new guy. now as we have done this for all the
persons who are in the original set we have calculated the above thing and we take the minimum rides among it if in case min ride is same then 
we take the one in which the last ride has the minimum weight. just write on a paper you will get an idea, initially all value are initialised to 
{n+1,0} min weight and min no of rides required. 

for example for a capacity of weight 10 and the weights 2 3 3 5 6  I have calculated the things which are written as shown

dp[0] = {1, 0}
dp[1] = {1, weight[0]} 
dp[2] = {1, weight[1]} 
dp[3] = {1, weight[0] + weight[1]} 
dp[4] = {1, weight[2]}
dp[5] = {1, weight[2] + weight[0]}
dp[6] = {1, weight[2] + weight[1]}
dp[7] = {1, weight[2] + weight[1] + weight[0]}
dp[8] = {1, weight[3]}
dp[9] = {1, weight[3] + weight[0]}
dp[10] = {1, weight[3] + weight[1]}
dp[11] = {1, weight[3] + weight[1] + weight[0]}
dp[12] = {2, weight[1]/weight[2]} as both are same weights either of them and in the first ride weight[3]+weight[1]/weight[2] will go and another will be in ride2


note 
pair = min(pair1, pair2) here first compares the first elements if the minimum of first element is in pair1 then pair = pair1 
and if first is min in pair2 then min is pair2 if in case first two are same then take the minimum of second one this is how it is done

pi = min({1,10}, {10, 3}) = {1,10}
pi = min({1,10}, {1,2}) = {1,2}
pi = min({1,1}, {1,1}) = {1,1}
*/