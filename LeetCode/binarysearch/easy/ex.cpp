#include <bits/stdc++.h>
using namespace std ;


bool check(vector<int>& x, int k, int mid) {
    int n = x.size() ;
    int count = 1;
    int lastPosition = x[0];
    for (int i = 1; i < n; ++i) {
        if (x[i] - lastPosition >= mid) {
            count++;
            lastPosition = x[i];
        }
    }
    return count >= k;
}

int maxmizeMinimumnDistance(vector<int> &x, int k) {
    sort(x.begin(), x.end());
    int n = x.size() ;
    int low = 0;
    int high = x[n - 1] - x[0];
    int result = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(x, k, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

/*
given a set of n distinct points on the x-axis, choose k of them such that  the minimum distance between any two chosen points is as large as possible
find the maximum possible minimum distance 
*/


