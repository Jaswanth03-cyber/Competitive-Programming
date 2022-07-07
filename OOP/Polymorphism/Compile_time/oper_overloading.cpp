#include<iostream>
#include<cmath>
using namespace std ;

/*
Some operators like +,-,*,/ ... so on are defined for primitive user types not for user defined data types
but we can define them for user defined data types also, here we are not overriding the inbuilt operation but 
adding the operator a new quality 

see for ex 
int a, b 
int c = a + b ; is fine 
but 
class A{

};
A a1, a2, a3 ;
a3 = a1 + a2 ; 
this is a compile time error so we over load the operators.
*/
class complex{
    private:
    int real ;
    int imag ;
    public:
    complex(int a, int b){
        this->real = a ;
        this->imag = b ;
    }
    complex(){
        this->real = 0 ;
        this->imag = 0 ;
    }
    int getreal(){
        return this->real ;
    }
    int getimag(){
        return this->imag ;
    }
    double arg(){
        double rad ;
        rad = abs(sqrt((this->real)*(this->real) + (this->imag)*(this->imag))) ;
        return rad ;
    }

    /*
    Now we will overload +, - and * operators for complex class 

    complex operator + (complex &obj) and 
    complex operator+ (complex &obj)    both are same don't for get operator that is more imp 
    */

    complex operator + (complex &obj) ;          // defining here but implementing outside the class just an example how to do


    /*{   // even if u write complex obj working is same, even const complex &obj is working same 
        complex res ;
        res.real = this->real + obj.real ;
        res.imag = this->imag + obj.imag ;
        return res ;
    }
    */
    complex operator - (complex &obj){  

        // // even if u write complex obj working is same, even const complex &obj is working same here this matters when u want to change obj variables
        complex res ;
        res.real = this->real - obj.real ;
        res.imag = this->imag - obj.imag ;
        return res ;
    }
    complex operator * (complex &obj){  // even if u write complex obj working is same, even const complex &obj is working same 
        complex res ;
        res.real = this->real*obj.real - this->imag*obj.imag ;
        res.imag = this->real*obj.imag + this->imag*obj.real ;
        return res ; 
    }
    void display(){
        if(this->imag > 0){
            cout<<this->real<<" + i"<<this->imag<<endl ;
        }
        else if(this->imag < 0){
            cout<<this->real<<" - i"<<abs(this->imag)<<endl ;
        }
        else{
            cout<<this->real<<endl ;
        }
        return ;
    }

};

complex complex :: operator + (complex &obj){
    complex res ;
    res.real = this->real + obj.real ;
    res.imag = this->imag + obj.imag ;
    return res ;
}

class Fraction{
    private:
        int num, den;
    public:
        Fraction(int n, int d){ 
            num = n; den = d ; 
        }

// Conversion operator: return float value of fraction 
    operator float() const {
        return float(num) / float(den);
    }
};

int main(){
    complex c1(1,2) ;
    complex c2(3,3) ;
    complex c3(6,6) ;
    complex c4(9,9) ;
    complex c5,c6,c7,c9 ;
    c5 = c1 + c2 ;          // c5 = c1 + c2; is internally translated as ComplexNumber c5 = c1.operator+ (c2); in order
    c6 = c2 - c3 ;
    c7 = c2*c1 ;
    c5.display() ;
    c6.display() ;
    c7.display() ;
    c1.display() ;
    c2.display() ;
    c3.display() ;
    Fraction f(2, 5);
    float val = f;     // this works only when using that class obj not for all lets see for ex
    cout << val <<endl ;
    float a = 9.99 ;
    cout<<a<<endl ;
    return 0 ;
}