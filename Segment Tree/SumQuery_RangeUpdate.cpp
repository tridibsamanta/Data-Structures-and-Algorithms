/**
 * Title     : Answer sum queries allowing range update using lazy propagation method
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN];
int seg[4 * MAXN];
int lazy[4 * MAXN];

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

void update(int idx, int curr_l, int curr_r, int l, int r, int value) {

	// If pending lazy updates present, then update current range (node) value
	if (lazy[idx] != 0) {
		seg[idx] += (curr_r - curr_l + 1) * lazy[idx];

		// current node has children, then propagate the current lazy update value
		if (curr_l != curr_r) {
			lazy[2 * idx] += lazy[idx];
			lazy[2 * idx + 1] += lazy[idx];
		}

		// we have completed the pending lazy updates for the current range (node)
		lazy[idx] = 0;
	}

	// current range (node) is completely outside target range
	if (curr_l > r || curr_r < l || curr_l > curr_r)
		return;

	// current range (node) is completely inside target range
	if (curr_l >= l && curr_r <= r) {

		// update current range (node)
		seg[idx] += (curr_r - curr_l + 1) * value;

		// current node has child, propagate the update value as pending lazy update
		if (curr_l != curr_r) {
			lazy[2 * idx] += value;
			lazy[2 * idx + 1] += value;
		}

		return;
	}

	// current range is partially inside target range
	int mid = (curr_l + curr_r) / 2;

	update(2 * idx, curr_l, mid, l, r, value);
	update(2 * idx + 1, mid + 1, curr_r, l, r, value);

	seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int query(int idx, int curr_l, int curr_r, int l, int r) {

	// current range is completely outside target range
	if (curr_l > r || curr_r < l || curr_l > curr_r)
		return 0;

	// If pending lazy updates present, then update current range (node) value
	if (lazy[idx] != 0) {
		seg[idx] += (curr_r - curr_l + 1) * lazy[idx];

        // current node has children, then propagate the current lazy update value
		if (curr_l != curr_r) {
			lazy[2 * idx] += lazy[idx];
			lazy[2 * idx + 1] += lazy[idx];
		}

        // we have completed the pending lazy updates for the current range (node)
		lazy[idx] = 0;
	}

	// current range is completely inside target range
	if (curr_l >= l && curr_r <= r)
		return seg[idx];

	// current range is partially inside target range
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

		int type;
		cin >> type;

        // type = 1 -> update every element in the range [l, r] by adding some value
		// type = 2 -> query for the sum of the elements in the range [l, r]

		if (type == 1) {
			int l, r, value;
			cin >> l >> r >> value;

			update(1, 1, n, l, r, value);
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
