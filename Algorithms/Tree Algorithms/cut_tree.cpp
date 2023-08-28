#include <bits/stdc++.h>
using namespace std ;

/*
https://www.hackerrank.com/challenges/cut-the-tree/problem
*/

/*
this gives a different view of a tree problem here by just one bfs we can store child and the corresponding parent 

when tree is given as n input in the form of a graph following problems can be solved using this approach

with this approach following questions can be answered 
1) find the children of a node 
2) find the sum of the children of a node 
3) find the common ancestor (doubtfull)
*/
class graph{
    private :
    int vertices ; // number of vertices
    vector<vector<int>> adjlist ; // adjacency list which maintains the edges
    vector<bool> visited ; // boolean vector to maintain to know whether a node is visited or not 
    vector<int> sum ;  // this vector is just for this problem, sum[i] denotes sum of all the descendants of a node except that node
    stack<pair<int, int>> st ; // this maintains the child and parent pair coming from the leaves till the root 
    public:
    // initialiazing the tree 
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n) ;
        fill(visited.begin(), visited.end(), false) ;
        sum.resize(n) ;
        fill(sum.begin(), sum.end(), 0) ;
    }
    // adding edges 
    void add(int a, int b){
        adjlist[a-1].push_back(b) ;
        adjlist[b-1].push_back(a) ;
    } 
    // bfs traversal starting at the root 
    void bfs(){
        queue<int> pq ;
        pq.push(1) ;
        visited[0] = true ;
        int top = 0 ;
        int size = 0 ;
        while(!pq.empty()){
            top = pq.front() ;
            pq.pop() ;
            cout<<top<<endl ;
            size = adjlist[top-1].size() ;
            for(int i = 0 ; i < size ;i++){
                if(!visited[adjlist[top-1][i]-1]){
                    pq.push(adjlist[top-1][i]) ;
                    visited[adjlist[top-1][i]-1] = true ;
                    st.push(make_pair(adjlist[top-1][i], top)) ;   // first element in the pair is the child while the second element is its parent 
                }
            }
        }
    }
    // this functionb purpose is to solve our question

    int solve(vector<int> &data){
        int ans = INT_MAX ;
        while(!st.empty()){
            // cout<<st.top().first<<" "<<st.top().second<<endl ;
            sum[st.top().second-1] = sum[st.top().second-1] + data[st.top().first-1] + sum[st.top().first -1];
            st.pop() ;    
        }
        sum[0] = sum[0] + data[0] ; 
        // this step is done because as I said sum[i] is the sum of all the nodes which are descendants of the node i except the node i's value
        for(int i = 1 ; i < vertices ;i++){
            sum[i] = sum[i] + data[i] ; // this step is done because as I said sum[i] is the sum of all the nodes which are descendants of the node i except the node i's value
            ans = min(ans, abs((sum[0]-sum[i])-sum[i])) ;
            // we are having n-1 edges so traversing through those n-1 edges 
        }
        return ans ;
    }
};
int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    int n = data.size() ;
    graph g(n) ;
    int m = edges.size() ;
    for(int i = 0 ; i < m ; i++){
        g.add(edges[i][0], edges[i][1]) ;
    }
    g.bfs() ;
    int ans = g.solve(data) ;
    return ans ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    vector<int> data(n, 0) ;
    int m = 0 ;
    cin>>m ;
    vector<vector<int>> edges(m, vector<int>(2,0)) ;

    for(int i = 0 ; i < n ; i++){
        cin>>data[i] ;
    }
    for(int i = 0 ; i < m ; i++){
        cin>>edges[i][0] ;
        cin>>edges[i][1] ;
    }

    int ans = cutTheTree(data, edges) ;
    cout<<ans<<endl ;

    return 0 ;
}

/*
sum[st.top().second-1] = sum[st.top().second-1] + data[st.top().first-1] + sum[st.top().first -1];

this is the main step we are calculating the sum from bottom of the tree till top 

as we know stack contains the child parent relation from bottom of the tree till the root so thats the reason why we are using stack 
we need last added child parent pair to be accessed. 

there is no harm in using vector also but we need to traverse from the back and calculate the sum[i]
in place of st.push({})
we need to have this lets say vector<pair<int, int>> vec ; is defined in the private

vec.push_back(make_pair(adjlist[top-1][i], top))

while caluclating sum we need to calculate from the back of the vector 

for(int i = vec.size()-1 ; i >= 0; i--){
    sum[vec[i].second-1] = sum[vec[i].second-1] + data[vec[i].first] + sum[vec[i].first-1] ;
}

even this solves our purpose but just to make our life easier using a data structure stack.

we know that sum[0] is the sum of all node values except root node 
*/