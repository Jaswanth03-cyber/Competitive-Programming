#include<iostream>
#include<vector>
using namespace std ;
int main(){
    vector<pair<int, int>> v ;
    v.push_back(make_pair(1,2)) ;
    v.push_back(make_pair(3,4)) ;
    v.push_back(make_pair(5,6)) ;
    v.push_back(make_pair(7,8)) ;
    v.push_back(make_pair(9,10)) ;
    v.push_back(make_pair(11,12)) ;
    v.push_back(make_pair(13,14)) ;
    v.push_back(make_pair(15,16)) ;
    

    v.emplace_back(17,18) ;      // we can even use this also over here 


    /*for(auto i = v.begin(); i != v.end() ; i++){
        cout<<*i.first<<endl ;
    }*/

    /*
    we can use almost same fuctions as before but now bit updated differently we can access the elements in the following way 
    rest all are same as vectors itself .
    */

    for(auto i = v.begin(); i != v.end() ; i++){
        cout<<i->first<<endl ;
    }

    for(auto i = v.begin(); i != v.end() ; i++){
        cout<<i->second<<endl ;
    }

    cout<<v.size()<<endl ;

    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl ;
    }

    auto j = v.begin() ;
    v.erase(j + 4) ; //deleting vector at position 4

    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl ;
    }

    v.pop_back() ; // removing the last element 

    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl ;
    }


    int a = v.front().first ;
    cout<<a<<endl ;
    cout<<v.front().second<<endl ;      // simillarly for back 

    
    return 0 ;
}