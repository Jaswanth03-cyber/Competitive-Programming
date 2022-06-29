#include<iostream>
#include<string.h>
using namespace std ;
struct person{
    string firstname ;
    string lastname ;
    string fullname ;
};
class flight{
    private:
    int *seat_number;
    bool *occupied ;
    int cardinality ;
    int capacity ;
    struct person *name ;
    public:
    flight(int a){
        capacity = a ;
        seat_number = new int[capacity] ;
        occupied = new bool[capacity] ;
        cardinality = 0 ;
        name = new person[capacity] ;
        for(int i=0; i < capacity ; i++){
            seat_number[i] = i +1 ;
            occupied[i] = false ;
        }
    }
    void empty_seats(){
        int a ;
        a = capacity - cardinality ;
        cout<<"No of empty seats is "<<a<<endl ;
    }
    void add_customer(){
        if(cardinality == capacity){
            cout<<"Sorry sir Seats have been filled"<<endl ;
            return ;
        }
        int id ;
        for(int i = 0; i < capacity ; i++){
            if(occupied[i] == false){
                id = i ;
                break ;
            }
        }
        string first_name ;
        string last_name ;
        cout<<"Please tell me your first name :"<<endl ;
        cin>>first_name ;
        name[id].firstname = first_name ;
        cout<<"Please tell me your last  name :"<<endl ;
        cin>>last_name ;
        name[id].lastname = last_name ;
        name[id].fullname = first_name + " " + last_name ;
        occupied[id] = true ;
        cout<<"Your seat number is "<<seat_number[id]<<endl ;
        cardinality++ ;
        return ;
    }
    void deleteseat(int seatid){
        int i ;
        i = seatid -1 ;
        cout<<name[i].firstname<<" "<<name[i].lastname<<" your ticket is being cancelled as per your request"<<endl ; 
        occupied[i] = false ;
        cardinality-- ;
    }
    void print_last_names(){
        int m = 0 ;
        for(int i = 0 ; i < capacity ; i++){
            if(occupied[i] == true ){
                m++ ;
            }
        }
        string sortnames[m] ;
        int a = 0 ;
        for(int i = 0; i < capacity; i++){
            if(occupied[i] == true){
                sortnames[a] = name[i].lastname ;
                a++ ;
            }
        }
        char sortlastnames[m][50], temp[50] ;
        for(int i = 0 ; i < m ; i++){
            strcpy(sortlastnames[i], sortnames[i].c_str()) ;
        }
        for(int i = 0; i < m ; i++){
            for(int j = i+1 ; j < m; j++){
                if(strcmp(sortlastnames[i], sortlastnames[j]) > 0){
                    strcpy(temp, sortlastnames[i]) ;
                    strcpy(sortlastnames[i], sortlastnames[j]) ;
                    strcpy(sortlastnames[j], temp) ;
                }
            }
        }
        cout<<"last name of the passengers is as follows "<<endl ;
        for(int i =0 ; i < m ; i++){
            cout<<sortlastnames[i]<<endl ;
        }
        cout<<endl ;
        return ;
    }
    void print_first_names(){
        int m = 0 ;
        for(int i = 0 ; i < capacity ; i++){
            if(occupied[i] == true ){
                m++ ;
            }
        }
        string sortnames[m] ;
        int a = 0 ;
        for(int i = 0; i < capacity ; i++){
            if(occupied[i] == true){
                sortnames[a] = name[i].firstname ;
                a++ ;
            }
        }
        char sortfirstnames[m][50], temp[50] ;
        for(int i = 0 ; i < m ; i++){
            strcpy(sortfirstnames[i], sortnames[i].c_str()) ;
        }
        for(int i = 0; i < m ; i++){
            for(int j = i+1 ; j < m; j++){
                if(strcmp(sortfirstnames[i], sortfirstnames[j]) > 0){
                    strcpy(temp, sortfirstnames[i]) ;
                    strcpy(sortfirstnames[i], sortfirstnames[j]) ;
                    strcpy(sortfirstnames[j], temp) ;
                }
            }
        }
        cout<<" first name of the passengers is as follows "<<endl ;
        for(int i =0 ; i < m ; i++){
            cout<<sortfirstnames[i]<<endl ;
        }
        cout<<endl ;
        return ;
    }
    void printfullnames(){
        int m = 0 ;
        for(int i = 0 ; i < capacity ; i++){
            if(occupied[i] == true ){
                m++ ;
            }
        }
        string sortnames[m] ;
        int a = 0 ;
        for(int i = 0; i < 12 ; i++){
            if(occupied[i] == true){
                sortnames[a] = name[i].fullname ;
                a++ ;
            }
        }
        char sortfullnames[m][50], temp[50] ;
        for(int i = 0 ; i < m ; i++){
            strcpy(sortfullnames[i], sortnames[i].c_str()) ;
        }
        for(int i = 0; i < m ; i++){
            for(int j = i+1 ; j < m; j++){
                if(strcmp(sortfullnames[i], sortfullnames[j]) > 0){
                    strcpy(temp, sortfullnames[i]) ;
                    strcpy(sortfullnames[i], sortfullnames[j]) ;
                    strcpy(sortfullnames[j], temp) ;
                }
            }
        }
        cout<<"name of the passengers is as follows "<<endl ;
        for(int i =0 ; i < m ; i++){
            cout<<sortfullnames[i]<<endl ;
        }
        cout<<endl ;
        return ;
    }
    ~flight(){
        delete[] seat_number ;
        delete[] occupied ;
        delete[] name ;
    }
};
int main(){
    flight Airindigo(30) ;
    cout<<"--------------------------- Welcome to Airidigo flights---------------------------"<<endl ;
    cout<<"To choose a function, enter its letter label:"<<endl ;
    cout<<"a) Show number of empty seats"<<endl  ;
    cout<<"b) Assign a customer to a seat"<<endl  ;
    cout<<"c) Delete a seat assignment"<<endl ;
    cout<<"d) Print last name of seat holder in alphabetical order"<<endl ;
    cout<<"e) Print first name of seat holder in alphabetical order"<<endl ;
    cout<<"f) Print full name of seat holder in alphabetical order"<<endl ;
    cout<<"---------------------------------------------------------------------------------"<<endl ;
    while(true){
        char in ;
        cout<<"Please click any alphabet shown in the driver menu "<<endl ;
        cin>>in ;
        if(in == 'a'){
            Airindigo.empty_seats() ;
        }
        else if(in == 'b'){
            Airindigo.add_customer() ;
        }
        else if(in == 'c'){
            int n ; 
            cout<<"Please tell us your seat id"<<endl ;
            cin>>n ;
            Airindigo.deleteseat(n) ;
        }
        else if(in == 'd'){
            Airindigo.print_first_names() ;
        }
        else if(in == 'e'){
            Airindigo.print_last_names() ;
        }
        else if(in == 'f'){
            Airindigo.printfullnames() ;
        }
        else {
            cout<<"Give input according to the driver menu given above "<<endl ;
        }
        cout<<"---------------------------------------------------------------------------------"<<endl ;
    }
    return 0 ;
}