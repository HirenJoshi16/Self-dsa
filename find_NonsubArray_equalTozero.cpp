// Program to find non subarray sum equal to zero
#include <iostream>
using namespace std;

// Naive Approach to find non subarray sum equal to zero ~ T.C - O(n^2), S.C - O(1)
void findSubsum(int *A, int n){
    // If array is empty by size
    if(n <= 0){
        cout<<"Array Empty!";
    }

    // There exists only single element or its zero
    if(n == 1 || A[0] == 0){
        cout<<"Element is zero or one sized array";
    }
    int i, j, noSum;
    int k=0; // To store j+1 indeces to calculate
        // Iterate over the array and check subarray sum for each index value
        for(i=0; i<n; i++){

            noSum = 1;
            // Check all possibilities of sum by each value for it
            for(j=0; j<n; j++){

                k = j+1; // Update k in each iteration by j+1
                // When i and j are 0 then increase j by 1 and k by 1
                if(i == 0){
                    j++; k++;
                }
                // Move j further without being i
                else if(j == i){
                    j++;
                }
                // Move k further without being i
                if(k == i){
                    k++;
                }

                // When there sum is not equal to zero or zero already exist
                if(A[i]+A[j]+A[k] != 0){
                    noSum = 0; // If no sum is there
                }
                // When there sum is equal to zero
                else{
                    cout<<A[i]<<" "<<A[j]<<" "<<A[k]<<endl;
                    exit(0);
                }
            }
            // Check if no sum in array
            if(noSum == 0){
                cout<<"0 already in the array or no such sum exist";
                break;
        }
    } 
}

// Driver code
int main(){
    // int A[] = {-3, 1, 2, 4, 6};
    // int A[] = {1, 4, -2, -2, 0, -4, 3};
    int A[] = {4, 7, -6, -10, 6, 6, 3};
    // int A[] = {1, 0, -6, -10, 0};
    // int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    findSubsum(A, n);

    return 0;
}