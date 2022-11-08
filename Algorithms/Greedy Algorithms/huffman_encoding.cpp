#include<bits/stdc++.h>
using namespace std ;
typedef pair<int, char> pi ;
const char dollar = '$' ;


// Have to be updated not updated one 

void add(map<char, vector<int>> &result, char a, vector<int> &code){
    result.emplace(a, code) ;
    //code.clear() ;
}
struct node{
    int frequency ;
    char alphabet ;
    struct node *left ;
    struct node *right ;

    node(char a, int freq){
        this->alphabet = a ;
        this->frequency = freq ;
        this->left = nullptr ;
        this->right = nullptr ;
    }
};

class tree{
    public:
    node *top ;
    tree(){
        top = nullptr ;
    }

    void insert(node *a, node *b){
        int sum = a->frequency + b->frequency ;
        node *add = new node(dollar, sum) ;
        add->left = a ;
        add->right = b ;
        this->top = add ;
    }

    void traverse(node *root, vector<int> &code, map<char, vector<int>> &result){
        if(root->left){
            code.push_back(0) ;
            traverse(root->left, code, result) ;
        }
        if(root->right){
            code.push_back(1) ;
            traverse(root->right, code, result) ;
        }

        if((root->left == nullptr) && (root->right == nullptr)){

            char a = root->alphabet ;

            add(result, a, code) ;
        }
    }
};

map<char, int> find_freq(string &text){

    map<char, int> frequency ;

    set<char> character ; 
    for(unsigned int i = 0 ; i < text.length() ; i++){
        if(character.count(text[i]) == 0){
            character.insert(text[i]) ;
        }
    }
    for(auto i = character.begin() ; i != character.end() ; i++){
        frequency.insert({*i, 0}) ;
    }

    for(unsigned int i = 0 ; i < text.length() ; i++){
        auto k = frequency.find(text[i]) ;
        k->second++ ;
    }
    return frequency ;
}

map<char, vector<int>> huffman_encode(map<char, int> &frequency){

    map<char, vector<int>> result ;
    priority_queue<pi, vector<pi>, greater<pi>> pq ;

    for(auto i = frequency.begin() ; i != frequency.end() ; i++){
        pq.push(make_pair(i->second, i->first)) ;
    }


    tree huffman_tree ;

    node *a = new node(pq.top().second, pq.top().first) ;
    pq.pop() ;

    node *b = new node(pq.top().second, pq.top().first) ;
    pq.pop() ;

    huffman_tree.insert(a,b) ;

    while(!pq.empty()){ 
        node *vertex = new node(pq.top().second, pq.top().first) ;

        node *current_top = huffman_tree.top ;
        huffman_tree.insert(vertex, current_top) ;

        pq.pop() ;
    }

    vector<int> code ;
    huffman_tree.traverse(huffman_tree.top, code, result) ;

    return result ;
}





int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string input ;
    input = "hello" ;
    // cin>>input ;
    map<char, int> frequency = find_freq(input) ;

    /*
    for(auto i = frequency.begin() ; i != frequency.end() ; i++){
        cout<<i->first<<" "<<i->second<<endl ;
    }
    */
    map<char, vector<int>> result = huffman_encode(frequency) ;

    for(auto i = result.begin() ; i != result.end() ; i++){
        cout<<i->first<<" : " ;
        for(unsigned int j = 0 ; j < i->second.size() ; j++){
            cout<<i->second[j] ;
        }
        cout<<endl ;
    }
    return 0 ;
}
