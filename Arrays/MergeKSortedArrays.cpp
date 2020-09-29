/**
 * Title     : Merge k sorted arrays
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int> > arr) {

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > minHeap;

    // Each element of the min heap has 3 elements as follows:
    // integer 1 contains the element itself
    // integer 2 contains the element's array index
    // integer 3 contains the element's index in the array

    for (int i = 0; i < arr.size(); i++){
        if (arr[i].size() != 0)
            minHeap.push({arr[i][0], {i, 0}});
    }

    if (minHeap.empty())
        return vector<int> {};

    vector<int> res;

    while (!minHeap.empty()) {

        pair<int, pair<int, int> > curr = minHeap.top();
        minHeap.pop();

        res.emplace_back(curr.first);

        int arrayIdx = curr.second.first;
        int elementIdx = curr.second.second;

        if (++elementIdx < arr[arrayIdx].size())
            minHeap.push({arr[arrayIdx][elementIdx], {arrayIdx, elementIdx}});
    }

    return res;
}

int main() {

    vector<vector<int> > arr {{1, 4, 5, 6},
                              {1, 3, 4},
                              {2, 6}};

    vector<int> res = mergeKSortedArrays(arr);

    cout << "Merged array is: ";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ' ';
    }

    return 0;
}

/*
 ~ Time Complexity  : O(Nlogk)
 ~ Space Complexity : O(k)

   where, N - total number of elements
          k - total number of sorted arrays
*/
