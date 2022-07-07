#include<iostream>
#include<string>
using namespace std ;

/*
Function overloading is a feature of object-oriented programming where two or more functions can have the same name but 
different parameters. When a function name is overloaded with different jobs it is called Function Overloading. In Function 
Overloading “Function” name should be the same and the arguments should be different. Function overloading can be considered 
as an example of a polymorphism(compile time) feature in C++.
*/

// Parameters should have a different type

void add(int a, int b){
    int res ; 
    res = a + b ;
    cout<<"sum is "<<res<<endl ;
    return  ;
}
void add(double a, double b){    // atleast one data type must change 
    double res ;
    res =  a + b ;
    cout<<"sum is "<<res<<endl ;
    return  ;
}
// no of parameters is different 
void add(int a, int b, int c){
    int res ;
    res = a + b +c ;
    cout<<"sum is "<<res<<endl ;
    return  ;
}

// Parameters should have a different sequence of parameters.
void add(int a, double b){
    cout<<"sum is "<<(a + b)<<endl ; 
    return ;
}
void add(double a, int b){
    cout<<"sum is "<<(a+b)<<endl ;
}


/// Important 
void fun(char *a){
    cout<<"non-const fun() "<<a<<endl ;
}

void fun(const char *a){
    cout<<"const fun() "<<a<<endl;
}
void fun(const int &i){
    cout << "fun(const int &) called "<<i<<endl ;
}
void fun(int &i){
    cout << "fun(int &) called "<<i<<endl  ;
}

/*
Main Note :

Function overloading is possible in C++ and Java but only if the functions must differ from each other by the types 
and the number of arguments in the argument list. However, functions can not be overloaded if they differ only 
in the return type. 

Reason :
Function overloading comes under the compile-time polymorphism. During compilation, the function signature is checked. 
So, functions can be overloaded, if the signatures are not the same. The return type of a function has no effect on 
function overloading, therefore the same function signature with different return type will not be overloaded. 

Example: if there are two functions: int sum() and float sum(), these two will generate a compile-time error as 
function overloading is not possible here.
*/

/*
int fun() { return 10; }
  
char fun() { return 'a'; }
// compiler error as it is a new declaration of fun() with diff return type
*/


/*                  Functions that can not be overloaded                   */

/*
1.) Function declarations that differ only in the return type.

2.) Member function declarations with the same name and the name parameter-type-list cannot be overloaded 
if any of them is a static member function declaration. For example, following program fails in compilation. 

class Test {
   static void fun(int i) {}
   void fun(int i) {}  
};
 
int main()
{
   Test t;
   getchar();
   return 0;
}


3.) Parameter declarations that differ only in a pointer * versus an array [] are equivalent. 
That is, the array declaration is adjusted to become a pointer declaration. Only the second and subsequent 
array dimensions are significant in parameter types. For example, following two function declarations are equivalent. 

int fun(int *ptr);
int fun(int ptr[]); // redeclaration of fun(int *ptr)


4.) Parameter declarations that differ only in the presence or absence of const and/or volatile are equivalent. 
That is, the const and volatile type-specifiers for each parameter type are ignored when determining which 
function is being declared, defined, or called. For example, following program fails 
in compilation with error “redefinition of `int f(int)’ “ Example: 

program 1  compilation error 
int f ( int x) {
  return x+10;
}

int f ( const int x) {
  return x+10;
}

int main() {  
getchar();
return 0;
}

// PROGRAM 2 (Compiles and runs fine)
#include<iostream>
using namespace std;

void fun(char *a)
{
cout << "non-const fun() " << a;
}

void fun(const char *a)
{
cout << "const fun() " << a;
}

int main()
{
const char *ptr = "GeeksforGeeks";
fun(ptr);
return 0;
}

C++ allows functions to be overloaded on the basis of the const-ness of parameters only if the const parameter 
is a reference or a pointer. That is why program 1 failed in compilation, but program 2 worked fine. 
This rule actually makes sense. In program 1, the parameter ‘i’ is passed by value, so ‘i’ in fun() is a copy of ‘i’ in main(). 
Hence fun() cannot modify ‘i’ of main(). Therefore, it doesn’t matter whether ‘i’ is received as a const parameter 
or a normal parameter. When we pass by reference or pointer, we can modify the value referred or pointed, 
so we can have two versions of a function, one which can modify the referred or pointed value, other which can not.

5.) wo parameter declarations that differ only in their default arguments are equivalent. For example, 
following program fails in compilation with error “redefinition of `int f(int, int)’ “ 

int f ( int x, int y) {
    return x+10;
}
 
int f ( int x, int y = 10) {
    return x+y;
}
 
int main() {    
  f(a,b);
  return 0;
}

*/


/*
You can overload functions across namespaces. For example:

#include <iostream>
using namespace std;

// Original X.h:
int f(int);
// Original Y.h:
int f(char);

// Original program.c:
#include "X.h"
#include "Y.h"

int main(){
f('a'); // calls f(char) from Y.h
}



Namespaces can be introduced to the previous example without drastically changing the source code:

#include <iostream>
using namespace std;

i// New X.h:
namespace X {
f(int);
}

// New Y.h:
namespace Y {
f(char);
}

// New program.c:
#include "X.h"
#include "Y.h"

using namespace X;
using namespace Y;

int main(){
f('a'); // calls f() from Y.h
}

*/
int main(){
    int a = 3 ;
    int b = 6 ;
    int c = 9 ;
    double d = 12 ;
    double e = 15 ;
    add(a,b) ;
    add(a,b,c) ;
    add(a,d) ;
    add(d,a) ;
    char arr[]  = {'N','a','m','m','u'} ;
    const char *ptr = "GeeksforGeeks";          
    /*
    If  we remove const before char and we compile it we get a warning if const is there no error dont know why
    so thats why I defined arr that way 
    ISO C++ forbids converting a string constant to ‘char*’ 
    */
    fun(ptr);   // constant one is called as defined const
    fun(arr) ;
    const int i = 10;
    fun(i);      //  fun(const int &) called
    int z = 9 ;
    fun(z) ;    // fun(int &) called 
    return 0 ;
}

