#include<bits/stdc++.h>
using namespace std ;

//  there can be an edge between two strongly connected components 
/*
comp1->comp2->comp3 or 
comp3<-comp1->comp2 but there can not be a reverse edge which means this condensed graph is acyclic.
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<vector<int>> revlist ;
    vector<bool> visited ;
    vector<bool> revisited ;
    vector<int> component ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        revlist.resize(n) ;
        visited.resize(n, false) ;
        revisited.resize(n, false) ;
        component.resize(n, -1) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest);
        revlist[dest].push_back(src) ;
    }

    void dfs(int src, stack<int> &st){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            dfs(node, st) ;
        }
        st.push(src) ;
    }

    void revdfs(int src, int head){
        if(revisited[src]){
            return ;
        }
        revisited[src] = true ;
        component[src] = head ;
        int size = revlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = revlist[src][i] ;
            revdfs(node, head) ;
        }
    }

    void solve(vector<long long> &coins){
        stack<int> st ;
        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                dfs(i, st) ;
            }
        }
        int k = 0 ;
        while(!st.empty()){
            int top = st.top() ;
            st.pop() ;
            if(revisited[top]){
                continue ;
            }
            revdfs(top, k);
            k++ ;
        }

        map<int, set<int>> mp ;
        for(int i = 0 ; i < vertices ; i++){
            int size = adjlist[i].size() ;
            for(int j= 0 ; j < size ; j++){
                int node = adjlist[i][j] ;
                if(component[i] != component[node]){
                    mp[component[i]].insert(component[node]) ;
                }
            }
        }
        // component1 ->component2->component3 // this case we are missing modify from this line such that every case works over here.
        // cout<<"no of components :"<<k<<endl ;
        vector<long long> sum(k, 0) ;
        // cout<<"vertex components"<<endl ;
        for(int i = 0 ; i < vertices ; i++){
            // cout<<component[i]<<" "<<i<<endl ;
            sum[component[i]] += coins[i] ;
        }
        // cout<<"sum of components"<<endl ;
        for(int i = 0 ; i < k ; i++){
        //   cout<<sum[i]<<" "<<i<<endl ;
        }
        // cout<<"vertices between components "<<endl ;
        long long ans = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            // cout<<it->first<<" " ;
            for(auto it1 = it->second.begin() ; it1 != it->second.end() ; it1++){
                // cout<<*it1<<endl ;
                ans = max(ans, sum[it->first] + sum[*it1]) ;
            }
        }

        cout<<ans<<endl ;
    }
};
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0, m = 0;
    cin>>n ;
    cin>>m ;
    vector<long long> coins(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i] ;
    }

    graph g(n) ;
    int src = 0, dest = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src-1, dest-1) ;
    }

    g.solve(coins) ;
    return 0 ;
}