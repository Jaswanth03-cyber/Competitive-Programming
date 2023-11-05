#include <bits/stdc++.h>
using namespace std ;


/*
https://www.thejoboverflow.com/p/p2143/
*/
void solve(){
    int m = 0 ;
    cin>>m ;
    int n = 0 ;
    cin>>n ;

    vector<vector<int>> count(m, vector<int>(n, 0)) ;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>count[i][j] ;
        }
    }

    vector<int> maxcount(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            maxcount[i] = max(maxcount[i], count[j][i]) ;
        }
    }

    int id = -1 ;
    int anscount = -1 ;
    double avg = -1.0 ;

    for(int i = 0 ; i < m ; i++){
        int currcount = 0 ;
        int total = 0 ;
        double den = n ; 
        double curravg ;
        for(int j = 0 ; j < n ; j++){
            if(count[i][j] == maxcount[j]){
                currcount++ ;
                total += count[i][j] ;
            }
        }
        curravg = (total)/den ;
        if((currcount > anscount) || (currcount == anscount && avg < curravg)){
            anscount = currcount ;
            id = i ;
            avg = curravg ;
        }
    }

    cout<<id<<" "<<anscount<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}

/*
understand ther questionw well not much 

there are m sequences now each sequence contains the number of messages received from each device so now do according to the conditions 

for each device calculate the maximum count of messages received that is max of all a[i] for 0 <= i < m for each device so this is 
a vector of length n 
now for each seqeunce if in that sequence if so number of messages is same as the max number of messages in that device increase the currcount

now for which seq that currcount is max if same take the avg number of messages received in that sequence that is total number of messages/(no of devices)

so if same count go with avg 
*/