/**
 * Title     : Insertion Sort
 * Author    : Tridib Samanta
 **/

#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int key;
    for (int i = 1; i < n; ++i) {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
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

    insertionSort(arr, n);

    cout << "\nAfter sorting\n";
    displayArray(arr, n);

    return 0;
}

/*
 * Time Complexity  : O(n^2)
 * Auxiliary Space  : O(1)
*/

/*
Additional Notes -
1. Efficient when the number of elements in the list are quite small
2. Adaptive, i.e., efficient for already substantially sorted list of elements
3. Stable, i.e., does not change the relative order of elements with equal keys
4. In-place, i.e., only requires a constant amount - O(1) of additional memory space
5. Online, i.e., can sort a list as it receives it
6. More efficient in practice than other simple quadratic (i.e., O(n^2)) algorithms, such as selection sort or bubble sort
*/
