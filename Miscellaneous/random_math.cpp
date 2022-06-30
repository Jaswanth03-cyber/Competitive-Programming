#include<iostream>
#include<cstdlib>   // If it is C then we use cstdlib.h this we are using for random generation of numbers 
#include<cmath>     // this is for mathematical functions we use if in C we use math.h 
#include<time.h>  // for using time(0) as seed 
using namespace std ;
#define max 60        // defining global keyword for this file 


/*Note: If random numbers are generated with rand() without first calling srand(), 
your program will create the same sequence of numbers each time it runs.
Syntax: 
int rand(void): 
returns a pseudo-random number in the range of [0, RAND_MAX).
RAND_MAX: is a constant whose default value may vary 
\between implementations but it is granted to be at least 32767.
if no srand() program will create same sequence of random numbers on every program run. 

The srand() function sets the starting point for producing a series of pseudo-random integers.
If srand() is not called, the rand() seed is set as if srand(1) were called at program start. 
Any other value for seed sets the generator to a different starting point. 
Syntax: 
void srand( unsigned seed ): 
Seeds the pseudo-random number generator used by rand() with the value seed.

Note: The pseudo-random number generator should only be seeded once, before any calls to rand(), 
and the start of the program. It should not be repeatedly seeded, or reseeded every time you wish to generate a new batch of pseudo-random numbers. 
Standard practice is to use the result of a call to srand(time(0)) as the seed. However,
time() returns a time_t value which vary everytime and hence the pseudo-random number vary for every program call. 

*/


/*
double sin(double) : This function takes angle (in degree) as an argument and return its sine value that could be verified using sine curve.
double cos(double) : This function takes angle (in degree) as an argument and return its cosine value that could be verified using cosine curve.
double tan(double) : This function takes angle (in degree) as an argument and return its tangent value. This could also be verified using Trigonometry as Tan(x) = Sin(x)/Cos(x).
double sqrt(double) : This function takes number as an argument and return its square root value. Number can not be negative value.
int abs(int) : This function takes integer number as an argument and return its absolute value. It means, the output will always be positive regardless of sign of input.
double pow(double, double) : This function takes one argument as base and other as exponent.
double hypot(double, double) : This function requires two sides of the right angled triangle to give output as its hypotenuse.
double floor(double) : This functions returns the integer value lesser or equal to argument passed in the function.
double fabs(double) : This function returns the absolute value of any number.
double acos(double) : This function returns the arc cosine of argument. The argument to acos() must be in the range -1 to 1 ; otherwise, a domain error occurs.
double asin(double) : This function returns the arc sine of argument. The argument to asin() must be in the range -1 to 1 ; otherwise, a domain error occurs.
double atan(double) : This function returns the arc tangent of arg.
double atan2(double, double) : This function returns the arc tangent of (double a)/(double b).
double ceil(double) : This function returns the smallest integer as double not less than the argument provided.
double cosh(double) : This function returns the hyperbolic cosine of argument provided. The value of argument provided must be in radians.
double tanh(double) : This function returns the hyperbolic tangent of argument provided. The value of argument provided must be in radians.
double log(double) : This function takes a number and returns the natural log of that number.
*/

int main(){
    for(int i = 0; i < 5; i++){
        cout <<rand()%max<< " ";
    }                     // this for loop produces same sequence every time we run the executable file after compilation
    cout<<endl ;

    srand(time(0)) ; // after this no need of seed again 

    for(int i = 0 ; i < 5 ; i++){
        cout<<rand()%max<<" " ;
    }                      // this for loop produces different sequence every time we run the executable file after compilation
    cout<<endl ;


    for(int i = 0 ; i < 5 ; i++){
        cout<<rand()%max<<" " ;
    }                      // this for loop produces different sequence every time we run the executable file after compilation
    cout<<endl ;

/* Mathematical functions */

    double logarithm = log(2) ; // base is e 
    cout<<logarithm<<endl ;

    double x = 2.3;
    cout << "Sine value of x=2.3 : " << sin(x) << endl;
    cout << "Cosine value of x=2.3 : " << cos(x) << endl;
    cout << "Tangent value of x=2.3 : " << tan(x) << endl;
 
    double y = 0.25;
    cout << "Square root value of y=0.25 : " << sqrt(y) << endl;
 
    int z = -10;
    cout << "Absolute value of z=-10 : " << abs(z) << endl;
    cout << "Power value: x^y = (2.3^0.25) : " << pow(x, y) << endl;
 
    x = 3.0;
    y = 4.0;
    cout << "Hypotenuse having other two sides as x=3.0 and"
         << " y=4.0 : " << hypot(x, y) << endl;
 
    x = 4.56;
    cout << "Floor value of x=4.56 is : " << floor(x) << endl;
 
    x = -4.57;
    cout << "Absolute value of x=-4.57 is : " << fabs(x) << endl;
 
    x = 1.0;
    cout << "Arc Cosine value of x=1.0 : " << acos(x) << endl;
    cout << "Arc Sine value of x=1.0 : " << asin(x) << endl;
    cout << "Arc Tangent value of x=1.0 : " << atan(x) << endl;
 
    y = 12.3;
    cout << "Ceiling value of y=12.3 : " << ceil(y) << endl;
 
    x = 57.3; // in degrees
    cout << "Hyperbolic Cosine of x=57.3 : " << cosh(x) << endl;
    cout << "Hyperbolic tangent of x=57.3 : " << tanh(x) << endl;
 
    y = 100.0;
    // Natural base with 'e'
    cout << "Log value of y=100.0 is : " << log(y) << endl;
 
    return 0 ;
}