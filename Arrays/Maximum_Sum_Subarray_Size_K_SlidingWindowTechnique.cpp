/**
 * Title   : Maximum Sum Sub-array of Size K (Sliding Window Technique)
 * Author  : Tridib Samanta
 **/

 //Overall Time Complexity - O(n)

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iostream>
using namespace std;

int getMaxSubArrayOfSizeK(int [],int,int);

int main() {

    int n,k;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements : "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the value of k : "<<endl;
    cin>>k;
    int max_sum=getMaxSubArrayOfSizeK(arr,k,n);
    cout<<"The maximum sum of subarray of size "<<k<<" is = "<<max_sum<<endl;
    return 0;
}

int getMaxSubArrayOfSizeK(int arr[],int k,int n) {

    int windowSum=0,maxSum=INT_MIN;

    for(int i=0;i<k;i++) {
        windowSum +=arr[i];
    }
    //maxSum=max(maxSum,windowSum);
    maxSum=windowSum;

    for(int end=k;end<n;end++) {
            windowSum+=arr[end]-arr[end-k];
            maxSum=max(maxSum,windowSum);
    }

    return maxSum;
}
