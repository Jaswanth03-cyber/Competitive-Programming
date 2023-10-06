#include <bits/stdc++.h>
using namespace std ;

/*

Assume a1 ⊕ a2 ⊕ a3 ⊕ . . . ⊕ an = a and a1 ⊕ a2 ⊕ a3 ⊕ . . . ⊕ an-1 = b
Then a ⊕ b = an

*/

int getMissingNo(int a[], int n)
{
    // For xor of all the elements in array
    int x1 = a[0];
 
    // For xor of all the elements from 1 to n+1
    int x2 = 1;
 
    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];
 
    for (int i = 2; i <= n + 1; i++) // as n+1 numbers are there here n+1 = 5 n is 4 number of elements in the array
        x2 = x2 ^ i;
 
    return (x1 ^ x2);
}

int main(){
    int arr[] = { 1, 2, 3, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    int miss = getMissingNo(arr, N); 
    cout << miss;
    return 0;
}