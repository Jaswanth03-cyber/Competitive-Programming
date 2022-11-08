#include<bits/stdc++.h>
using namespace std ;
class hashtable{
    private:
    int size ;
    int *elements ;
    int hash_function(int key){
        int index = key%(this->size) ;
        return index ;
    }
    public:
    hashtable(int cap){
        size = cap ;
        elements = new int[cap] ;
        for(int i = 0; i < this->size; i++){
            elements[i] = -1 ;
        }
    }
    void insert(int key){
        int index = hash_function(key) ;
        int current_index = index ;
        while(elements[current_index] != -1 ){
            if(elements[current_index] == 0){
                break ;
            }
            current_index = (current_index + 1)%(this->size) ;
            if(current_index == index){
                cout<<"the table is full"<<endl ;
                return ;
            }
        } 
        elements[current_index] = key ;
        cout<<"Successfully inserted the key "<<key<<" at index "<<current_index<<endl ;
        return ;
    }
    int search(int key){
        int index = hash_function(key) ;
        int current_index = index ;
        while(elements[current_index] != -1){
            if(elements[current_index] == key){
                return current_index ;
            }
            else{
                current_index = (current_index + 1)%(this->size) ;
            }
            if(current_index == index){
                break ;
            }
        }
        return -1 ;
    }
    void delete_element(int key){
        int index = search(key) ;
        if(index >= 0 && index < this->size){
            elements[index] = 0 ;       // taking 0 as tombstone X element 
            cout<<"Deleted the element "<<key<<" at index "<<index<<endl ;
        }
        else{
            cout<<"There is no element with the given key to delete"<<endl ;
        }
        return ;
    }
    ~hashtable(){
        delete[] elements ;
    }
};
int main(){


    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    hashtable H(100) ;
    H.insert(20) ;
    H.insert(21) ;
    H.delete_element(21) ;
    H.insert(120) ;
    int i =  H.search(120) ;
    cout<<i<<endl ;
    H.insert(3) ;
    H.insert(9) ;
    H.insert(99);
    H.delete_element(6) ;

    
    return 0 ;
}