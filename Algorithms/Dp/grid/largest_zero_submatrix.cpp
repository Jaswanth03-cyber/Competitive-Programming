#include<bits/stdc++.h>
using namespace std ;

int zero_matrix(vector<vector<int>> &a, int n, int m) {
    int rows = n;
    int columns = m;

    int ans = 0;
    vector<int> d(columns, -1), d1(columns), d2(columns);
    stack<int> st;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (a[i][j] != 0){
                d[j] = i;
            }
        }

        for (int j = 0; j < columns; ++j) {
            while (!st.empty() && d[st.top()] <= d[j]){
                st.pop();
            }
            d1[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = columns - 1; j >= 0; --j) {
            while (!st.empty() && d[st.top()] <= d[j]){
                st.pop();
            }
            d2[j] = st.empty() ? m : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = 0; j < columns; ++j)
            ans = max(ans, (i - d[j]) * (d2[j] - d1[j] - 1));
    }
    return ans;
}

int main(){

    int n ; 
    int m ;
    cin>>n ;
    cin>>m ; 
    vector<vector<int>> a ; 
    a.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        a[i].resize(m) ;
    }
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            cin>>a[i][j] ;
        }
    }
    int ans = zero_matrix(a, n, m) ;
    cout<<ans<<endl ;
    return 0;
}
