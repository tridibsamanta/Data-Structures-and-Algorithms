/**
 * Title     : Count the Number of Islands (Using BFS)
 * Author    : Tridib Samanta
**/

/*
    In a given 2D matrix, a group of connected 1's forms an island. For example -

    mat[][] = {{1, 1, 0, 0, 0},
               {0, 1, 0, 0, 1},
               {1, 0, 0, 1, 1},
               {0, 0, 0, 0, 0},
               {1, 0, 1, 1, 0}};

    Number of islands are = 4
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int> >& mat, int i, int j, vector<bool> visited[], int rows, int columns) {

    return (i >= 0) && (i < rows) &&
           (j >= 0) && (j < columns) &&
           (mat[i][j] && !visited[i][j]);
}

void bfs(vector<vector<int> >& mat, int i, int j, vector<bool> visited[], int rows, int columns) {

    static int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    visited[i][j] = true;

    while (!q.empty()) {

        int curr_i = q.front().first;
        int curr_j = q.front().second;
        q.pop();

        for (int k = 0; k < 8; ++k) {
            if (isValid(mat, curr_i + rowNum[k], curr_j + colNum[k], visited, rows, columns)) {
                q.push(make_pair(curr_i + rowNum[k], curr_j + colNum[k]));
                visited[curr_i + rowNum[k]][curr_j + colNum[k]] = true;
            }
        }
    }
}

int countIslands(vector<vector<int> >& mat) {

    int rows = mat.size();
    int columns = mat[0].size();

    vector<bool> visited[rows];
    for (int i = 0; i < rows; ++i) {
        visited[i] = vector<bool> (columns);
        for (int j = 0; j < columns; ++j)
            visited[i][j] = false;
    }

    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (mat[i][j] && !visited[i][j]) {
                bfs(mat, i, j, visited, rows, columns);
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

    vector<vector<int> > mat(r);

    for (int i = 0; i < r; ++i) {
        cout << "Enter the values for row " << i + 1 << " : ";
        vector<int> temp(c);
        mat[i] = temp;
        for (int j = 0; j < c; ++j) {
                cin >> mat[i][j];
        }
    }

    cout << "Number of islands are = " << countIslands(mat);

    return 0;
}

/*
 ~ Time Complexity  : O(rows * columns)
 ~ Space Complexity : O(rows * columns)
*/
