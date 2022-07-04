# STL Library

The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized. A working knowledge of template classes is a prerequisite for working with STL.

STL has four components 
1. Algorithms 
2. Containers 
3. Iterators
4. Functions

First we will look about the Containers, then about the algoritms next followed by functions.

## Containers

### Vectors

Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. To use this we need to insert this library "#include<vector>" in our code file. Some of the functions of the vector are as shown below 

1. .begin()     Returns an iterator pointing to the first element in the vector
2. .end()       Returns an iterator pointing to the theoretical element that follows the last element in the vector
3. .rbegin()    Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
4. .rend()       Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)   
5. .size()      Returns the number of elements in the vector.
6. .empty()     Returns whether the container is empty.     
7. .capacity()  Returns the size of the storage space currently allocated to the vector expressed as number of elements.
8. .max_size()   Returns the maximum number of elements that the vector can hold.
9. .push_back(m)    It push the elements into a vector from the back
10. .pop_back()     It is used to pop or remove elements from a vector from the back.
11. .front()      Returns a reference to the first element in the vector
12. .back()     Returns a reference to the last element in the vector
13. .data()     Returns a direct pointer to the memory array used internally by the vector to store its owned elements(pointer to the array, using which we can access the elements)
14. [i]([] operator) Returns a reference to the element at position ‘g’ in the vector(we can access element by v[i])
15. .at(i)  Returns a reference to the element at position ‘g’ in the vector
16. .insert(iterator, value)   It inserts new elements before the element at the specified position, here parameters are position as iterator and the value to be inserted 
17. .emplace_back(m)     It is used to insert a new element into the vector container, the new element is added to the end of the vector
18. .erase(iterator)    it is used to remove elements from a container from the specified position or range, clear() used to completely empty the vector


Time taken by the operations here, for inserting or deleting from the back its constant time(O(1)), for resizing it is O(N), for inserting at a particular position it is O(N).

### List 

Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, the list has slow traversal, but once a position has been found, insertion and deletion are quick. Normally, when we say a List, we talk about a doubly linked list. For implementing a singly linked list, we use a forward list. To use this we need to insert this library "#include<list>" in our code file. Some of the functions of the vector are as shown below 

1. .begin()     Returns an iterator pointing to the first element in the vector
2. .end()       Returns an iterator pointing to the theoretical element that follows the last element in the vector
3. .rbegin()    Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
4. .rend()       Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)   
5. .size()      Returns the number of elements in the vector.
6. .empty()     Returns whether the container is empty.     
7. .capacity()  Returns the size of the storage space currently allocated to the vector expressed as number of elements.
8. .max_size()   Returns the maximum number of elements that the vector can hold.
9. .push_back(m)    It push the elements into a vector from the back
10. .pop_back()     It is used to pop or remove elements from a vector from the back.
11. .front()      Returns a reference to the first element in the vector
12. .back()     Returns a reference to the last element in the vector
13. .reverse()     Reverses the list
14. .push_front(m)  Adds a new element ‘g’ at the beginning of the list.
15. .pop_back()     Removes the last element of the list, and reduces size of the list by 1.
16. .insert(iterator, value)   It inserts new elements before the element at the specified position, here parameters are position as iterator and the value to be inserted 
17. .emplace_back(m)     It is used to insert a new element into the vector container, the new element is added to the end of the vector
18. .erase(iterator)    it is used to remove elements from a container from the specified position or range. 
19. .sort() This is used to sort the list in ascending order
20. .remove(m)  Removes all the occurences of m

Here difference between vectors and list is that we can not access the list elements using .at(i) or list[i] operations instead for that we can do the following and in this program only we will see some iterator magics 

```c++
#include<iostream>
#include<list>
using namespace std 
void print(list<int> l){
    list<int> z = l ;                // this we do because as we pop original list will be effected
    while(!z.empty()){
        cout<<v.front()<<" " ;
        v.pop_front() ;
    }
}
int main(){
    list<int> v ;
    v.push_back(2) ;
    v.push_back(3) ;
    v.push_back(4) ;
    v.push_back(5) ;
    /*
    One of the way in which we can access the elements is 
    */
    for(auto it = v.begin() ; it != v.end() ; it++){
        cout<<*it<<endl ;
    }
    auto it = v.begin()  ; // we can even use list<int>:: iterator it = v.begin()
    /*
    Here incase of lists unlike vectors we can only do it++ but not it = it + 2 as not contigous memory but anyway as in
    linked list next node is connected to the previous one so it++ works, we can not repeat it++ 5 times if we want
    it = it + 5, so instead of that we have the following function advance(it,position_required)
    */
    advance(it, 2) ;
    v.insert(it , 1) ;
    // v.reverse() ;
    for(auto it = v.begin() ; it != v.end() ; it++){
        cout<<*it<<" " ;
    }
    cout<<endl ;
    return 0 ;
}
```

Time taken by the operations over here are as follows inserting/removing from back takes constant time but from front it takes 
O(N), sorting takes O(NlogN), reversing takes O(N) time 

### Deque

Double-ended queues are sequence containers with the feature of expansion and contraction on both ends. They are similar to vectors, but are more efficient in case of insertion and deletion of elements. Unlike vectors, contiguous storage allocation may not be guaranteed. To use this we need to insert this library "#include<deque>" in our code file. Some of the functions of the vector are as shown below, anyway here most of the functions are similar to vectors.

