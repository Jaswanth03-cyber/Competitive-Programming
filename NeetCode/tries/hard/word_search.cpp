#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/word-search/
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
        TrieNode *temp = root ;

        for(int i = 0 ; i < n ; i++){
            if(temp->mp.find(word[i]) == temp->mp.end()){
                TrieNode* node = new TrieNode() ;
                temp->mp.insert({word[i], node}) ;
            }
            temp = temp->mp[word[i]] ;
        }
        temp->isword = true ;
    }

    TrieNode* Root(){
        return root ;
    }
};
class Solution {
public:
    void search(vector<vector<char>> &board, int n, int m, int x, int y, TrieNode* node, string currword, bool &ans, vector<vector<bool>> &visited){
        if(visited[x][y]){
            return ;
        }

        if(node->mp.find(board[x][y]) == node->mp.end()){
            return ;
        }

        visited[x][y] = true ;
        currword = currword + board[x][y] ;
        node = node->mp[board[x][y]] ;
        if(node->isword){
            ans = true ;
            return ;
        }

        if(x != 0){
            search(board, n, m, x-1, y, node, currword, ans, visited) ;
        }
        if(x != n-1){
            search(board, n, m, x+1, y, node, currword, ans, visited) ;
        }
        if(y != 0){
            search(board, n, m, x, y-1, node, currword, ans, visited) ;
        }
        if(y != m-1){
            search(board, n, m, x, y+1, node, currword, ans, visited) ;
        }
        visited[x][y] = false ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        Trie trie ;
        trie.add(word) ;
        int n = board.size() ;
        int m = board[0].size() ;
        bool ans = false ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    TrieNode* node = trie.Root() ;
                    vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
                    search(board, n, m, i, j, node, "", ans, visited) ;
                    if(ans){
                        return ans ; 
                    }
                }
            }
        }
        return ans ;    
    }
};