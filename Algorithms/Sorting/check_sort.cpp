// CPP implementation to Check if it is possible to sort an
// array with conditional swapping of elements at distance K
#include <bits/stdc++.h>
using namespace std;

// Function for finding if it possible
// to obtain sorted array or not

/*
https://www.geeksforgeeks.org/check-possible-sort-array-conditional-swapping-adjacent-allowed/
*/
/*
from every index i take i, i+k, i+2*k and sort these and replace at the positions of these from where these are taken of the sorted array
do this for index and see if it can be sorted or not. 
*/
bool fun(int arr[], int n, int k)
{
	vector<int> v;

	// Iterate over all elements until K
	for (int i = 0; i < k; i++) {
		// Store elements as multiples of K
		for (int j = i; j < n; j += k) {
			v.push_back(arr[j]);
		}

		// Sort the elements
		sort(v.begin(), v.end());

		int x = 0;

		// Put elements in their required position
		for (int j = i; j < n; j += k) {
			arr[j] = v[x];
			x++;
		}

		v.clear();
	}

	// Check if the array becomes sorted or not
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

// Driver code
int main()
{
	int arr[] = { 4, 2, 3, 7, 6 };

	int K = 2;

	int n = sizeof(arr) / sizeof(arr[0]);

	if (fun(arr, n, K))
		cout << "yes" << endl;

	else
		cout << "no" << endl;

	return 0;
}
