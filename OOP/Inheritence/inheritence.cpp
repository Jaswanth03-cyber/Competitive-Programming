#include<iostream>
using namespace std ;
// remember by deafult if u  do not mention any access specifier inside a class its private but in struct public
class person{
    private:
    string name ;
    int id ;
    public:
    /*
    this I have defined becuase we want set_person() details inside student class so overloaded as another function has two 
    parameters, so we can not know student name before, but we can even modify the set_student() taking four parameters
    and setting all the 4 variables that is name, id which are inherited from base class and self variables course and fee
    */
    void set_person(){      
        string nam ;
        int roll ;
        cout<<"Enter a name"<<endl ;
        cin>>nam ;
        cout<<"Enter an int roll no"<<endl ;
        cin>>roll ;
        this->name = nam ;
        this->id = roll ;
        return ;
    }
    void set_person(int roll, string nam){
        this->name = nam ;
        this->id = roll ;
        return ;
    }
    void display(){
        cout<<"Name is "<<this->name<<" and the id is "<<this->id<<endl ;
        return ;
    }
}; 


/*

    Pls do not get confused with access outside the class and access inside the class just calm down and think 


Here if the access specifier provided is public then all the public functions present in the derived and all the public functions
in the base class can be accessed by the derived class obj outside the class.

Here if the access specifier provided is protected then all the public functions present in the derived can only be accessed by 
the derived class obj outside the class, as public functions defined in the base class becomes protected in the derived class 
but u can access these protected functions inside the class or even another class can be derived from the derived class in which
these functions can be accessed only inside the class not by the object outside the class

Here if the access specifier is private then all the functions defined in the base class can not be accessed outside the class
only public functions defined in the derived class can be accessed outside the class by the derived class object and also remember
that if other class is derived from this derived class then the base class functions can not be accessed by the last class derived 
as the base class functions are private in the first derived class so can not be accessed by second derived class


 to understand better once change this access specifier and run the code u will get an idea

*/
class student : private person{
    private :
    string course ;
    int fee ;
    public:
    void set_student(string cour, int fe){
        this->set_person() ;
        this->course = cour ;
        this->fee = fe ;
        return ;
    }
    // can not be done as name and roll are private inside person class 
    /*
    void set_student(string nam, int roll, string cour, int fe){
        this->name = nam ;
        this->id = roll ;
        this->course = cour ;
        this->fee = fe ;
        return ;
    }
    */
    void display_student(){
        this->display() ;
        cout<<"course taken by the student is "<<course<<" and the fee paid is "<<fee<<endl ;
        // cout<<this->name<<endl ; not possible as name is private can not be accessed over here
        return ;
    }
    /*
    This function display defined over here overrided the display function defined in the parent class so this called inside the display_student()
    */

    /*
    void display(){
        cout<<"course taken by the student is "<<course<<" and the fee paid is "<<fee<<endl ;
        return ;
    }
    */
};

class first_student : private student{
    private: 
    string class_name ;
    public:
    void set_class(){

        /*
        this can not be written as not accessible 
        */
        // this->set_person() ;      
        this->set_student("cs207",1000 ) ;  // but this function can be accessed over here but this function is private in this class
        string nam ;
        cout<<"Enter your class number in words"<<endl ;
        cin>>nam ;
        this->class_name = nam ;
        return ;
    }
    void display_class(){
        cout<<"The class is "<<class_name<<endl ;
        return ;
    }
};
int main(){
    student s2 ;
    s2.set_student("cs207", 1000) ;
    // s2.set_student("nammu", 62, "cs201", 1000) ;
    s2.display_student();
    // s2.display() ;
    first_student s3 ;
    s3.set_class() ;
    s3.display_class() ;
    return 0 ;
}