/**
 * Title     : Spirally traverse a matrix
 * Author    : Tridib Samanta
 **/

#include<iostream>
using namespace std;

int main()
 {
    int m, n;
    cout << "Enter the number of rows : ";
    cin >> m;
    cout << "Enter the number of columns : ";
    cin >> n;

    cout << "Enter " << (m * n) << " elements : ";
    int arr[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j ) {
            cin >> arr[i][j];
        }
    }

    cout << "Matrix in spiral order : ";

    int k = 0; // starting row index
    int l = 0; // starting column index

    while (k < m &&  l < n) {

        // Print the topmost row from left to right
        for (int i = l; i < n; ++i)
            cout << arr[k][i] << ' ';
        // Topmost row printing done, so increment the row index
        ++k;

        // Print the rightmost column from top to bottom
        for (int i = k; i < m; ++i)
            cout << arr[i][n - 1] << ' ';
        // Rightmost column printing done, so decrement the column index
        --n;

        // Check for remaining rows
        if (k < m) {

            // Print the bottom row from right to left
            for (int i = n - 1; i >= l; --i)
                cout << arr[m - 1][i] << ' ';
            // Bottom row printing done, so decrement the row index
            --m;

        }

        // Check for remamining columns
        if (l < n) {

            // Print the leftmost column from bottom to top
            for (int i = m - 1; i >= k; --i)
                cout << arr[i][l] << ' ';
            // Leftmost column printing done, so increment the column index
            ++l;

        }

    }

    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(m*n)
 ~ Space Complexity  : O(1)
*/
