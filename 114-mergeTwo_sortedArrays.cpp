#include <bits/stdc++.h>
using namespace std;

// Merges two sorted array
void mergeArrays(int *A, int *B, int n, int m){
    map <int, int> freqCount;

    for(int i=0; i<n; i++){
        freqCount.insert(A[i])++;
    }
    for(int i=0; i<n; i++){
        freqCount.insert(B[i])++;
    }
    // cout<<freqCount[0];
}

// Driver code
int main()
{
    int A[] = {1, 2, 3, 4, 5, 5};
    int B[] = {3, 3, 5, 10, 16, 20};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    mergeArrays(A, B, n, m);
    return 0;
}