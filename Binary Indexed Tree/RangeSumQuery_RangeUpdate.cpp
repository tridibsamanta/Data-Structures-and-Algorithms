/**
 * Title     : Range Sum Queries allowing range updates
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int arr[MAXN];
int bit1[MAXN], bit2[MAXN];

void update(bool flag, int i, int x) {
    for (; i <= n; i += (i & -i)) {
        (flag) ? bit2[i] += x : bit1[i] += x;
    }
}

void range_update(int l, int r, int x) {
    update(0, l, x);
    update(0, r + 1, -x);
    update(1, l, x * (l - 1));
    update(1, r + 1, -x * r);
}

int sum(bool flag, int i) {
    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += (flag) ? bit2[i] : bit1[i];
    return ans;
}

int prefix_sum(int i) {
    return sum(0, i) * i - sum(1, i);
}

int range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; ++i) {
        range_update(i, i, arr[i]);
    }

    int q;
    cin >> q;

    while (q--) {

        // Type 1: range_update(l, r, value) -> add value to arr[l..r]
        // Type 2: range_sum(l, r) -> sum of elements from arr[l..r];

        int type;
        cin >> type;

        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;

             range_update(l, r, val);
        }
        else if (type == 2) {
            int l, r;
            cin >> l >> r;

            cout << range_sum(l, r) << '\n';
        }
    }

    return 0;
}

/*
 ~ Time Complexity:
   range_update() -> O(log n)
   range_sum()  -> O(log n)
 ~ Space Complexity: O(n)
*/
