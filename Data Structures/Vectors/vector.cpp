#include<iostream>
#include<vector>    // header file name 
using namespace std ;

vector<int> one(){
    vector<int> s ;
    s.assign(6,9) ;
    return s ;
}

int main(){

    vector<int> s ;          // initial defining of vector 
    for(int i = 1 ; i < 10; i++){
        s.push_back(i*9) ;      // adding elelments to the vector 
    }

    auto g = s.begin() ; 

    // Returns a bidirectional  iterator pointing to the first element in the vector, its not of type int* or int 
    // so we write as auto so that during run time compiler finds the proper data type

    cout<<*g<<endl ;
    cout<<endl ;

    // cout<<*--g<<endl ;     this gives 0 as the output
    // int *t = s.begin() ;     this gives a compile time error
    // cout<<*s<<endl ;         this is an error

    // 1
    cout<<"1) " ;
    for(auto i = s.begin(); i != s.end(); i++){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    cout<<endl ;

    auto n = s.end() ; 

    //  Returns a bidirectional iterator pointing to the theoretical element that follows the last element in the vector, its not of type int* or int 
    // so we write as auto so that during run time compiler finds the proper data type

    cout<<*n<<endl ;    // see the output this gives 0
    cout<<endl ;

    cout<<*--n<<endl ;   // Now see the output obtained 
    cout<<endl ;

    // 2
    cout<<"2) " ;
    for(auto i = s.end() - 1 ; i != s.begin(); i--){
        cout<<*i<<" " ;
    }
    cout<<endl ;         // different start positions observe the outputs 
    cout<<endl ;

    // 3
    cout<<"3) " ;
    for(auto i = s.end() ; i != s.begin(); i--){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    cout<<endl ;

    // 4
    cout<<"4) " ;
    for(auto i = s.begin() ; i < s.end(); i++){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    cout<<endl ;

    // 5
    cout<<"5) " ;
    for(auto i = s.end()- 1 ; i >= s.begin(); i--){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    cout<<endl ;

    auto m = s.rbegin() ;

    // Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element its not of type int* or int 
    // so we write as auto so that during run time compiler finds the proper data type

    // auto m = s.rend() ;

    // Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

    // 6
    cout<<"6) " ;
    for(auto i = s.rbegin(); i < s.rend() ; i++){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    cout<<endl ;

    // 7
    cout<<"7) " ;
    for(auto i = s.rend() ; i >= s.rbegin() ; i--){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    cout<<endl ;

    // 8
    cout<<"8) " ;
    for(auto i = s.rend() - 1 ; i >= s.rbegin() ; i--){
        cout<<*i<<" " ;
    }
    cout<<endl ;
    cout<<endl ;


    // cbegin() – Returns a constant iterator pointing to the first element in the vector.

    //       auto m = s.cbegin() ; 
    //       cout<<*++m<<endl ; gives the output  not that it is constant 

    // cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
    // crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
    // crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

    int f = s.size() ;
    cout<<f<<endl ;
    cout<<endl ;
    // size() – Returns the number of elements in the vector.


    // max_size() – Returns the maximum number of elements that the vector can hold. it is 4611686018427387903

    int x = s.capacity() ;
    cout<<x<<endl ;
    cout<<endl ;
    
    // capacity() – Returns the size of the storage space currently allocated to the vector container expressed as number of elements
    // it changes as we push up more and more values first lets say we pushed 5 elements and capacity is 8 if we push 6 more elements
    // capacity value changes, we can think it as size of the array present 

    // resize(n) – Resizes the container so that it contains ‘n’ elements. it changes the container size that is the array size we talked above

    // empty() – bool rerturn Returns whether the container is empty, retyurns false if not empty

    // shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
    // lets say we pushed 5 elements now lets say capacity is 8, using this function capacity changes to 5 
    // s.shrink_to_fit() ;


    // reserve() – Requests that the vector capacity be at least enough to contain n elements.
    // N = 1e5 ;
    // s.reserve(N) ;

    // To access ith element s[i] 

    cout<<s[6]<<endl ;
    cout<<endl ;

    // another way .at[i]

    int d = s.at(2) ;
    cout<<d<<endl ;
    cout<<endl ;

    int a = s.front() ;
    cout<<a<<endl ;
    cout<<endl ;

    //  s.front() Returns a reference to the first element in the vector

    int b = s.back() ;
    cout<<b<<endl ;
    cout<<endl ;

    //  s.back() Returns a reference to the last element in the vector

    int *c = s.data() ;
    for(int i = 0 ; i < f; i++){
        cout<<c[i]<<" " ;
    }
    cout<<endl ;
    cout<<endl ;

    // .back() Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
    // its like int arr[100] then returning arr, we can acces elements as shown above 


    vector<int> p ;
    p = one() ;
    for(int i = 0 ; i < p.size(); i++){
        cout<<p[i]<<" " ;
    }
    cout<<endl ;
    cout<<endl ;

    // Function returning 

    // .assign(int size, int value)    it assigns new value to the vector elements by replacing old ones
    // vector<int> x 
    // x.assign(5,6) we have seen the usage in the function  

    s.push_back(90) ;

    //.push_back(value) It push the elements into a vector from the back

    s.pop_back() ;

    // It is used to pop or remove elements from a vector from the back.

    s.insert(s.begin(),100) ;
    // .insert(position, value )
    // position – It specifies the iterator which points to the position where the insertion is to be done.
    // val – It specifies the value to be inserted.

    // .insert(position, size, val)
    // position – It specifies the iterator which points to the position where the insertion is to be done.
    // size – It specifies the number of times a val is to be inserted at the specified position.
    // val – It specifies the value to be inserted.

    // .insert(position, iterator1, iterator2)
    // position – It specifies the position at which insertion is to be done in vector.
    // iterator1 – It specifies the starting position from which the elements are to be inserted
    // iterator2 – It specifies the ending position till which elements are to be inserted

    // removes the first element
    // s.erase(s.begin());
    // erase() function is used to remove elements from a container from the specified position or range.

    // vectorname.erase(position)
    // vectorname.erase(startingposition, endingposition)
    // Position of the element to be removed in the form of iterator.
    // or the range specified using start and end iterator so that Elements are removed from the specified position of the container.

    // inserts at the beginning
    // s.emplace(s.begin(), 5);
    //  It extends the container by inserting new element at position

    // Inserts 20 at the end
    // s.emplace_back(20);

    // .clear() It is used to remove all the elements of the vector container


    // vectorname1.swap(vectorname2)
    // Parameters: The name of the vector with which the contents have to be swapped, so finally All the elements of the 2 vectors are swapped.
 

                //                       Time Complexities                

// Random access – constant O(1)
// Insertion or removal of elements at the end – constant O(1)
// Insertion or removal of elements – linear in the distance to the end of the vector O(N)
// Knowing the size – constant O(1)
// Resizing the vector- Linear O(N)

/*
    // Assign vector
    vector<int> v;
 
    // fill the array with 10 five times
    v.assign(5, 10);
 
    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
 
    // inserts 15 to the last position
    v.push_back(15);
    int n = v.size();
    cout << "\nThe last element is: " << v[n - 1];
 
    // removes last element
    v.pop_back();
 
    // prints the vector
    cout << "\nThe vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
 
    // inserts 5 at the beginning
    v.insert(v.begin(), 5);
 
    cout << "\nThe first element is: " << v[0];
 
    // removes the first element
    v.erase(v.begin());
 
    cout << "\nThe first element is: " << v[0];
 
    // inserts at the beginning
    v.emplace(v.begin(), 5);
    cout << "\nThe first element is: " << v[0];
 
    // Inserts 20 at the end
    v.emplace_back(20);
    n = v.size();
    cout << "\nThe last element is: " << v[n - 1];
 
    // erases the vector
    v.clear();
    cout << "\nVector size after erase(): " << v.size();
 
    // two vector to perform swap
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
 
    cout << "\n\nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
 
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
 
    // Swaps v1 and v2
    v1.swap(v2);
 
    cout << "\nAfter Swap \nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
 
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
*/

/*
Output :
The vector elements are: 10 10 10 10 10 
The last element is: 15
The vector elements are: 10 10 10 10 10 
The first element is: 5
The first element is: 10
The first element is: 5
The last element is: 20
Vector size after erase(): 0

Vector 1: 1 2 
Vector 2: 3 4 
After Swap 
Vector 1: 3 4 
Vector 2: 1 2
*/
    return 0 ;
}
