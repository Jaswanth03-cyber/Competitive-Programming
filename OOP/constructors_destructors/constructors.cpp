#include<iostream>
#include<cmath>
using namespace std ;


/*
Note :
Constructor can not be declared virtual. this we will see when inheritence is discussed
*/

class point{
    private:
    int x ;
    int y ;
    int z ;
    public:
    point(){                 // this is a deafult constructor having no parameters 
        x = 0 ;
        y = 0 ;
        z = 0 ;
    }
    
    // point(int a, int b, int c) ;    if you want to implement outside the class 

    point(int a, int b, int c){      // parametrized constructor
        this->x = a ;
        this->y = b ;
        this->z = c ;
    }
    /*
    we can have more than one paramterized constructors that is constructor overloading similar to function overloading 

    Actually u can even say above it is constructor overloading as we defined 2 constructors one with no parameters one with parameters
    */
    void display(){
        cout<<this->x<<" "<<this->y<<" "<<this->z<<endl ;
        return ;
    }
    double distance(int a, int b, int c){
        double length ; 
        length = abs(sqrt((x-a)*(x-a) + (y-b)*(y-b) + (z-c)*(z-c))) ;
        return length ;
    }
};
   /*
    See if we do not define any parametrized constructor and u only have default constructor which u might define or not define
    so creating an object instance in the main by point p1 creates an object, but if u define a parametrized constructor and 
    do not define a default constructor that is a constructor with no arguments and if u define point p1 in main then it will 
    flash an error, do not think that it will take some default constructor, no it will not.

    Default constructor will be taken by the compiler only if u do not define any parametrized or user define default constructor 
    if u define any one of them then it will not take default constructor on its own, it will see for ones u defined. so be
    carefull while creating an object instance in the main when u define a parametrized conatructor/user defined deafult constructor
    */


// If you want to implement outside by just defining inside the class syntax is as shown 
/*
point :: point(int a, int b, int c){
    this->x = a ;
    this->y = b ;
    this->z = c ;   
}
*/
int main(){
    point p1 ;
    point p2(1,1,1) ;
    double length = p2.distance(0,0,0) ;
    cout<<length<<endl ;
    p2.display() ;
    p1.display() ;
}