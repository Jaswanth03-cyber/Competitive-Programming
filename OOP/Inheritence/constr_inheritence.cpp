#include<iostream>
using namespace std ;
class shapes{
/*

if we keep this protected or public and in the constructor defined in the triangle if we are changing the sides value 
and if we create an object of the derived class then the constructor of the derived class is called to initialise the value 
of sides not that of surface but if we are not changing or assigning any value to the sides in the triangle class constructor 
then the value of sides will be 0 as base class constructor is called for initialisation of the variable sides

*/
    protected:      
    int sides ;
    public:
    shapes(){
        this->sides = 0 ;
    }
    void display(){
        cout<<"no of sides for this surface is "<<this->sides<<endl ;
        return ;
    }
    void set_sides(int n){
        this->sides = n ;
        return ;
    }
};
class triangle : private shapes{      // constructor of the base class is being called irrespective of the access specifier
    private:
    int vertices ;
    public:
    triangle(){
        this->vertices = 3 ;
        this->sides = 3 ;   
/*       
u can even use this->set_sides(this->vertices) or just set_sides(this->vertices) but before than that do not 
forget to initialise vertices as we are using that as parameter instead u can directly pass 3 then u can write these 
fucntions even before initialising the vertices in the constructor implementation
*/
    }
    void display_triangle(){
        this->display() ;
        cout<<"no of vertices of the triangle is "<<this->vertices<<endl ;
        return ;
    }
};
int main(){
    triangle t ;
    t.display_triangle() ;
    shapes s ;
    s.display() ;
    return 0 ;
}