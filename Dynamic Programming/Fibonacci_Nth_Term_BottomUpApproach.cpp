/**
 * Title   : Fibonacci Nth Term (Bottom Up Approach - Tabulation)
 * Author  : Tridib Samanta
 **/

// time complexity - O(n)
// space complexity - O(n)

#include <iostream>
using namespace std;

int fib(int);

int main() {

    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}

int fib(int n) {
    int cache[n];

    //Base Cases
    cache[0]=0;
    cache[1]=1;

    for(int i=2;i<=n;i++)
        cache[i]=cache[i-1]+cache[i-2];

    return cache[n-1];
}
