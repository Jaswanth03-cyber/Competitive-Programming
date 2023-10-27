#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/map-sum-pairs/
*/
struct TrieNode{
    map<char, TrieNode*> mp ;
    bool isword ;
    int value ;
    int prefixsum ;
    TrieNode(){
        isword = false ;
        value = 0 ;
        prefixsum = 0 ;
    }
};

class Trie{
    TrieNode* root ;
    public:
    Trie(){
        root = new TrieNode() ;
    }

    void add(string word, int key){
        int n = word.length() ;
        TrieNode* temp = root ;
        int currentvalue = search(word) ;
        int change = key - currentvalue ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                TrieNode* node = new TrieNode() ;
                temp->mp.insert({word[i], node}) ;
            }
            temp= temp->mp[word[i]] ;
            temp->prefixsum += change ;
        }
        temp->value = key ;
        temp->isword = true ;
    }

    int sum(string word){
        int n = word.length() ;
        TrieNode* temp = root ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                return 0 ;
            }
            temp = temp->mp[word[i]] ;
        }
        ans = temp->prefixsum ;
        return ans ;
    }

    int search(string word){
        int n = word.length() ;
        TrieNode* temp = root ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                return 0 ;
            }
            temp = temp->mp[word[i]] ;
        }
        return temp->value ;
    }
};

class MapSum {
public:
    Trie trie ;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        trie.add(key, val) ;    
    }
    
    int sum(string prefix) {
        return trie.sum(prefix) ;
    }
};

/*
if a word already exists then just find the value and note the difference and now we have to add that difference to every prefix
that is prefix of the given word so that is what we are doing and the end updating the value of the given word so while calculating the 
prefix sum just return back the prefix sum 

note for every prefix there will be a TrieNode that will be there after the prefix either having entries in the map or may not
if not having entries in the map in the sense we have gone through the end of a particular word.
*/