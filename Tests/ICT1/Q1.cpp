#include <bits/stdc++.h>
using namespace std ;


/*
basically what we are doing is that in the possible paths we will have a string now lets say we are having a string 
a[0].......a[k] be the path from (1,1) to (n, m) so now this string has to be a palindrome if we see the patterns 

a[1] and a[k-2] will be one of the elements among all the cell elements which are at distance 1 from (0, 0) or (n-1, m-1) here distance means manhattan distance simillarly
a[2] and a[k-3] will be one of the elements among all the cell elements which are at distance 2 from (0, 0) or (n-1, m-1)
a[i] and a[k-1-i] will be one of the elements among all the cell elements which are at distance i from (0, 0) or (n-1, m-1) 

so these must be same for this string to be palindrome so our aim is that for all possible manhattan distances lets say from 0 to dist
for all these distances i take all the elements that are at distance i from (0,0) or (n-1, m-1) now we have to change these values such that
all these values must be equal so to get the minimum changes what we do is that change all the elements at the cells that are at distance i
in to the value whose freq is more at those cells for ex lets say for i = 1 possible cells are 4 among all these 4 cells take the max freq element
change all other into that value so we are calculating the total cells and subtracting the max freq count remaing elements we have to change for sure

so freq[i][j] and freq[n+m-2-i][j] denotes freq of element j in the cells which are at distance i either from (0, 0) or (n-1, m-1).
so we have number of columns = maxelement in the matrix + 1 

In our exam max element in the matrix is just 1 so we need not calculate max element in the matrix explicitly 
*/
void solve(){
    int n = 0 ;
    cin>>n ;
    int m =0 ;
    cin>>m ;

    vector<vector<int>> grid(n, vector<int>(m, 0)) ;

    int maxelement = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>grid[i][j] ;
        }
        maxelement = max(maxelement, *max_element(grid[i].begin(), grid[i].end())) ;
    }

    int maxdist = n + m - 1 ;
    vector<vector<int>> freq(maxdist, vector<int>(maxelement+1, 0)) ;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            freq[i+j][grid[i][j]]++ ;
        }
    }

    int ans = 0 ;
    for(int i = 0 ; i < maxdist/2 ; i++){
        int maxfreqelem_i = 0 ;
        int total = 0 ;
        for(int j = 0 j <= maxelement ; j++){
            maxfreqelem_i = max(maxfreqelem_i, freq[i][j] + freq[n+m-2-i][j]) ;
            total_i = total_i + freq[i][j] + freq[n+m-2-i][j] ;
        }

        int minchanges_i = total - maxfreqelem_i ;
        ans = ans + min_changes_i ;
    }

    cout<<ans<<endl ; 
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;

    return 0 ;
}