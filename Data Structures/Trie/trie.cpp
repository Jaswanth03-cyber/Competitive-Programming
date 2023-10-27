#include <bits/stdc++.h>
using namespace std ;

struct TrieNode{
    map<char, TrieNode*> mp ;
    bool isword ;

    TrieNode(){
        isword = false ;
    }
};

class Trie{
    TrieNode *root ;
    public:

    Trie(){
        root = new TrieNode() ;
    }

    void Insert(string word){
        int n = word.length() ;
        TrieNode *temp = root ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                TrieNode *node = new TrieNode() ;
                temp->mp.insert({word[i], node}) ;
            }
            temp = temp->mp[word[i]] ;
        }
        temp->isword = true ;
    }

    bool search(string word){
        int n = word.length() ;
        TrieNode *temp = root ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                return false ;
            }
            temp = temp->mp[word[i]] ;
        }
        return temp->isword ;
    }

    bool doesprefixexist(string word){
        int n = word.length() ;
        TrieNode *temp = root ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                return false ;
            }
            temp = temp->mp[word[i]] ;
        }
        return true ;
    }
};

/* if in case if he gives us words of type "..abc" and we have to check and also . can match with any character so we have do recursively 
checking all of them, check the below question

https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
*/
class newsearch{
    void search(string word, int index, TrieNode* node, bool &ans){
        if(index == word.length()){
            if(node->isword){
                ans = true ;
            }
            return ;
        }

        if(word[index] != '.'){
            if(node->mp.find(word[index]) != node->mp.end()){
                search(word, index+1, node->mp[word[index]], ans) ;
            }
            else{
                return ;
            }
        }
        else{
            for(auto it = node->mp.begin() ; it != node->mp.end() ; it++){
                search(word, index+1, it->second, ans) ;
            }
        }
    }

    bool searchword(string word){
        int i = 0 ;
        bool ans = false ;
        TrieNode* temp = root ;
        search(word, i, temp, ans) ;
        return ans ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Trie trie ;
    trie.Insert("car") ;
    trie.Insert("cat") ;
    trie.Insert("done") ;
    trie.Insert("try") ;
    trie.Insert("train") ;
    trie.Insert("alien") ;
    cout<<trie.search("car")<<endl ;
    return 0 ;
}