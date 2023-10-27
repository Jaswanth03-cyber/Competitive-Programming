#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/implement-trie-prefix-tree/
*/
struct TrieNode{
    map<char, TrieNode*> mp ;
    bool isword ;
    TrieNode(){
        isword = false ;
    }
};

class TrieDs{
    TrieNode* root ;
    public:
    TrieDs(){
        root = new TrieNode() ;
    }

    void Insert(string word){
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

    bool search(string word){
        int n = word.length() ;
        TrieNode* temp = root ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                return false ;
            }
            temp = temp->mp[word[i]] ;
        }
        return temp->isword ; 
    }

    bool isprefix(string word){
        int n = word.length() ;
        TrieNode* temp = root ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                return false ;
            }
            temp = temp->mp[word[i]] ;
        }
        return true ;   
    }
};

class Trie {
    TrieDs trie ;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        trie.Insert(word) ;
    }
    
    bool search(string word) {
        return trie.search(word) ; 
    }
    
    bool startsWith(string prefix) {
        return trie.isprefix(prefix) ; 
    }
};

