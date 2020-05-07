/**
 * Title     : Merge Sort
 * Author    : Tridib Samanta
 **/

#include<iostream>
using namespace std;

void mergeArrays(int *arr, int *L, int L_len, int *R, int R_len) {

    int i = 0, j = 0, k = 0;

    while (i < L_len && j < R_len) {

        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < L_len)
        arr[k++] = L[i++];

    while (j < R_len)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int n) {

    if (n < 2)
        return;

    int mid = n / 2;

    int* L = new int[mid];
    int* R = new int[n - mid];

    for (int i = 0; i < mid; ++i)
        L[i] = arr[i];

    for (int i = mid; i < n; ++i)
        R[i - mid] = arr[i];

    mergeSort(L, mid);

    mergeSort(R, n - mid);

    mergeArrays(arr, L, mid, R, n - mid);

    delete L;
    delete R;

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

    mergeSort(arr, n);

    cout << "\nAfter sorting\n";
    displayArray(arr, n);

    return 0;
}

/*
 * Time Complexity  : O(n log n)
 * Auxiliary Space  : O(n)
*/

/*
Additional Notes -
1. Useful for sorting linked lists in O(n log n) time and in O(1) extra space
2. Stable, i.e., does not change the relative order of elements with equal keys
3. NOT in-place (only requires a constant amount - O(1) of additional memory space)
4. Algorithmic Paradigm - Divide and Conquer
5. Efficient than other simple quadratic (i.e., O(n^2)) algorithms, such as selection sort or bubble sort
*/
