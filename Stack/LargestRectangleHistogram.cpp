/**
 * Title     : Largest Rectangle in Histogram
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int height[], int n) {

    // To store indexes of the height array
    // The indexes are stored in ascending order of their heights
    stack<int> S;

    int tempTop = -1, maxArea = 0, currArea = 0, i = 0;

    while (i < n) {

        // If stack is empty or current height is equal or higher than the height at stack top index,
        // push current height index into the stack.
        if (S.empty() || height[i] >= height[S.top()])
            S.push(i++);

        // If the current height is smaller than the height at stack top index,
        // calculate area with respect to the height at stack top index and pop the index
        // Continue this process until a height is found which is smaller than or equals current height,
        // if no such height is there, then we reach empty stack and push the current height index.
        else {
            tempTop = S.top();
            S.pop();

            currArea = height[tempTop] * (S.empty() ? i : (i - S.top() - 1));

            if (currArea > maxArea)
                maxArea = currArea;
        }
    }

    // If stack is not empty then calculate area w.r.t. each of the height indexes in the stack and pop.
    while (!S.empty()) {
        tempTop = S.top();
        S.pop();

        currArea = height[tempTop] * (S.empty() ? i : i - S.top() - 1);

        if (currArea > maxArea)
            maxArea = currArea;
    }

    // Return the maximum rectangular area in histogram
    return maxArea;

}

int main() {
    int n;
    cout << "Enter the number of bars in the histogram : ";
    cin >> n;
    int arr[n];
    cout << "Enter the height of " << n << " bars : ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Largest rectangular area = " << getMaxArea(arr, n) << '\n';
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
