/**
 * Title     : Inversion count in an array
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 5;

int n; // n <= 200000
long long arr[MAXN];
int bit[MAXN];

void compress() {
    map<long long, int> mp;

    for (int i = 1; i <= n; ++i) {
        mp[arr[i]];
    }

    int idx = 1;

    for (auto& pr : mp) {
        pr.second = idx++;
    }

    for (int i = 1; i <= n; ++i) {
        arr[i] = mp[arr[i]];
    }
}

void update(int i, int val) {
    for (; i < MAXN; i += (i & -i)) {
        bit[i] += val;
    }
}

int query(int i) {
    int ans = 0;
    for (; i > 0; i -= (i & -i)) {
        ans += bit[i];
    }
    return ans;
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    // index compression to handle cases such as:
    // 1. arr[i] is negative
    // 2. arr[i] > 1e6 (insufficient memory for bit[])
    compress();

    int inversionCount = 0;

    for (int i = 1; i <= n; ++i) {
        inversionCount += query(MAXN) - query(arr[i]);
        update(arr[i], 1);
    }

    cout << inversionCount << '\n';

    return 0;
}

/*
 ~ Time Complexity: O(n * log n)
 ~ Auxiliary Space: O(MAXN)
*/
