#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-median-from-data-stream/
*/

class MedianFinder {
public:
    priority_queue<int> left ;
    priority_queue<int, vector<int>, greater<int>> right ;
    MedianFinder() {
        
    }   
    void addNum(int num) {
        if(left.empty()){
            left.push(num) ;
            return ;
        }   

        if(left.size() > right.size()){
            if(left.top() > num){
                right.push(left.top()) ;
                left.pop() ;
                left.push(num) ;
            }
            else{
                right.push(num) ;
            }
        }
        else{
            if(num > right.top()){
                left.push(right.top()) ;
                right.pop() ;
                right.push(num) ;
            }
            else{
                left.push(num) ;
            }
        }
    }
    
    double findMedian() {
        double ans ;
        double two = 2.0 ;
        if(left.size() == right.size()){
            ans = (left.top() + right.top())/two;
        }
        else if(left.size() > right.size()){
            ans = left.top() ;
        }   
        else{
            ans = right.top() ;
        }
        return ans ; 
    }
};

/*
this can be used to calculate the median if you are continously being given data 

so the approach is that we are maintaining two heaps left and right also 
left will have all the elements less than or equal to all the elements in the right that is maximum element in the left is <= min element in the
right 

left will be a greater heap and right will be a min heap 
we always add the elements in the heap in such a way that difference between the sizes of both these heaps is at max 1 

so if left is empty we add num to it if not if left size is more if in case the number which we are adding is smaller than the top element 
in the left so what we do is that remove the top element in the left add it to the right one and add the new element to left 
if not just add the new element to right see here even though num == left.top() we are adding it to right because difference between sizes should be at
max 1, so if right size is more if so the element being added is more than the right top we add the right top element to left and
pop it and add this number to right or else just add this number to left as to make sizes equal 

so now if one of the heaps size is more in the sense we are having odd number of elements so return the top value of that heap whose 
size is more,  if sizes are equal in the sense even number of elements then return the avg of top of both
*/