#include <bits/stdc++.h>
using namespace std ;

/*
So the idea is this 
we are taking prefix sum and calculating the modulo of the sum so 
now in the prefix array prefix[i] denotes the sum of the elements from 0 to i modulo m, we need to calculate the maximum sub array sum modulo m 

so  we need to find index i to j such that sum of elements modulo m between these index will be maximum 

so if we see S[i, j]%m = (prefix[j] - prefix[i] + m)%m  if in case prefix[i] > prefix[j] adding m will help thats all adn we new that prefix[i] and prefix[j] < m
so we need to find i, j such that prefix[j] - prefix[i] is negative and small in magnitude so that adding m to will maximise the sum and also i < j

so we while processing at an index j we need to find an index i which is closer to the prefix[j] this search can be linear at worst case at index 
i = n -1 this search can again be O(n) so overall O(N^2) we need to have a data structure such that search time is optimized as we can see if we use
BST then search space can be O(logn) but also notice that the insert time can be O(n) in BST if so prefixes are in increasing order so we need a balanced tree

so balanced tree can be an avl tree or red black trees. so set can be the data structure for that, so searching a prefix[i] which is >= prefix[j]+1 lower bound
as if prefix[i] == prefix[j] sub array sum modulo m will be zero that is least possible, if you want min value then initialize the ans = m -1 and
change max to min. and also search for upper bound not lower bound.  
*/
int maxsubarraysum(vector<int> &arr, int m){
    int prefix = 0, ans = 0 ;
    set<int> st ;
    st.insert(ans) ;
    int n = arr.size() ;
    for(int i = 0 ; i < n ; i++){
        prefix = (prefix + arr[i])%m ;
        ans = max(ans, prefix) ;

        auto it = st.lower_bound(prefix + 1) ;
        if(it != st.end()){
            ans = max(ans, prefix - *it + m) ;
        }
        st.insert(prefix);
    }
    return ans ;
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }
    int m =0 ;
    cin>>m ;
    int ans = maxsubarraysum(arr, m) ;
    cout<<ans<<endl ;
    return 0 ;
}