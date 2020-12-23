/**
 * Title     : Find the Nth Catalan Number
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

// ***** Approach 1 (Recursive) *****
/*
ull catalan(int n) {

	if (n <= 1)
		return 1;

	ull res = 0;

	for (int i = 0; i < n; ++i) {
		res += catalan(i) * catalan(n - i - 1);
	}

	return res;
}
*/

ull dp[105];

// ***** Approach 2 (Top-Down) *****
/*
ull catalanUtil(int n) {

	if (n <= 1)
		return 1;

	if (dp[n] != -1)
		return dp[n];

	ull res = 0;

	for (int i = 0; i < n; ++i)
		res += catalanUtil(i) * catalanUtil(n - i - 1);

	return dp[n] = res;
}

ull catalan(int n) {
	fill(dp, dp + 105, -1);
	return catalanUtil(n);
}
*/

// ***** Approach 3 (Bottom-Up) *****

ull catalan(int n) {

	fill(dp, dp + 105, 0);

	dp[0] = dp[1] = 1;

	for (int i = 2; i < n + 1; ++i) {

		for (int j = 0; j < i; ++j) {

			dp[i] += dp[j] * dp[i - j - 1];
		}
	}

	return dp[n];
}


int main() {

	int n;
	cin >> n;

	ull res = catalan(n);
	cout << res << '\n';

	return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(n^2)
 ~ Space Complexity : O(n^2)

 ***** Approach 2 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)

 ***** Approach 3 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)
*/
