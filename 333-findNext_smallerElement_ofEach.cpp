// Program to find next smaller element of each element to array ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Displays elements to array
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}

// Function to find next smaller element of each ~ O(n) & O(1)
bool nextSmallerEssence(int *A, int n){
    // If array is void 
    if(n==0){
        return false;
    }
    int minNow = INT_MAX;
    int minTillnow = INT_MAX;
    int i, j;
    j=n-2;

    // For each case last element's smaller will never conclude hence to -1
    cout<<-1<<' ';

        // Iterate from behind to index 1
        for(i=n-1; i>=1; i--){
            // Updates minimum element from ith & jth element in each iteration
            minNow = min(A[i], A[j]);
            // Stores minimum element till now
            minTillnow = min(minTillnow, minNow);

                if(A[j] > minNow){
                    cout<<minNow<<' ';
                }
                else if(A[j] > minTillnow){
                    cout<<minTillnow<<' ';
                }
                else{
                    cout<<-1<<' ';
                }
            j--;
        }
    return true;
}

// Driver code
int main(){
    // int A[] = {4, 8, 5, 2, 25};
    int A[] = {13, 7, 6, 12};
    int n=4;
    printArray(A, n);

    // Function call
    if(nextSmallerEssence(A, n)){
        exit(1);
    }
    else{
        cout<<"Something went wrong!";
    }
    return 0;
}