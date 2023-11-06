#include <bits/stdc++.h>
using namespace std ;


// You're faced at work with a distributed micro-services architecture. Each remote node contains a set of resources it
// provides, and a set of resources it depends on. You have gathered this information in the form of two maps
// (requiresMap and providesMap in the code below).
// You're asked to determine the correct startup sequence for the nodes so that all resources a node requires are being
// provided at the point it is started (i.e. the nodes that provide them have already been started) by providing a
// GetStartupSequence function.
// Example:
//     node      requires         provides
//      A        [c1, d1]         [a1, a2]
//      B        [a1]             []
//      C        []               [c1]
//      D        [c1]             [d1]
//
// On the example above, only one solution is possible: C -> D -> A -> B. The node C is the first to start as it has no
// dependencies, and once it's started, node D can be started as it's dependency is fulfilled (c1), which in turn allows the
// startup of node A as the dependencies on C (c1) and D (d1) are fulfilled; and finally that allows for the startup of B.
using NodeName = std::string;
using ResourceName = std::string;
using DependencyMap = std::unordered_map<NodeName, std::vector<ResourceName>>;
std::vector<NodeName> GetStartupSequence(DependencyMap requiresMap, DependencyMap providesMap);

/*
question has been asked in the da vinci bit different way of topo sort
*/

void dfs(NodeName src, stack<NodeName> &st, vector<vector<NodeName>> &adjlist, std::unordered_map<NodeName, int> &mp, std::unordered_map<NodeName, int> &visited){
    if(visited[src]){
        return ;
    }
    int size = adjlist[mp[src]].size() ;
    visited[src] = 1 ;
    for(int i = 0 ; i < size ; i++){
        NodeName node = adjlist[mp[src]][i] ;
        dfs(node, st, adjlist, mp, visited) ;
    }
    st.push(src) ;
}
std::vector<NodeName> GetStartupSequence(DependencyMap requiresMap, DependencyMap providesMap){
    std::unordered_map<ResourceName, vector<NodeName>> mpprovide ;
    std::unordered_map<ResourceName, vector<NodeName>> mprequire ;
    std::unordered_map<NodeName, int> mp ;
    int count = 0 ;

    for(auto it = requiresMap.begin() ; it != requiresMap.end() ; it++){
        int size = it->second.size() ;
        mp.insert({it->first, count++}) ;
        for(int i = 0 ; i < size ; i++){
            if(mprequire.find(it->second[i]) != mprequire.end()){
                mprequire[it->second[i]].push_back(it->first) ;
            }
            else{
                vector<NodeName> vec = {it->first} ;
                mprequire.insert({it->second[i], vec}) ;
            }
        }
    }

    std::vector<vector<NodeName>> adjlist ;
    adjlist.resize(requiresMap.size()) ;

    for(auto it = providesMap.begin() ; it != providesMap.end() ; it++){
        int size = it->second.size() ;
        for(int i = 0 ; i < size ; i++){
            int size2 = mprequire[it->second[i]].size() ;
            for(int j = 0 ; j < size2 ; j++){
                adjlist[mp[it->first]].push_back(mprequire[it->second[i]][j]) ;
            }
        }
    }

    int size = mp.size() ;
    stack<NodeName> st ;
    std::unordered_map<NodeName, int> visited ;
    for(auto it = mp.begin() ; it != mp.end() ; it++){
        visited.insert({it->first, 0}) ;
    }

    for(auto it = mp.begin() ; it != mp.end() ; it++){
        if(visited[it->first] == 0){
            dfs(it->first, st, adjlist, mp, visited) ;
        }
    }

    std::vector<NodeName> ans ;
    while(!st.empty()){
        ans.push_back(st.top()) ;
        st.pop() ;
    }

    return ans ;
}