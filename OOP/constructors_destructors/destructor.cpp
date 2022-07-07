#include<iostream>
#include<string>
using namespace std ;

/*
If we do not write our own destructor in class, compiler creates a default destructor for us. The default destructor works 
fine unless we have dynamically allocated memory or pointer in class. When a class contains a pointer to memory allocated 
in class, we should write a destructor to release memory before the class instance is destroyed. 
This must be done to avoid memory leak.
*/

/*
Note:

Yes, In fact, it is always a good idea to make destructors virtual in base class when we have a virtual function.
See virtual destructor for more details, we will see it at the time of inheritence 
*/

struct student{
    string name ;
    int id ;
};
class Class{
    private:
    student *first ;
    int size ;
    int capacity ;
    public:
    Class(int n){
        first = new student[n] ;   // dynamically allocating the memory so we must define a destructor for sure 
        this->size = 0 ;
        this->capacity = n ;
    }
    void add_student(string in, int roll){
        first[size].name = in ;
        first[size].id  = roll ;
        this->size++ ;
    }
    int getstrength(){
        return this->size ;
    }
    int getcapacity(){
        return this->capacity ;
    }
    void display(){
        for(int i = 0 ; i < this->size ; i++){
            cout<<first[i].name<<" "<<first[i].id<<endl ;
        }
        return ;
    }
    ~Class(){
        cout<<"destructor is called "<<endl ;
        delete[] first ;     // destructor for dynamically allocated memory 
    }
};

class matrix{
    private:
    int **arr ;           // for 2d arrays
    int rows ;
    int columns ;
    public:

    matrix(int n){
        this->rows = n ;
        this->columns = n ;

    // this is the way how we dynamically allocate memory for 2d arrays 
        arr = new int*[n] ;
        for(int i = 0 ; i < this->rows ;i++){
            arr[i] = new int[n] ;
        }

        for(int i = 0 ; i < this->rows ; i++){
            for(int j = 0 ; j < this->columns ; j++){
                if(i != j){
                    arr[i][j] = 0 ;
                }
                else{
                    arr[i][j] = 1 ;
                }
            }
        }
    }

    void display(){
        for(int i = 0 ; i < this->rows ; i++){
            for(int j = 0 ; j < this->columns ; j++){
                cout<<arr[i][j]<<" " ;
            }
            cout<<endl ;
        }
    }
    /*
    This is the way how we write destructor for a 2d array for which memory is allocated dynamially
    */
    ~matrix(){
        for(int i = 0 ; i < this->rows ; i++){
            delete[] arr[i] ;
        }
        delete[] arr ;
        cout<<"destructor is called "<<endl ;
    }
};
int main(){
    matrix M(9) ;
    M.display() ;

    Class btech(10) ;
    string name1 = "nammu" ;
    string name2 = "jassu" ;
    string name4 = "rooma" ;
    string name3 = "navya" ;
    string name5 = "bhuvan" ;
    btech.add_student(name1,1) ;
    btech.add_student(name2,2) ;
    btech.add_student(name3,3) ;
    btech.add_student(name4,4) ;
    btech.add_student(name5,5) ;
    btech.display() ;
    return 0 ;
}