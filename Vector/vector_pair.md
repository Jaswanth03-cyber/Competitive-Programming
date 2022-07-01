# Pair in Vectors

Vector of Pairs is a dynamic array filled with pairs instead of any primitive data type. Vector of pairs are no different from vectors when it comes to declaration and accessing the pairs.

Many of the  functions associated with the pair vector are same as that of vectors just we have two elements so accessing the elements will be different and the functions are as follows :

## Iterators:

1. [begin()](https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/) – Returns an iterator pointing to the first element in the vector
2. [end()](https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/) – Returns an iterator pointing to the theoretical element that follows the last element in the vector
3. [rbegin()](https://www.geeksforgeeks.org/vector-rbegin-and-rend-function-in-c-stl/) – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
4. [rend()](https://www.geeksforgeeks.org/vector-rbegin-and-rend-function-in-c-stl/) – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
5. [cbegin()](https://www.geeksforgeeks.org/vector-cbegin-vector-cend-c-stl/) – Returns a constant iterator pointing to the first element in the vector.
6. [cend()](https://www.geeksforgeeks.org/vector-cbegin-vector-cend-c-stl/) – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
7. [crbegin()](https://www.geeksforgeeks.org/vectorcrend-vectorcrbegin-examples/) – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
8. [crend()](https://www.geeksforgeeks.org/vectorcrend-vectorcrbegin-examples/) – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

## Capacity:

1. [size()](https://www.geeksforgeeks.org/vectorempty-vectorsize-c-stl/) – Returns the number of elements in the vector.
2. [max_size()](https://www.geeksforgeeks.org/vector-max_size-function-in-c-stl/) – Returns the maximum number of elements that the vector can hold.
3. [capacity()](https://www.geeksforgeeks.org/vector-capacity-function-in-c-stl/) – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
4. [resize(n)](https://www.geeksforgeeks.org/vector-resize-c-stl/) – Resizes the container so that it contains ‘n’ elements.
5. [empty()](https://www.geeksforgeeks.org/vectorempty-vectorsize-c-stl/) – Returns whether the container is empty.
6. [shrink_to_fit()](https://www.geeksforgeeks.org/vector-shrink_to_fit-function-in-c-stl/) – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
7. [reserve()](https://www.geeksforgeeks.org/using-stdvectorreserve-whenever-possible/) – Requests that the vector capacity be at least enough to contain n elements.

## Element access:
In the pair we access the element by first and second, u can see the code down how we access the element

1. [referenceoperator](https://www.geeksforgeeks.org/vectoroperator-vectoroperator-c-stl/) – Returns a reference to the element at position ‘g’ in the vector
2. [at(g)](https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/) – Returns a reference to the element at position ‘g’ in the vector
3. [front()](https://www.geeksforgeeks.org/vectorfront-vectorback-c-stl/) – Returns a reference to the first element in the vector
4. [back()](https://www.geeksforgeeks.org/vectorfront-vectorback-c-stl/) – Returns a reference to the last element in the vector
5. [data()](https://www.geeksforgeeks.org/vector-data-function-in-c-stl/) – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

## Modifiers: 

1. [assign()](https://www.geeksforgeeks.org/vector-assign-in-c-stl/) – It assigns new value to the vector elements by replacing old ones
2. [push_back()](https://iq.opengenus.org/vector-of-pairs-in-cpp/) – It push the elements into a vector from the back
3. [pop_back()](https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/) – It is used to pop or remove elements from a vector from the back.
4. [insert()](https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/) – It inserts new elements before the element at the specified position
5. [erase()](https://www.geeksforgeeks.org/vectorclear-vectorerase-c-stl/) – It is used to remove elements from a container from the specified position or range.
6. [swap()](https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/) – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
7. [clear()](https://www.geeksforgeeks.org/vectorclear-vectorerase-c-stl/) – It is used to remove all the elements of the vector container
8. [emplace()](https://www.geeksforgeeks.org/vector-emplace-function-in-c-stl/) – It extends the container by inserting new element at position
9. [emplace_back()](https://www.geeksforgeeks.org/vectoremplace_back-c-stl/) – It is used to insert a new element into the vector container, the new element is added to the end of the  vector

## Code 

```c++
#include<iostream>
#include<vector>
using namespace std ;
int main(){
    vector<pair<int, int>> v ;
    v.push_back(make_pair(1,2)) ;
    v.push_back(make_pair(3,4)) ;
    v.push_back(make_pair(5,6)) ;
    v.push_back(make_pair(7,8)) ;
    v.push_back(make_pair(9,10)) ;
    v.push_back(make_pair(11,12)) ;
    v.push_back(make_pair(13,14)) ;
    v.push_back(make_pair(15,16)) ;
    

    v.emplace_back(17,18) ;      // we can even use this also over here 


    /*for(auto i = v.begin(); i != v.end() ; i++){
        cout<<*i.first<<endl ;
    }*/

    /*
    we can use almost same fuctions as before but now bit updated differently we can access the elements in the following way 
    rest all are same as vectors itself .
    */

    for(auto i = v.begin(); i != v.end() ; i++){
        cout<<i->first<<endl ;
    }

    for(auto i = v.begin(); i != v.end() ; i++){
        cout<<i->second<<endl ;
    }

    cout<<v.size()<<endl ;

    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl ;
    }

    auto j = v.begin() ;
    v.erase(j + 4) ; //deleting vector at position 4

    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl ;
    }

    v.pop_back() ; // removing the last element 

    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl ;
    }


    int a = v.front().first ;
    cout<<a<<endl ;
    cout<<v.front().second<<endl ;      // simillarly for back 

    
    return 0 ;
}
```

## Output 

```
1
3
5
7
9
11
13
15
17
2
4
6
8
10
12
14
16
18
9
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
17 18
1 2
3 4
5 6
7 8
11 12
13 14
15 16
17 18
1 2
3 4
5 6
7 8
11 12
13 14
15 16
1
2
```




