/**
 * Title   : Maximum sum sub-array (Divide and Conquer Approach)
 * Author  : Tridib Samanta
 **/

 //Overall Time Complexity - O(n log n)

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

    if(n==1)
        return arr[0];

    int m=n/2;
    int left_MSS=Maximum_Subarray_Sum(arr,m);
    int right_MSS=Maximum_Subarray_Sum(arr+m,n-m);
    int leftsum=INT_MIN,rightsum=INT_MIN,sum=0;
    for(int i=m;i<n;i++) {
        sum+=arr[i];
        rightsum=max(rightsum,sum);
    }
    sum=0;
    for(int i=(m-1);i>=0;i--) {
        sum+=arr[i];
        leftsum=max(leftsum,sum);
    }
    int ans=max(left_MSS,right_MSS);
    return max(ans,leftsum+rightsum);
}