1. .begin()     Returns an iterator pointing to the first element in the deque
2. .end()       Returns an iterator pointing to the theoretical element that follows the last element in the deque
3. .rbegin()    Returns a reverse iterator pointing to the last element in the deque (reverse beginning). It moves from last to first element
4. .rend()       Returns a reverse iterator pointing to the theoretical element preceding the first element in the deque (considered as reverse end)   
5. .size()      Returns the number of elements in the deque .
6. .empty()     Returns whether the container is empty.     
7. .capacity()  Returns the size of the storage space currently allocated to the deque expressed as number of elements.
8. .max_size()   Returns the maximum number of elements that the deque can hold.
9. .push_back(m)    It push the elements into a deque from the back
10. .pop_back()     It is used to pop or remove elements from a deque from the back.
11. .front()      Returns a reference to the first element in the deque
12. .back()     Returns a reference to the last element in the deque
13. .data()     Returns a direct pointer to the memory array used internally by the deque to store its owned elements(pointer to the array, using which we can access the elements)
14. [i]([] operator) Returns a reference to the element at position ‘g’ in the deque(we can access element by v[i])
15. .at(i)  Returns a reference to the element at position ‘g’ in the deque
16. .insert(iterator, value)   It inserts new elements before the element at the specified position, here parameters are position as iterator and the value to be inserted 
17. .emplace_back(m)     It is used to insert a new element into the vector container, the new element is added to the end of the deque
18. .erase(iterator)    it is used to remove elements from a container from the specified position or range, clear() used to completely empty the deque



Time taken by the operations here, Accessing Elements- O(1), Insertion or removal of elements- O(N), Insertion or removal of elements at start or end- O(1)

### Queue

Queues are a type of container adaptors that operate in a first in first out (FIFO) type of arrangement. Elements are inserted at the back (end) and are deleted from the front. Queues use an encapsulated object of deque or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements. To use this we need to insert this library "#include<queue>" in our code file. Some of the functions of the vector are as shown below


1. .size()      Returns the number of elements in the vector.
2. .empty()     Returns whether the container is empty.     
3. .push(m)    It push the elements into a vector from the back
4. .front()      	Returns a reference to the first element of the queue.
5. .back()     Returns a reference to the last element in the queue.
6. .pop()     Deletes the first element of the queue. 
7. .emplace(m)     It is used to insert a new element into the vector container, the new element is added to the end of the queue

As here adding is done from the back and removing is done from the front as this is based on first in first out and the time taken for all the functions is constant time. 


### Priority_Queue

Priority queues are a type of container adapters, specifically designed such that the first element of the queue is either the greatest or the smallest of all elements in the queue and elements are in nonincreasing order (hence we can see that each element of the queue has a priority {fixed order}). However in C++ STL, by default, the top element is always the greatest element. We can also change it to the smallest element at the top. Priority queues are built on the top to the max heap and uses array or vector as an internal structure. To use this we need to insert this library "#include<queue>" in our code file. Some of the functions of the vector are as shown below


1. .size()      Returns the number of elements in the vector.
2. .empty()     Returns whether the container is empty.     
3. .push(m)    It push the elements into a vector from the back
4. .pop()     Deletes the top element of the queue. 
5. .emplace(m)     It is used to insert a new element into the vector container, the new element is added to the end of the queue
6. .top()   Returns a reference to the topmost element of the queue.
7. .value_type 	Represents the type of object stored as an element in a priority_queue. It acts as a synonym for the template parameter.

As said earlier by deafult STL uses max heap for the implementation for min heap, we can do ways as written below
1. Multiply the priority_queue defined by a negative value so that priority changes 
2. instead of defining priority_queue<int> q, we define this as, of course #include<vector> 
priority_queue<int , vector<int>, greater<int> >

Here also for accessing the elements we do like in the list we check whether the container is empty or not then print the top element and then pop it out, see above code written in lists section.

Here the time complexities are for inserting and removing the top element it is O(logN) as after inserting or removing there requires a heapify to maintain the priorities in the prescribed order(increasing/decreasing), for obtaining the top element it is constant time 

### Stack 

Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one end (top) and an element is removed from that end only.  Stack uses an encapsulated object of either vector or deque (by default) or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements. To use this we need to insert this library "#include<stack>" in our code file. Some of the functions of the vector are as shown below

1. empty() – Returns whether the stack is empty 
2. size() – Returns the size of the stack 
3. top() – Returns a reference to the top most element of the stack 
4. push(g) – Adds the element ‘g’ at the top of the stack
5. pop() – Deletes the top most element of the stack 

Here also for accessing the elements we do like in the list or priority_queue and the time complexities of all the operations is constant time as removing and adding is both done from the back. 

### Maps 

For learning about maps you can have a look over here (https://www.geeksforgeeks.org/mapat-mapswap-c-stl/)[Maps]


## Algorithms

Have a look over here (https://www.geeksforgeeks.org/the-c-standard-template-library-stl/#:~:text=The%20Standard%20Template%20Library%20(STL,classes%2C%20algorithms%2C%20and%20iterators.)(STL)



