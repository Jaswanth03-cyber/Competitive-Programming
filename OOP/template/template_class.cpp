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

