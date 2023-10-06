#include<bits/stdc++.h>
using namespace std ;


/*
We can see that nums[mid] this belongs to either left array or right array so if nums[mid] >= nums[l] then it belongs to the left sub array
which is sorted in increasing order so our minimum value will be in the right array 

nums[l] < nums[r] can never be the case as just take an example and watch as array is roated in an order nums[l] > nums[r] due to the rotation just 
check for any roattion it works if not nums[l] can be minimum and we are done return the minimum value 
in the loop we are checking the mid value if it is minimum or not.
l<= r for only one single element 
*/
class Solution{
public:
    int findMin(vector<int> &nums){
        int res = INT_MAX ;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r){
            if (nums[l] < nums[r]){
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);
            if (nums[mid] >= nums[l]){  // mid present in left sorted array
                l = mid + 1; // try to move closer to right sorted array
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }
};