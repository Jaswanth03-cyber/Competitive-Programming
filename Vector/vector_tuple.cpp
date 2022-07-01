#include<iostream>
#include<vector>
#include<tuple>
using namespace std ;
int main(){
    vector<tuple<int, int, int>> v ;

    v.push_back(make_tuple(1,1,1)) ;
    v.push_back(make_tuple(2,4,8)) ;
    v.push_back(make_tuple(3,9,27)) ;
    v.push_back(make_tuple(4,16,64)) ;
    v.push_back(make_tuple(5,25,125)) ;
    v.push_back(make_tuple(6,36,216)) ; // for this we need to include tuple header file
    v.emplace_back(7,49,343) ;            // for this no need to include tuple header file better include everytime 

    for(int i = 0 ; i < v.size() ; i++){
        cout<<get<0>(v[i])<<" "<<get<1>(v[i])<<" "<<get<2>(v[i])<<endl ;
    }

    for(auto i = v.begin() ; i != v.end() ; i++){
        cout<<get<0>(*i)<<" "<<get<1>(*i)<<" "<<get<2>(*i)<<endl ;
    }


    auto a = v.begin() ;
    v.erase(a + 2) ;

    for(auto i = v.begin() ; i != v.end() ; i++){
        cout<<get<0>(*i)<<" "<<get<1>(*i)<<" "<<get<2>(*i)<<endl ;     // rest all are same as pair and vector only 
    }

    return 0 ;
}