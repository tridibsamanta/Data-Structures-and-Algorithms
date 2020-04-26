/**
 * Title     : Merge two sorted arrays
 * Author    : Tridib Samanta
 **/


#include<bits/stdc++.h>
using namespace std;

void mergeArrays(int a[], int b[], int m, int n, int c[]) {

    int i = 0, j =0, k = 0;

    while (i < m && j < n) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < m)
        c[k++] = a[i++];
    while (j < n)
        c[k++] = b[j++];
}

int main() {

    cout << "Enter the size of array 1 = ";
    int m;
    cin >> m;

    int a[m];
    cout << "Enter the " << m << " array elements = ";
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    cout << "Enter the size of array 2 = ";
    int n;
    cin >> n;

    int b[n];
    cout << "Enter the " << n << " array elements = ";
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    int c[m+n];

    mergeArrays(a, b, m, n, c);

    cout << "\nAfter Merging -\n";

    cout << "Array is = ";
    for (int i = 0; i < m+n; ++i)
        cout << c[i] << " ";
    cout << "\n";

    return 0;
}

/*
 * Time Complexity  : O(m+n)
 * Auxiliary Space  : O(m+n)
*/

