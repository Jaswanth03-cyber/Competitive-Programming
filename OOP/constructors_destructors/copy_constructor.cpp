#include<iostream>
#include<cmath>
using namespace std ;
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
    point(int a, int b, int c){      // parametrized constructor
        this->x = a ;
        this->y = b ;
        this->z = c ;
    }


    // point(point &p) ;       this is for implementing outside we have to define it in the class 
    /*
    U can even do this no need to copy all the variables of the class into new obj defined u can even copy only 2/1 value and set 
    the remaining variables of your wish 
    */

    point(point &p){
        this->x = p.x ;
        this->y = p.y ;
        this->z = p.z ;
    }
    void display(){
        cout<<this->x<<" "<<this->y<<" "<<this->z<<endl ;
        return ;
    }
    double distance(int a, int b, int c){
        double length ; 
        length = abs(sqrt((x-a)*(x-a) + (y-b)*(y-b) + (z-c)*(z-c))) ;
        return length ;
    }
    void changex(int a){
        this->x = a ;
    }
};

/*
If u want to implement outside the class syntax is as follows 

point :: point (int &p){
    this->x  = p.x ;
    this->y = p.y ;
    this->z = p.z ;
}

Note :

If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor for each class which 
does a member-wise copy between objects. The compiler-created copy constructor works fine in general. We need to define 
our own copy constructor only if an object has pointers or any runtime allocation of the resource like file handle, 
a network connection, etc.

for ex if you comment the copy constructor implemented above but u still run the code even then p5 and p6 will be created 
same as before but the difference is as shown below 

The default constructor does only shallow copy. 
but 
for ex no copy construtor defined but u called called copy constructor in the main 
point p6= p1 or point p6(p1)
it is not that if u change value in p1 value in p6 also changes no it is false just we copied the contents did not reference 
the objects

Deep copy is possible only with a user-defined copy constructor. In a user-defined copy constructor, 
we make sure that pointers (or references) of copied objects point to new memory locations. 
Here also it is not if u change values in p1 it changes in p6 or vice versa its false 

So even u define copy constructor or not define changing values in one does not effect othger u are just creating another object 
but the values same as of an object we have before 

*/

int main(){
    point p1 ;
    point p2(1,1,1) ;
    point p3(2,2,2) ;
    point p4(3,3,3) ;
    double length = p2.distance(0,0,0) ;
    cout<<length<<endl ;
    p2.display() ;
    p1.display() ;

    point p5 = p1 ;  

/*

even if you use p1 it will call copy constructor it does not care whether the parameter obj which we are passing 
is initiated with parametrized constructor or deafult constructor(that is no parameter constructor)

*/
    point p6(p3) ; // or point p6 = p3 ; copy constructor is called here tooo 
    p5.display() ;
    p6.display() ;
    p3.changex(9) ;
    p6.display() ;
    p3.display() ;
/*
differences betweeen copy constructor between assignment operator is as shown 

A copy constructor is called when a new object is created from an existing object, as a copy of the existing object. 
The assignment operator is called when an already initialized object is assigned a new value from another existing object. 
In the below example (1) calls the copy constructor and (2) calls the assignment operator. 
*/
    point t1(6,6,6), t2, t4(10,10,10) ;
    point t3 = t1 ;
    t2 = t4 ;
    t1.display() ;
    t2.display() ;
    t3.display() ;
    t1.changex(5) ;
    t4.changex(7) ;
    t2.changex(90) ;
    t3.changex(100) ;
    t1.display() ;
    t2.display() ;
    t3.display() ;
    t4.display() ;

    /*
    here already existing point t2 is assigned a new value t1, but t3 is created by copying t1 values 
    */


    /*
    In assignment also no referencing new object and new memories even if u change 
    value in one other does not change and vice versa, u can see for the above 
    */
    return 0 ;
}