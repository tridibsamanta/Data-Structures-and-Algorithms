/**
 * Title   : Maximum sum sub-array (Kadane's Algorithm)
 * Author  : Tridib Samanta
 **/

 //Overall Time Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int Maximum_Subarray_Sum(int [],int);

int main() {

    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int arr[n];
        int cnt=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]<0)
                cnt++;
        }
        if(cnt==n)
            cout<<*max_element(arr, arr + n)<<endl;
        else {
            int max_sum=Maximum_Subarray_Sum(arr,n);
            cout<<max_sum<<endl;
        }
    }
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
