#include<bits/stdc++.h>
using namespace std ;

int knapsack(vector<int> &price_books, vector<int> &pages_books, int max_cost, int n){

    vector<vector<int>> max_pages ;

    vector<int> price_book ;
    vector<int> pages_book ;
    price_book.push_back(-1) ;
    pages_book.push_back(-1) ;

    max_pages.resize(n+1) ;

    for(int i = 0 ; i < n ; i++){
        price_book.push_back(price_books[i]) ;
        pages_book.push_back(pages_books[i]) ;
    }

    for(int i = 0 ; i <=n ; i++){
        max_pages[i].resize(max_cost+1) ;
    }

    max_pages[0][0] = 0 ; 

    for(int i = 1 ; i <= n; i++){
        max_pages[i][0] = 0 ;
    }
    for(int i = 1 ; i <= max_cost ; i++){
        max_pages[0][i] = 0 ;
    }

    for(int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j <= max_cost ; j++){
            if(j < price_book[i]){
                max_pages[i][j] = max_pages[i-1][j] ;
            }
            else{
                max_pages[i][j] = max(max_pages[i-1][j], max_pages[i-1][j - price_book[i]] + pages_book[i]) ;
            }
        }
    }

    return max_pages[n][max_cost] ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    int max_cost ;
    cin>>n>>max_cost ;
    vector<int> price_book ;
    vector<int> pages_book ;

    for(int i = 0 ; i < n ; i++){
        int l ;
        cin>>l ;
        price_book.push_back(l) ;
    }
    for(int i = 0 ; i < n ; i++){
        int l ;
        cin>>l ;
        pages_book.push_back(l) ;
    }

    int result = knapsack(price_book, pages_book, max_cost, n) ;
    cout<<result<<endl ;
    return 0 ;
}