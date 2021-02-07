/**
 * Title     : Building Bridges (Longest Increasing Subsequence Variation)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

/***** Approach 1 (Sort + DP) *****/
/*
int maxBridges(vector<vector<int> >& cities) {

	int n = cities.size();

	if (n <= 1)
		return n;

	sort(cities.begin(), cities.end());

	vector<int> dp(n, 1);

	int maxCnt = 1;

	for (int i = 1; i < n; ++i) {

		for (int j = 0; j < i; ++j) {

			if (cities[i][1] > cities[j][1] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}

		maxCnt = max(maxCnt, dp[i]);
	}

	return maxCnt;
}
*/

/***** Approach 2 (Sort + Binary Search + DP) *****/

int maxBridges(vector<vector<int> >& cities) {

	int n = cities.size();

	if (n <= 1)
		return n;

	sort(cities.begin(), cities.end());

	vector<int> dp;
	dp.emplace_back(cities[0][1]);

	for (int i = 1; i < n; ++i) {

		auto itr = lower_bound(dp.begin(), dp.end(), cities[i][1]);

		if (itr == dp.end())
			dp.emplace_back(cities[i][1]);
		else
			*itr = cities[i][1];
	}

	return dp.size();
}

int main() {

    vector<vector<int> > cities{{5, 6}, {3, 4}, {10, 1}};

    cout << "Maximum number of bridges = " << maxBridges(cities);

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(n^2)
 ~ Space Complexity : O(n)

 ***** Approach 2 *****
 ~ Time Complexity  : O(nlogn)
 ~ Space Complexity : O(n)
*/
