// Logic & coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Shows the element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// Finds product of A[i] except A[i] itself ~ O(n) & O(1)
void findProduct(int *A, int n){
    int product=1;

    // When array is 0 sized
    if(n<=0){
        return;
    }
        // Iterate the array
        for(int i=0; i<n; i++){
            // Calculate the total product 
            product *= A[i];
        }

        int prodIs;
        // Divide each value by total product 
        for(int i=0; i<n; i++){
            prodIs = product/A[i];
            cout<<"Product of "<<A[i]<<" except itself is : "<<prodIs<<endl;
        }
}

// Driver code
int main(){
    int A[] = {4, 6, 3, 2, 10};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);

    cout<<endl;
    findProduct(A, n);
    return 0;
} 