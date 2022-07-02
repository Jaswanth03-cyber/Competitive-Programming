# Template

A template is a simple and yet very powerful tool in C++. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need sort() for different data types. Rather than writing and maintaining the multiple codes, we can write one sort() and pass data type as a parameter. 
C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by keyword ‘class’.

## How do template work 
Templates are expanded at compiler time. This is like macros. The difference is, the compiler does type checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.  This means we define and implement the function/class once in the code but compiled code has as many functions as many we call with different data types, for example we defined max function using template in the main(), we used it for int and double so in the compiled code we will have two functions for max one with int and another with double like function overloading

## Function Templates 
Function Templates We write a generic function that can be used for different data types. Examples of function templates are sort(), max(), min(), printArray(). You can refer to the following code 

```c++
#include<iostream>
using namespace std ;
// remember that namespace std contains max, min, sort, swap functions inbuilt so before declaring function name just be carefull
template <typename T>     
/*
not sufficient if we declare once at the top, we have to write this before every function/class we can have sam name T or u can even use another name
where we want to use template that is function for more data types, we can even write template <class T> class/typename both are fine 
*/

T mymax(T x, T y){     
    if(x > y){
        return x ;
    }
    else if(x == y){
        return x ;
    }
    else{
        return y ;
    }
}
template <typename T>     // instead of T u can even write template<typename U> and use U in place of T for this function
T mymin(T x, T y){
    if(x > y){
        return y ;
    }
    else if(x == y){
        return x ;
    }
    else{
        return x ;
    } 
}
 template <typename T>
 void myswap(T &a, T &b){
    T c = b ;
    b = a ;
    a = c ;
    return ;
}
template <typename T>  // yes u have to declare every time before the function/class we use otherwise compile time error 
void mysort(T arr[], int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[i]){
                myswap(arr[j], arr[i]) ;
            }
        }
    }
    return ;
}
int main(){
    cout<<mymax<int>(3,9)<<endl ;
    cout<<mymax<double>(3.6, 9.6)<<endl ;
    cout<<mymin<int>(3,9)<<endl ;
    cout<<mymin<double>(3.6, 9.6)<<endl ;
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);
    mysort<int>(a, n) ;
    for(int i = 0 ; i < n ; i++){
        cout<<a[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}
```
## Output 
```
9
9.6
3
3.6
10 20 30 40 50 

```

## Class Templates 
Class Templates Like function templates, class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 

Following is a simple example of template Array class. 

```c++
#include <iostream>
using namespace std;

template <typename T> class Array {
private:
	T* ptr;
	int size;

public:
    /*
    Array(T arr[], int s) ;   constructor
    void print() ;          
    If we just define and implementation is done later then we have to write as shown below in comments outside the class
    */
	Array(T arr[], int s){          
	    ptr = new T[s];
	    size = s;
	    for (int i = 0; i < size; i++){
		    ptr[i] = arr[i]; 
        }   
    }
	void print(){
        for(int i = 0 ; i < size; i++){
            cout<<ptr[i]<<" " ;
        }  
        cout<<endl ;
    }
};

/*template <typename T> Array<T>::Array(T arr[], int s)
{
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		ptr[i] = arr[i];
}

template <typename T> void Array<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}*/

// We can even have more variables inside it
/*                                               There is some error over here not able to find 
template <typename T, typename U> class A {
    private:
    T x;
    U y;
    public:
    A(T a, U b){ 
        x = a ;
        y = b ; 
    }
    void print(){
        cout<<this->x<" "<<this->y<<endl ;
    }
};*/

int main(){
	int arr[5] = { 1, 2, 3, 4, 5 };
	Array<int> a(arr, 5);
	a.print();
    /*
    A<char, char> n('a', 'b');
    A<int, double> b(3, 9.0);
    n.print() ;
    b.print() ;
    */
	return 0;
}


```

```
1 2 3 4 5 
```

## What is the difference between function overloading and templates ?

Both function overloading and templates are examples of polymorphism feature of OOP. Function overloading is used when multiple functions do similar operations, templates are used when multiple functions do identical operations.

