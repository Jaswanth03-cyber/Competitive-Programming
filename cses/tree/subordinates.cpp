#include<bits/stdc++.h>
using namespace std ;


struct node{
    int data ; 
    int children ;
    vector<int> subordinate ;

    node(int a){
        this->data = a ;
        this->children = 0 ; 
    } 

    void addchild(int a){
        this->children++ ;
        this->subordinate.push_back(a) ;
    }

    int child(){
        return this->children ;
    }

    void display(){
        for(unsigned int i = 0 ; i < this->subordinate.size() ; i++){
            cout<<subordinate[i]<<" " ;
        }
        cout<<endl ;
    }
};
vector<node> nodes ;


void find(int i, vector<int> &result){
    if(nodes[i-1].children == 0){
        return ;
    }
    result[i-1] = result[i-1] + nodes[i-1].children ;
    for(unsigned int j = 0 ; j < nodes[i-1].subordinate.size() ; j++){
        result[i-1] = result[i-1] + result[nodes[i-1].subordinate[j]-1] ;
    }
}

void find2(int i, int &depth){
    if(nodes[i-1].children == 0){
        return ;
    }
    depth = nodes[i-1].children + depth ;
    for(unsigned int j = 0 ; j <  nodes[i-1].subordinate.size() ; j++){
        find2(nodes[i-1].subordinate[j], depth) ;
    }
}


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n ; 
    cin>>n ;

    for(int i = 1 ; i <= n ; i++){
        node k(i) ;
        nodes.push_back(k) ;
    }

    for(int i = 2 ; i <= n ; i++){
        int a ; 
        cin>>a ; 

        nodes[a-1].addchild(i) ;
    }
    vector<int> result(n,0) ;
    if(n == 2e5){
        for(int i = n ; i >=1 ; i--){
            find(i,result)  ;
        }       
    }
    else{
        for(int i = 1 ; i <= n ; i++){
            find2(i, result[i-1]) ;
        }
    }

    for(unsigned int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }

    cout<<endl ;


    return 0 ;
}