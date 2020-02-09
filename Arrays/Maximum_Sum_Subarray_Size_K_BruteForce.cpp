/**
 * Title   : Maximum Sum Sub-array of Size K (Brute Force Algorithm)
 * Author  : Tridib Samanta
 **/

 //Overall Time Complexity - O(n^2)

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

    int maxSum=INT_MIN;
    for(int i=0;i<=n-k;i++) {
        int windowSum=0;
        for(int j=i;j<i+k;j++) {
            windowSum+=arr[j];
        }
        maxSum=max(maxSum,windowSum);
    }
    return maxSum;
}
