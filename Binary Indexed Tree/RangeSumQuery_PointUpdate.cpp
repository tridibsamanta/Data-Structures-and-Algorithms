/**
 * Title     : Range Sum Queries allowing point updates
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int arr[MAXN];
int bit[MAXN];

void update(int i, int x) {
    for (; i <= n; i += (i & -i)) {
        bit[i] += x;
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

    // 1-indexed for ease of implementation
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    // build the bit array (1-indexed) - O(n * log n)
    for (int i = 1; i <= n; ++i) {
        update(i, arr[i]);
    }

    int q;
    cin >> q;

    while (q--) {

        // Type 1: update(index, value) -> replace arr[index] with value
        // Type 2: query(l, r) -> sum of elements from arr[l..r];

        int type;
        cin >> type;

        if (type == 1) {
            int index, val;
            cin >> index >> val;

            update(index, val - arr[index]);
            arr[index] = val;
        }
        else if (type == 2) {
            int l, r;
            cin >> l >> r;

            // sum(l..r) = sum(r) - sum(l - 1)
            cout << query(r) - query(l - 1) << '\n';
        }
    }

    return 0;
}

/*
 ~ Time Complexity:
   update() -> O(log n)
   query()  -> O(log n)
 ~ Space Complexity: O(n)
*/
