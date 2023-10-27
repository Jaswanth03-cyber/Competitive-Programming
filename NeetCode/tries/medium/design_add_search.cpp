#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
*/
struct TrieNode{
    map<char, TrieNode*> mp ;
    bool isword ;
    TrieNode(){
        isword = false ;
    }
};

class Trie{
    TrieNode* root ;
    public:
    Trie(){
        root = new TrieNode() ;
    }

    void insert(string word){
        int n = word.length() ;
        TrieNode* temp = root ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                TrieNode* node = new TrieNode() ;
                temp->mp.insert({word[i], node}) ;
            }
            temp = temp->mp[word[i]] ;
        }
        temp->isword = true ;
    }

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


class WordDictionary {
    Trie trie ;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word) ;
    }
    
    bool search(string word) {
        bool ans = false;
        int i = 0 ;
        return trie.searchword(word) ;
    }
};
