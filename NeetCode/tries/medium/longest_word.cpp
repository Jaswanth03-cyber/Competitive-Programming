#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-word-in-dictionary/
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

    void add(string word){
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

    bool canbuild(string word){
        int n = word.length() ;
        TrieNode* temp = root ;
        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                return false ;
            }
            temp = temp->mp[word[i]] ;
            if(!temp->isword){
                return false ;
            }
        }
        return temp->isword ;
    }
};




class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie ;
        int n = words.size() ;
        for(int i = 0 ; i < n ; i++){
            trie.add(words[i]) ;
        }  
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            if(trie.canbuild(words[i])){
                if(ans == "" || (ans.length() < words[i].length()) || (words[i].length() == ans.length() && !lexicographical_compare(ans.begin(), ans.end(), words[i].begin(), words[i].end()))){
                    ans = words[i] ;
                }
            }
        }
        return ans ;
    }
};

/*
i have slightly changed the search function if we notice after the update of temp I am checking another thing that 
for each word checking is every prefix a word in the trie or not so that is what was asked in the question.
ans also lexicographical smallest 

that function returns true if first range is strictly lexicographically smallest than the second one
*/