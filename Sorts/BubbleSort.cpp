/**
 * Title     : Bubble Sort
 * Author    : Tridib Samanta
 **/

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    bool swapping;

    for (int i = 0; i < n - 1; ++i) {

        swapping = false;

        for (int j = 0; j < n - i - 1; ++j) {

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapping = true;
            }
        }

        if (!swapping)
            return;
    }
}

void displayArray(int arr[], int n) {
    cout << "The array elements are - ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {

    int n;
    cout << "Enter the size of the array - ";
    cin >> n;

    int arr[n];
    cout << "Enter the " << n << " array elements - ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "\nBefore sorting\n";
    displayArray(arr, n);

    bubbleSort(arr, n);

    cout << "\nAfter sorting\n";
    displayArray(arr, n);

    return 0;
}

/*
 * Time Complexity  : O(n^2)
 * Auxiliary Space  : O(1)
*/
