#include <bits/stdc++.h>

using namespace std;

/*
In checking of cyclicity I have added whether parent == node because they told ther are edges from node to node itself 
and also here if there is cycle then not infinite paths in that cycle nodes must reach till last vertex if none of the vertices are in the
path from node 1 to node 4 then of no use even though cycle is present so even though cycle is present either the cycleend or cyclestart vertices
these must have a path to last vertex to check what all vertices that can reach last vertex do a dfs on last vertex in the reverse graph.

and while checking cycle its not any cycle works only cycle in the path from 1 to 4 so check for cycle when dfs starting from first vertex only

I guess you have to check all the cycles that are in the path from 1 do not just return I guess tore all the cycle starts and end in a vector of pairs
and now loop through them if none of them leads to final vertex then compute total number of paths.
*/
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<vector<int>> revlist ;
    vector<char> color ;
    vector<bool> visited ;
    vector<bool> revisited ;
    int cycle_start ;
    int cycle_end ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        color.resize(n, 'w') ;
        revlist.resize(n) ;
        visited.resize(n, false) ;
        revisited.resize(n, false) ;
        cycle_start = -1 ;
        cycle_end = -1 ;
    }
    
    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        revlist[dest].push_back(src) ;
    }
    
    bool cycledfs(int src, int parent){
        color[src] = 'g' ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            if(color[node] == 'w'){
                if(cycledfs(node, src)){
                    return true ;
                }
            }
            else if(color[node] == 'g'){
                cycle_start = node ;
                cycle_end = src ;
                return true ;
            }
        }
        color[src] = 'b' ;
        return false ;
    }
    
    void dfsdest(int src){
        if(revisited[src]){
            return ;
        }
        revisited[src] = true ;
        int size = revlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = revlist[src][i] ;
            dfsdest(node) ;
        }
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
    
    void solve(){
        dfsdest(vertices-1) ;
        if(cycledfs(0, 0)){
            if(revisited[cycle_start] || revisited[cycle_end]){
                cout<<"INFINITE PATHS"<<endl ;
                return ;
            }   
        }
        stack<int> st ;
        dfs(0, st) ;
        vector<long long> noofpaths(vertices, 0) ;
        noofpaths[0] = 1 ;
        int mod = 1e9 ;
        while(!st.empty()){
            int top = st.top() ;
            st.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i] ;
                noofpaths[node] = (noofpaths[node] + noofpaths[top])%mod ;
            }
        }
        cout<<noofpaths[vertices-1]<<endl ;
    }
};
void countPaths(int n, vector<vector<int>> edges) {
    graph g(n) ;
    int size = edges.size() ;
    for(int i = 0 ; i < size ; i++){
        g.add(edges[i][0]-1, edges[i][1]-1) ;
    }
    g.solve() ;
    return ;
}


int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int nodes = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    countPaths(nodes, edges);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


/*
It has been a prosperous year for King Charles and he is rapidly expanding his empire. In fact, he recently invaded his neighboring 
country and set up a new kingdom! This kingdom has many cities connected by one-way roads. To ensure higher connectivity, two cities are 
sometimes directly linked by more than one road.

In the new kingdom, King Charles has made one of the cities his financial capital and another city his warfare capital. He wants a better 
connectivity between these two capitals. The connectivity of a pair of cities,  and , is defined as the number of different paths from city  
to city . A path may use a road more than once if possible. Two paths are considered different if they do not use the same sequence of roads 
the same number of times.

There are  cities numbered  to  in the new kingdom and  one-way roads. City  is the financial capital and city  is the warfare capital. 
Determine the number of different paths between cities  and . Since the number may be large, print the result modulo(1e9) 

Note: Two roads may connect the same cities, but they are still considered distinct for path connections. For example, there are  cities 
connected by  roads as shown in the following graph:


*/
