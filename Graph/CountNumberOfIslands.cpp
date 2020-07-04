/**
 * Title     : Count the Number of Islands
 * Author    : Tridib Samanta
**/

/*
    In a given 2D matrix, a group of connected 1's forms an island. For example -

    mat[][] = {{1, 1, 0, 0, 0},
               {0, 1, 0, 0, 1},
               {1, 0, 0, 1, 1},
               {0, 0, 0, 0, 0},
               {1, 0, 1, 0, 1}};

    Number of islands are = 5
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> mat[], int i, int j, vector<bool> visited[], int r, int c) {
    return (i >= 0) && (i < r) && (j >= 0) && (j < c) &&
            (mat[i][j] && !visited[i][j]);
}

void dfs(vector<int> mat[], int i, int j, vector<bool> visited[], int r, int c) {

    static int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[i][j] = true;

    for (int k = 0; k < 8; ++k)
        if(isValid(mat, i + rowNum[k], j + colNum[k], visited, r, c))
            dfs(mat, i + rowNum[k], j + colNum[k], visited, r, c);
}

int countIslands(vector<int> mat[], int r, int c) {

    vector<bool> visited[r];
    for (int i = 0; i < r; ++i) {
        visited[i] = vector<bool>(c);
        for (int j = 0; j < c; ++j)
            visited[i][j] = false;
    }

    int count = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {

            if (mat[i][j] && !visited[i][j]) {
                dfs(mat, i, j, visited, r, c);
                ++count;
            }
        }
    }

    return count;
}

int main() {

    int r, c;
    cout << "Enter the number of rows : ";
    cin >> r;

    cout << "Enter the number of columns : ";
    cin >> c;

    vector<int> mat[r];

    for (int i = 0; i < r; ++i) {
        vector<int> temp(c);
        mat[i] = temp;
        cout << "Enter the values for row " << i + 1 << " : ";
        for (int j = 0; j < c; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << "Number of islands are = " << countIslands(mat, r, c);

    return 0;
}

/*
 ~ Time Complexity  : O(rows * columns)
 ~ Space Complexity : O(rows * columns)
*/
