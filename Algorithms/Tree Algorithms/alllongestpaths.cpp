#include <bits/stdc++.h>
using namespace std ;

/*
Second way of solving this problem is that by first calculating dfs through a random node, get the maxdistance node say a calculate dfs distances
through this node to all other nodes now take the maximum distance node from this a, lets say that max distance node be b, now comoute dfs through b
and finally maxdistance for each node = max(dist[a][i], dist[b][i])
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> paththrough ;
    vector<int> firstmaxdistance ;
    vector<int> secondmaxdistance ;
    public:

    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        firstmaxdistance.resize(n, 0) ;
        secondmaxdistance.resize(n, 0) ;
        paththrough.resize(n, 0) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs1(int src, int parent){
        int size = adjlist[src].size() ;

        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dfs1(node, src) ;

            if(firstmaxdistance[node]+1 > firstmaxdistance[src]){
                secondmaxdistance[src] = firstmaxdistance[src] ;
                firstmaxdistance[src] = firstmaxdistance[node] + 1 ;
                paththrough[src] = node ;
            }
            else if(firstmaxdistance[node] + 1 > secondmaxdistance[src]){
                secondmaxdistance[src] = firstmaxdistance[node] + 1 ;
            }
        }
    }

    void dfs2(int src, int parent){
        int size = adjlist[src].size() ;

        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }

            if(paththrough[src] == node){
                if(secondmaxdistance[src] + 1 > firstmaxdistance[node]){
                    secondmaxdistance[node] = firstmaxdistance[node] ;
                    firstmaxdistance[node] = secondmaxdistance[src] + 1 ;
                    paththrough[node] = src ;
                }
                else if(secondmaxdistance[src] + 1 > secondmaxdistance[node]){
                    secondmaxdistance[node] = secondmaxdistance[src] + 1 ;
                }
            }
            else{
                secondmaxdistance[node] = firstmaxdistance[node] ;
                firstmaxdistance[node] = firstmaxdistance[src] + 1 ;
                paththrough[node] = src ;
            }
            dfs2(node, src) ;
        }
    }

    void solve(){
        dfs1(0, -1) ;
        dfs2(0, -1) ;

        for(int i = 0 ; i < vertices ; i++){
            cout<<firstmaxdistance[i]<<" " ;
        }
        cout<<endl ;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    int m = n-1 ;
    graph g(n) ;
    int src, dest =0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src-1, dest-1) ;
    }
    g.solve() ;
    return 0 ;
}

/*
logic :
for each node we try to have these two always find the maximum two distances that are starting from that node 
so we do this in two dfs
first dfs :


this gives for each node what are the two maximum distances from their child and we also maintain through which child is the firstmaxdistance coming
so computations are done after the dfs of leaves and then to the top 
so do not forget that +1st wherever they are they correspond to the edge between the src and the connected child which we are processing at that time
similarly like diameter we take top 2 distances through the child for a node.

second dfs 
now through this for each node we try to calculate the maxdistance of a node through its parent and compare the ones through its child to get the
top two maximums 

so now before computation of  dfs for leaves, here calculations must be done as we want maximum paths of nodes through their parents so those parent nodes
calculation must be done before that of children. 

so now here what we check is for a src node if the firstmaxdistance goes through the child x which we are processing now 
then update the firstmaxdistance[childnode]  according to the secondmaxdistance of the parent so if in case secondmaxdistance[parent]+1 > firstmaxdistance[childnode]
so update the second and first maxdistances of the child node and also update the paththrough which firstmaxdistance of childnode is going
if not the condition is true just check if secondmaxdistance can be changed or not if not fine

if so first condition that firstmaxdiatance[src] is not passing through that of the child which is being processed
then obviously it means for the source there is a path which is max than the distance through the child node which is being processed
so firstmaxdistance[childnode] will be maximum in that path so just update the secondmaxdistance and firstmaxdistance and paththrough which the
firstmaxdistance is going.


so in the first dfs1 using child maxdistances we are calculating maxdistances of nodes through their children and in the second dfs using
parent computations from the first dfs we are computing the maxdistance of the children through their parents
now at last for each node we are having two maxdistances for each node they max either go through their children or either go through their parents.


+1s correspond to the edge between the src asnd child do not forget it.
*/