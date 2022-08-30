#include<bits/stdc++.h>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long t; 
    cin>>t;
    while (t--){
        long long y, x; cin >> y >> x;
        long long k = max(x, y);
        long long ans = (k-1)*(k-1);
        if(k&1){
            ans += (x + (k-y));
        }
        else{
            ans += (y + (k-x));
        }
        cout<<ans<<endl ;
    }
    return 0;
}