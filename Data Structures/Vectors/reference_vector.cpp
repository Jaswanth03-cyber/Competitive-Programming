#include<iostream>
#include<vector>
using namespace std ;
void insertionsort(vector<float> &inp){        // to reference we have to do this way 
    if(inp.size() == 0 || inp.size() == 1){
        return ;
    }
    float key ;
    for (int i = 1; i < inp.size(); i++){
        key = inp[i];
        int j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && inp[j] > key)
        {
            inp[j + 1] = inp[j];
            j = j - 1;
        }
        inp[j + 1] = key;
    }
    return ;
}

void Insertionsort(vector<float> inp){        // lets see if we do not reference 
    if(inp.size() == 0 || inp.size() == 1){
        return ;
    }
    float key ;
    for (int i = 1; i < inp.size(); i++){
        key = inp[i];
        int j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && inp[j] > key)
        {
            inp[j + 1] = inp[j];
            j = j - 1;
        }
        inp[j + 1] = key;
    }
    return ;
}
int main(){
    vector<float> v ;
    v.push_back(0.897) ;
    v.push_back(0.565) ;
    v.push_back(0.656) ;
    v.push_back(0.1234) ;
    v.push_back(0.665) ;
    v.push_back(0.3434) ; 
    cout<<"The original vector is as shown :"<<endl ;
    for(auto i = v.begin() ; i < v.end(); i++){
        cout<<*i<<" " ;
    }
    cout<<endl ; 
    cout<<"when we did not pass by reference the vector after sort will be :"<<endl ;   
    Insertionsort(v) ;
    for(auto i = v.begin() ; i < v.end(); i++){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    cout<<"when we  pass by reference the vector after sort will be :"<<endl ;
    insertionsort(v) ;
    for(auto i = v.begin() ; i < v.end(); i++){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    return 0 ;

}