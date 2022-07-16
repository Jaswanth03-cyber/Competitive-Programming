/*
Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of 
platforms required for the railway station so that no train waits. We are given two arrays that represent the arrival and 
departure times of trains that stop.

brute force:
The idea is to take every interval one by one and find the number of intervals that overlap with it. Keep track of the 
maximum number of intervals that overlap with an interval. Finally, return the maximum value.



Greedy Approach:

Store the arrival time and departure time in array arr and sort this array based on arrival time
Declare a priority queue(min-heap) and store the departure time of the first train and also declare a counter cnt and initialize
it with 1.
Iterate over arr from 1 to n-1 
1. check if the arrival time of current train is less than or equals to the departure time of previous train which is kept
on top of the priority queue
2. If true, then push the new departure time and increment the counter cnt
   otherwise, we pop() the departure time
3. push new departure time in the priority queue


basically we are having the arrival times sorted, so now if the arrival time of the new train is less than the departure time of 
the previous one we need another platform and now push the departure time of the arriving train into the heap, so when u push
into the heap, heap gets heapified and and the top element will be the minimum of all the elements, we do this as if the new 
arrival train time is less than this then its less than all other ones in the priority queue and finally have to increase the 
platforms_required count by 1

if newly arrived train time is not less than the departure time of the previous train then after the previous train goes this
train can come, so we pop out the departure time of the before train and add the departure time of newly arriving train as
anyway before train will departure so no overlaps for next arriving trains we have to check according to this trains departure time
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std ;

int naive(int arr[], int dep[], int n){

    int count_iteration, platforms_needed = 1;

    for(int i = 1 ; i < n ; i++){

        count_iteration = 1 ;         // we are seeing for one iteration how many overlaps

        for(int j = i +1 ; j < n ; j++){
            if(max(arr[i], arr[j]) <= min(dep[i], dep[j])){            // if we see this is the overlap condition 
                count_iteration++ ;
            }
        }

        platforms_needed = max(platforms_needed, count_iteration) ;     // finding the maximum one as we need that many platforms 

    }
    return platforms_needed ;
}


int greedy(int arr[], int dep[], int n){

    vector<pair<int, int>> train_times ;  // see if we determine size and push_back then n + no of push backs is the size

    // that is train-times(n) now pushing back total size is n + no of push_backs no n 

/*
we have to assign the pair values this way
    vector<pair<int, int>> p(n) ;
    for(int i = 0 ; i < n ; i++){
        p[i] = {arr[i], dep[i]} ;
    }
*/

    int plat_needed = 1 ;

    for(int i = 0 ; i < n ; i++){
        train_times.push_back(make_pair(arr[i], dep[i])) ;
    }
    train_times.resize(n) ;

    sort(train_times.begin(), train_times.end()) ;  // by default it is sorted with first element if u want with second then sortbysec()

    priority_queue<int, vector<int>, greater<int>> p ; // by deafult it is max heap

    p.push(train_times[0].second) ;              // anyway in queues elements are added from the back no need to explicitly write push_back()

    for(int i = 1 ; i < n ; i++){
        if(train_times[i].first <= p.top()){
            plat_needed++ ;
        }
        else{
            p.pop() ;
        }
        p.push(train_times[i].second) ;
    }
    return plat_needed ;

}
/*
first I wrote train-times(n) and then pushed back n elements size is 2n and first elements are all 0 so as 
in the further codes it satisfied the condition that newly arrival train time is less than or equal to old train
departure time is all 0's all are equal so platneeded became 6 as size(n) is 6.
*/
int main(){
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Using naive approach, minimum, number of platforms needed are as shown : "<<naive(arr, dep, n)<<endl ;
    cout <<"Using greedy approach minimum number of platforms needed are as shown : "<<greedy(arr, dep, n)<<endl;
    return 0;
}

