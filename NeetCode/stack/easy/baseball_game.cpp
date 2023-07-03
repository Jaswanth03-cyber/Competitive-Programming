#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0 ;
        int val = 0 ;
        int temp1 = 0 ;
        int temp2 = 0 ;
        stack<int> st ;
        for(int i = 0 ; i < operations.size(); i++){
            if(operations[i] == "D"){
                temp1 = 2*st.top() ;
                st.push(temp1) ;
            }
            else if(operations[i] == "C"){
                st.pop() ;
            }
            else if(operations[i] == "+"){
                temp1 = st.top() ;
                st.pop() ;
                temp2 = st.top() + temp1 ;
                st.push(temp1) ;
                st.push(temp2) ;
            } 
            else{
                val = stoi(operations[i]) ;
                st.push(val) ;
            }
        }

        while(!st.empty()){
            ans = ans + st.top() ;
            st.pop() ;
        } 
        return ans ;     
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<string> operations(n, " ");
    for(int i = 0 ; i < n ; i++){
        cin>>operations[i] ;
    }

    Solution ans ;
    int res = ans.calPoints(operations) ;
    cout<<res<<endl ;
    return 0 ;
}