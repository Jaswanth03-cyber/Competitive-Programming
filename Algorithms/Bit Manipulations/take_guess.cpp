#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1556/problem/D
*/
/*
In fact, we can figure out the sum of two numbers using just their AND, OR and XOR values! Suppose we know their
XOR values, we can use the following property:

a + b = 2.(a & b) + a xor b

The proof is as follows:

a xor b is essentially just a + b in base 2 but we never carry over to the next bit. Recall a bit in a xor b is 1 only if the bit in a is different from the bit in b, thus one of them must be a 1. However, when we add two 1 bits, we yield a 0, but we do not carry that 1 to the next bit. This is where a & b comes in.

a & b is just the carry bits themselves, since a bit is 1 only if it's a 1 in both a and b, which is exactly what we need. We multiply this by 2 to shift all the bits to the left by one, so every value carries over to the next bit.

To acquire the XOR values of the two numbers, we can use the following:

a xor b = ~(a & b) & (a | b)

The proof is as follows:

Recall a bit in a xor b is 1 only if the bit in a is different from the bit in b. By negating a & b, the bits that are left on are in the following format:

If it's 1 in a and 0 in b
If it's 0 in a and 1 in b
If it's 0 in a and 0 in b
*/
int ask(string s, int a, int b) {
	cout << s << ' ' << a << ' ' << b << endl;
	int res;
	cin >> res;
	return res;
}

/** @return the sum of the elements at a and b (0-indexed) */
int sum(int a, int b) {
	int and_ = ask("and", ++a, ++b);
	int or_ = ask("or", a, b);

	int xor_ = ~and_ & or_;  // a ^ b = ~(a & b) & (a | b)

	return 2 * and_ + xor_;  // a + b = 2(a & b) + a ^ b
}

int main() {
	int n, k;
	cin >> n >> k;

	// Acquire the first 3 elements
	int a_plus_b = sum(0, 1);
	int a_plus_c = sum(0, 2);
	int b_plus_c = sum(1, 2);

	// Get the actual values by solving the equations
	vector<int> arr{(a_plus_b + a_plus_c - b_plus_c) / 2};
	arr.push_back(a_plus_b - arr[0]);
	arr.push_back(a_plus_c - arr[0]);

	// Get the rest of the array
	for (int i = 3; i < n; i++) { arr.push_back(sum(i - 1, i) - arr.back()); }

	sort(arr.begin(), arr.end());
	cout << "finish " << arr[k - 1] << endl;
}