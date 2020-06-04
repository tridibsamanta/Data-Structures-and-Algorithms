/**
 * Title     : Height of a N-ary Tree
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

int findHeight(int parent[], int n) {

    int maxHeight = INT_MIN;

    for (int i = 0; i < n; ++i) {

        int currHeight = 0, j = i;

        while(parent[j] != -1) {
            ++currHeight;
            j = parent[j];
        }

        maxHeight = max(maxHeight, currHeight);
    }

    return maxHeight;
}

int main() {

    // Given a parent array, where parent[i] indicates the parent of i-th node in the tree
    // Assume, parent of root node is indicate with -1

    int parent[] = {-1, 0, 1, 6, 6, 0, 0, 2 ,7};
    int n = sizeof(parent) / sizeof(parent[0]);

    int height = findHeight(parent, n);
    cout << "Height of the N-ary tree is : " << height << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n^2)
 ~ Space Complexity  : O(1)
*/
