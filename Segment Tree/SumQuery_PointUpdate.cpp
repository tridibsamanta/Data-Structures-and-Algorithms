/**
 * Title     : Answer sum queries allowing point update
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN];
int seg[4 * MAXN];

void build(int idx, int l, int r) {

    if (l == r) {
        seg[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

void update(int idx, int curr_l, int curr_r, int target_idx, int value) {

    // reached the target element (leaf node)
    if (curr_l == curr_r) {
        arr[target_idx] += value;
        seg[idx] += value;
    }
    else {
        int mid = (curr_l + curr_r) / 2;

        // target element lies in the left subtree
        if (target_idx >= curr_l && target_idx <= mid)
            update(2 * idx, curr_l, mid, target_idx, value);
        else // target element lies in the right subtree
            update(2 * idx + 1, mid + 1, curr_r, target_idx, value);

        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
}

int query(int idx, int curr_l, int curr_r, int l, int r) {

    // no overlap
    if (curr_l > r || curr_r < l)
        return 0;

    // complete overlap
    if (curr_l >= l && curr_r <= r)
        return seg[idx];

    // partial overlap
    int mid = (curr_l + curr_r) / 2;

    int left = query(2 * idx, curr_l, mid, l, r);
    int right = query(2 * idx + 1, mid + 1, curr_r, l, r);

    return left + right;
}

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    build(1, 1, n);

    int q;
    cin >> q;

    while (q--) {

        // type = 1 -> update the element at target index by adding some value to it
        // type = 2 -> query for the sum of the elements in the range [l, r]
        int type;
        cin >> type;

        if (type == 1) {
            int target_idx, value;
            cin >> target_idx >> value;

            update(1, 1, n, target_idx, value);
        }
        else if (type == 2) {
            int l, r;
            cin >> l >> r;

            cout << query(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}

/*
 ~ Time Complexity:
   build()  -> O(n)
   update() -> O(log n)
   query()  -> O(log n)
 ~ Space Complexity: O(4*n)
*/
