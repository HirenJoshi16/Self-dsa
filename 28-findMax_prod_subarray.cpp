#include <bits/stdc++.h>
using namespace std;

// Prints array element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// // Finds maximum product in subarray
// // Hiren's logic but wrong in lot cases
// int maxProdsubArray(int *A, int n){
//     int i, j;
//     int mid = n/2;

//     int prod1=1, prod2=1;
//     for(i=0; i<=mid; i++){
//         prod1 *= A[i];
//     }
//     for(j=n-1; j>mid; j--){
//         prod2 *= A[j];
//     }
//     cout<<prod1<<" & "<<prod2<<endl<<endl;
//     int maximum = max(prod1, prod2);
//     for(int i=0; i<n; i++){
//         if(A[i] > maximum){
//             maximum = A[i];
//         }
//     }
//     return maximum;
// }

// Finds maximum product subarray ~ O(n) & O(1)
int maxProdsubArray(int *A, int n){
    int currProd = 1;
    int maxProd = 1;

    // Iterate from left to right & find maximum product
    for(int i=0; i<n; i++){
        currProd *= A[i];
        maxProd = max(maxProd, currProd);
        
        if(currProd==0){
            currProd = 1;
        }
    }
    // Set currnt product again to 1 as it contains the first loops product
    currProd=1;
    // Iterate from right to left & find maximum product
    for(int i=n-1; i>=0; i--){
        currProd *= A[i];
        maxProd = max(maxProd, currProd);
        
        if(currProd==0){
            currProd = 1;
        }
    }
    return maxProd;
}

// Driver code
int main(){
    // int A[] = {6, -3, -10, 0, 2};
    // int A[] = {1, -3, -10, 0, 60};
    int A[] = {1, -2, -3, 0, 7, -8, -2};
	// int A[] = { 1, -2, -3, 0, 7, -8,  4, 10, -20};
	int n = sizeof(A) / sizeof(A[0]);

    printArray(A, n);
    cout<<endl;
    cout<<"maximum product subarray is : "<<maxProdsubArray(A, n);
    return 0;
}