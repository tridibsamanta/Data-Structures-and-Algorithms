/**
 * Title     : Merge two sorted arrays with O(1) extra space
 * Author    : Tridib Samanta
 **/


#include<bits/stdc++.h>
using namespace std;

void mergeArrays(int a[], int b[], int m, int n) {

    for (int i = n - 1; i >= 0; --i) {

        int j, last = a[m-1];

        for (j = m-2; j>=0 && a[j] > b[i]; --j)
            a[j+1] = a[j];

        if (j != m-2 || last > b[i]) {
            a[j+1] = b[i];
            b[i] = last;
        }
    }
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

    mergeArrays(a, b, m, n);

    cout << "\nAfter Merging -\n";

    cout << "Array 1 is = ";
    for (int i = 0; i < m; ++i)
        cout << a[i] << " ";
    cout << "\n";

    cout << "Array 2 is = ";
    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << "\n";

    return 0;
}

/*
 * Time Complexity  : O(m*n)
 * Auxiliary Space  : O(1)
*/

