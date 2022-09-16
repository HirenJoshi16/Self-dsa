// Program to find next greater element of each element to array ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Displays elements to array
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}

// Function to find next greater element of each ~ O(n) & O(1)
bool nextGreaterEssence(int *A, int n){
    // If array is void 
    if(n==0){
        return false;
    }
    int maxNow = 0;
    int maxTillnow = 0;
    int i, j;
    j=A[n-2];

        // Iterate from behind to index 1
        for(i=n-1; i>=1; i--){
            // Updates maximum element from ith & jth element in each iteration
            maxNow = max(A[i], A[j]);
            // Stores maximum element till now
            maxTillnow = max(maxTillnow, maxNow);

                if(A[j] < maxNow){
                    A[j] = maxNow;
                }
                else if(A[j] < maxTillnow){
                    A[j] = maxTillnow;
                }
                else{
                    A[j] = -1;
                }
            j--;
        }
    // For each case last element's greater will never conclude hence to -1
    A[n-1] = -1;
    return true;
}

// Driver code
int main(){
    // int A[] = {13, 7, 6, 12};
    int A[] = {4, 5, 2, 25};
    int n=4;
    printArray(A, n);

    // Function call
    if(nextGreaterEssence(A, n)){
        printArray(A, n);
    }
    else{
        cout<<"Something went wrong!";
    }
    return 0;
}