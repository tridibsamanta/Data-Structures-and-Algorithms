/**
 * Title     : Selection Sort
 * Author    : Tridib Samanta
 **/

#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {

    int minIdx;
    bool swapRequired;

    for (int i = 0; i < n - 1; ++i) {

        minIdx = i;
        swapRequired = false;

        for (int j = i + 1; j < n; ++j) {

            if (arr[j] < arr[minIdx]) {
                minIdx = j;
                swapRequired = true;
            }
        }

        if (swapRequired) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
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

    selectionSort(arr, n);

    cout << "\nAfter sorting\n";
    displayArray(arr, n);

    return 0;
}

/*
 * Time Complexity  : O(n^2)
 * Auxiliary Space  : O(1)
*/
