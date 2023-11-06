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
    void search(vector<vector<char>> &board, int n, int m, int x, int y, TrieNode* node, string currword, vector<string> &ans, vector<vector<bool>> &visited){
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
            ans.push_back(currword) ;
            node->isword = false ;
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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = words.size() ;
        Trie trie ;
        for(int i = 0 ; i < n ; i++){
            trie.add(words[i]) ;
        }
        n = board.size() ;
        int m = board[0].size() ;
        vector<string> ans ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                TrieNode* node = trie.Root() ;
                vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
                search(board, n, m, i, j, node, "", ans, visited) ;
            }
        }
        return ans ;
    }
};

/*
inserting the elements in a trie now searching like a dfs here the thing is that 


also beore checking node->isword in search do not forget to add that board[x][y] to currword and also update node before checking isword


once visited its not that we should not visit and also once a word is found make isword to false to not repeat the same words again and again
as once remove visited[x][y] = false in the last and execute you will get an error 

there in the grid we have a cells of this type now if we start searching at h now h -> k -> f -> l now as l is visited from k to f to l we will not 
go but that is not the case as hklf can be there in the words so its not dfs like in graphs if we visit once we need not process its wrong we need 
to revisit that again if a word exists so after dfs at a particular cell we again make back visited[x][y] as false.

h k 
l f 

this is the example

"o", "a", "a", "n"
"e", "t", "a", "e"
"i", "h", "k", "r"
"i", "f", "l", "v"

["oath","pea","eat","rain","hklf", "hf"]

["oath","eat","hf"] wrong output if we do not change visited as once visited we are not revisiting but it should not be the case 

["oath","eat","hklf","hf"] correct one
*/