/**
 * Title   : Fibonacci Nth Term (Top Down Approach - Memoization)
 * Author  : Tridib Samanta
 **/

// time complexity - O(n)
// space complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int F[MAX];

void _initialize();
int fib(int);


int main() {
    int n;
    cin>>n;
    _initialize();
    cout<<fib(n)<<endl;
    return 0;
}

void _initialize()
{
    for (int i = 0; i < MAX; i++)
        F[i] = -1;
}

int fib(int n) {

    if(F[n] == -1)
    {
        if(n<=1)
            F[n]=n;
        else
            F[n]=fib(n-1)+fib(n-2);
    }
    return F[n];
}
