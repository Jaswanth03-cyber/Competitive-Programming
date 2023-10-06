#include <bits/stdc++.h>
using namespace std ;

typedef pair<int,int> pi ;
int n, m ;
queue<pi> pq ;
vector<vector<int>> paths(1005, vector<int>(1005, INT_MAX)) ;
vector<vector<char>> grid(1005, vector<char>(1005, 'a')) ;
vector<vector<pi>> from(1005, vector<pi>(1005, {0, 0})) ;
pi start ;
bool possible = false ;
string ans ;
pi end_trace = {0, 0} ;

void isvalid(pi src, pi dest){
    int dis = paths[src.first][src.second] ;
    if(dest.first < 0 || dest.first >= n || dest.second < 0 || dest.second >= m){
        return ;
    }
    else if(dis + 1 < paths[dest.first][dest.second]){
        paths[dest.first][dest.second] = dis + 1 ;
        pq.push({dest.first, dest.second}) ;
        from[dest.first][dest.second] = src ;
    }
    return ; 
}

void retrace(pi cell){
    pi src = from[cell.first][cell.second] ;
    if(src == end_trace){
        return ;
    }
    else if(src.first -1 == cell.first){
        ans.push_back('U') ;
    }
    else if(src.first + 1 == cell.first){
        ans.push_back('D') ;
    }
    else if(src.second -1 == cell.second){
        ans.push_back('L') ;
    }
    else if(src.second + 1 == cell.second){
        ans.push_back('R') ;
    }

    retrace(src) ;
}
void bfs(char src){
    while(!pq.empty()){
        pi curr = pq.front(), next ;
        pq.pop() ;

        next = curr ;
        next.first++ ;
        isvalid(curr, next) ;
        next = curr ;
        next.first-- ;
        isvalid(curr, next) ;
        next = curr ;
        next.second++ ;
        isvalid(curr, next) ;
        next = curr ;
        next.second-- ;
        isvalid(curr, next) ;

        if(src == 'A'){
            if(curr.first == 0 || curr.first == n-1 || curr.second == 0 || curr.second == m-1){
                cout<<"YES"<<endl ;
                cout<<paths[curr.first][curr.second]<<endl ;
                possible = true ;
                retrace(curr) ;
                return ;
            }
                
        } 
    }
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    cin>>n ;
    cin>>m ;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>grid[i][j] ;
            if(grid[i][j] == '#'){
                paths[i][j] = 0 ;
            }
            else if(grid[i][j] == 'M'){
                pq.push({i, j}) ;
                paths[i][j] = 0 ;
            }
            else if(grid[i][j] == 'A'){
                start = {i, j} ;
            }
        }
    }
    bfs('M') ; // bfs of Monsters 
    from[start.first][start.second] = end_trace ;
    paths[start.first][start.second] = 0 ;
    pq.push(start) ;
    bfs('A') ;

    if(possible){
        reverse(ans.begin(), ans.end()) ;
        cout<<ans<<endl ;
    }
    else{
        cout<<"NO"<<endl ;
    }
}

/*
so we are having global variables paths for length of either monster or A and from is a 2D vector of pairs which has the information 
from which cell did we reach this cell and possible will be true if we reach the border and pair start stores where A cell is and end_trace
this is the source of A we end the trace when we raech this queue used for bfs 

so as here more monsters are there not just one we have to do bfs of all them at one time so what we do is initially we push the monster 
and now for every cell we are taking the minimum distance of all the monsters which reach that cell later if a can reach in minimum distance over
there then it is replaced over there 

so basically for every cell we are having at what minimum time either a monster or A can reach over there if so that cell happens to be a border 
then we have found it if to none of the borders A can reach first than a monster then not possible NO is the solution 

so first bfs of the monsters when a monster occurs we are doing bfs of that first I guess rotten oranges sum in neetcode is same as this and for each
cell we are maintaing from which cell it came at last bfs of A is done so to the cells which A can reach that is stored 
*/