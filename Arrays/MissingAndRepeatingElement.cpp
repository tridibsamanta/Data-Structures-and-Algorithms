/**
 * Title     : Find the missing and repeating element in an array
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

void findMissingRepeating(int arr[], int n) {

    for (int i = 0; i < n; ++i) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << "Repeating element : " << abs(arr[i]) << '\n';
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0)
            cout << "Missing element : " << i + 1 << '\n';
    }

}

int main() {
    int n;
    cout << "Enter the number of array elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    findMissingRepeating(arr, n);
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(1)
*/
