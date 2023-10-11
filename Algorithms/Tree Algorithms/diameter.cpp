#include <bits/stdc++.h>
using namespace std ;

/*
we know the second method do dfs from random vertex and then find the maxdistance node, from that node do dfs now maxdistance will be the diameter 
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> toleaf ;
    vector<int> maxdistance ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        toleaf.resize(n, 0) ;
        maxdistance.resize(n, 0) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs(int src, int parent){
        int size = adjlist[src].size() ;
        toleaf[src] = 0 ;
        int maxtoleaf1 = -1, maxtoleaf2 = -1 ; // for each node these two contain the maximum toleaf of all their childrens
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            
            if(node == parent){
                continue ;
            }

            dfs(node, src) ;

            toleaf[src] = max(toleaf[node]+1, toleaf[src]) ;   //update the roleaf[src] after dfs as toleaf[node] is calculated 

            if(toleaf[node] >= maxtoleaf1){ // so if toleaf[node] is greater than previosuly computed maxtoleaf1 update maxtoleaf1 to this value and maxtoleaf2 to maxtoleaf1
                maxtoleaf2 = maxtoleaf1 ;
                maxtoleaf1 = toleaf[node] ;
            } // if in case maxtoleaf1 may be greater already but maxtoleaf2 can be small than this toleaf[node] so if it is the case update it.
            else if(toleaf[node] > maxtoleaf2){
                maxtoleaf2 = toleaf[node] ;
            }
        } //now after all the computation for each node top 2 maxdistances to leaves sum them 
        maxdistance[src] = max(maxtoleaf2 + maxtoleaf1 + 2, maxtoleaf1 + 1) ; // maxtoleaf1+1 because if there is only one child.
        return ;
    }

    void solve(){
        dfs(0, 0) ;
        int diameter = 0 ;
        for(int i = 0 ; i < vertices ; i++){
            diameter = max(diameter, maxdistance[i]) ;
        }
        cout<<diameter<<endl ; 
    }
    
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    graph g(n) ;
    
    int src, dest ;
    for(int i = 0 ; i < n-1 ; i++){
        cin>>src>>dest ;
        g.add(src-1, dest-1) ;
    }
    g.solve() ;
    return 0 ;
}

/*
here logic is that for each node we try to find two nodes which are distinct children of the taken node and distances of these two is the maximum 
among all the childs the node has and maxdistance with the selected node as the highest point is 
max(toleaf1+toleaf2 + 2, toleaf1 + 1) +2 because include the edge between parent and children adn second argument is because 
if we just have one child then maxdistance to leaf is just 1 + toleafofchild.
*/ 

/*
toLeaf(x): the maximum length of a path from x to any leaf
• maxLength(x): the maximum length of a path whose highest point is x
For example, in the above tree, toLeaf(1) = 2, because there is a path 1 → 2 → 6,
and maxLength(1) = 4, because there is a path 6 → 2 → 1 → 4 → 7. In this case,
maxLength(1) equals the diameter.
Dynamic programming can be used to calculate the above values for all nodes
in O(n) time. First, to calculate toLeaf(x), we go through the children of x,
choose a child c with maximum toLeaf(c) and add one to this value. Then, to
calculate maxLength(x), we choose two distinct children a and b such that the sum
toLeaf(a)+toLeaf(b) is maximum and add two to this sum.

*/