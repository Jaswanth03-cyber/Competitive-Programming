#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2) {
        vector<int>ans;
        stack<int>mystack;
         int i,j,k,l;
        int hash[1000001]={0};
        int n=nums2.size();
        for(int k:nums2){
            if(!mystack.empty()){
                int value=k;
                while(!mystack.empty() && value>mystack.top()){
                    hash[mystack.top()]=value;
                    mystack.pop();
                }
            }
            mystack.push(k);
        }
        while(!mystack.empty()){
           hash[mystack.top()]=-1;
           mystack.pop();
        }
        for(int k:nums1){
            ans.push_back(hash[k]);
        }
        return ans;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}