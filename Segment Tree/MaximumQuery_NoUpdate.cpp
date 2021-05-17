/**
 * Title     : Answer Maximum queries (Find the maximum of all elements in a given range)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN];
int seg[4 * MAXN];

/* Construct the Segment Tree */
void build(int idx, int l, int r) {

    // current range has a single element (leaf node)
    if (l == r) {
        seg[idx] = arr[l];
        return;
    }

    // current range has two or more elements, hence divide into half and recur
    int mid = (l + r) / 2;

    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    // any node (except leaf) contains the maximum between its left and right child
    seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
}

/* Find maximum of all elements in the range [l, r] */
int query(int idx, int curr_l, int curr_r, int l, int r) {

    // no overlap
    if (curr_l > r || curr_r < l)
        return INT_MIN;

    // complete overlap
    if (curr_l >= l && curr_r <= r)
        return seg[idx];

    // partial overlap
    int mid = (curr_l + curr_r) / 2;

    int left = query(2 * idx, curr_l, mid, l, r);
    int right = query(2 * idx + 1, mid + 1, curr_r, l, r);

    return max(left, right);
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

        int l, r;
        cin >> l >> r;

        cout << query(1, 1, n, l, r) << '\n';
    }

    return 0;
}

/*
 ~ Time Complexity:
   build() -> O(n)
   query() -> O(log n)
 ~ Space Complexity: O(4*n)
*/
