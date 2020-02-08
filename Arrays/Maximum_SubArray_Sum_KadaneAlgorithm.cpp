/**
 * Title   : Maximum sum sub-array (Kadane's Algorithm)
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

int Maximum_Subarray_Sum(int [],int);

int main() {

    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements : "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int max_sum=Maximum_Subarray_Sum(arr,n);
    cout<<"The Maximum Sub-array Sum is = "<<max_sum<<endl;

    return 0;
}

int Maximum_Subarray_Sum(int arr[],int n) {

    int ans=0,sum=0;

    for(int i=0;i<n;i++) {
        if(sum+arr[i]>0)
            sum+=arr[i];
        else
            sum=0;
        ans=max(ans,sum);
    }
    return ans;
}
