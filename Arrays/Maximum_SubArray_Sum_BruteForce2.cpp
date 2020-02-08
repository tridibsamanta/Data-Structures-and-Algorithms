/**
 * Title   : Maximum sum sub-array (Brute Force Approach)
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

int Maximum_Sum_Subarray(int [],int);

int main() {

    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements : "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int max_sum=Maximum_Sum_Subarray(arr,n);
    cout<<"The Maximum Sub-array Sum is = "<<max_sum<<endl;

    return 0;
}

int Maximum_Sum_Subarray(int arr[],int n) {

    int ans=INT_MIN;
    for(int start_index=0;start_index<n;++start_index) {
        int sum=0;
        for(int sub_array_size=1;sub_array_size<=n;++sub_array_size) {
            if(start_index+sub_array_size>n)
                break;
            sum+=arr[start_index+(sub_array_size-1)];
            ans=max(ans,sum);
        }
    }
    return ans;
}
