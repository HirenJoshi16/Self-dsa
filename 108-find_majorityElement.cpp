// Coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Shows the element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// Finds majority element to array ~ O(n*logn) & O(1)
// T.C - O(n*logn) bcz as sorting takes O(n*logn) hence O(n*logn)+O(n) = O(n*logn) 
int findMajority(int *A, int n){
    int i, j;
    int count=1;
    sort(A, A+n);
        
        i=0;
        j=i+1;
        while(j<n+1){
            // If value counts turn out to be upper bound of condition
            if(count > n/2){
                return A[i];
            }
            else if(A[i] == A[j]){
                count++;
                i++; j++;
            }
            else if(A[i] != A[j]){
                count = 1;
                i++; j++;
            }
            else{
                return -1;
        }
    }
    return 0;
}

// Driver code
int main(){
    int A[] = {2, 12, 2, 2, 2, 4, 2};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);

    cout<<endl;
    if(int val = findMajority(A, n)){
        cout<<"Majority element is : "<<val;
    }
    else{
        cout<<"No majority element";
    }
    return 0;
} 