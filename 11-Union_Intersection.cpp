//Program to find union and intersection for all the cases 
#include <bits/stdc++.h>
using namespace std;

void printArray(int *P, int n){
    for(int i=0; i<n; i++){
        cout<<P[i]<<" ";
    }
}

//Function to find union of the array
void Union(int *A, int *B, int n, int m){
    int i, j, ind;
    i=j=ind=0;
    int *C = new int[n+m]; //New auxilliary array

    while(i<n && j<m){
        if(A[i] < B[j]){
            if(ind != 0 && A[i] == C[ind-1]){
                i++;
            }
            else{
                C[ind] = A[i];
                i++; ind++;
            }
        }
        else{
            if(ind != 0 && B[j] == C[ind-1]){
                j++;
            }
            else{
                C[ind] = B[j];
                j++; ind++;
            }
        }
    }

    //Copies remaining element of the array to aux. array
    while(i < n){
        if(ind != 0 && A[i] == C[ind-1]){
            i++;
        }
        else{
            C[ind] = A[i];
            i++;
            ind++;
        }
    }
    while(j < m){
        if(ind != 0 && B[j] == C[ind-1]){
            j++;
        }
        else{
            C[ind] = B[j];
            j++;
            ind++;
        }
    }

    //Printing aux. array
    cout<<"Union : ";
    for(int k=0; k<ind; k++){
        cout<<C[k]<<" ";
    }
}

//Function to find intersection of the array
void interSection(int *A, int *B, int n, int m){
    int i, j, ind;
    i=j=ind=0;
    int *C = new int[n+m]; //New auxilliary array  

    while(i<n && j<m){
        if(A[i] < B[j]){
            i++;
        }
        else if(A[i] > B[j]){
            j++;
        }
        else{
            if(ind != 0 && A[i] == C[ind-1]){
                i++; j++;
            }
            else{
                C[ind] = A[i];
                i++; j++; ind++;
            }
        }
    }
    //Printing aux. array
    cout<<"Intersection : ";
    for(int k=0; k<ind; k++){
        cout<<C[k]<<" ";
    }
}

int main(){
    int A[] = {10, 10, 20, 1011, 12, 123};
    int B[] = {5, 6, 7, 10, 20, 90};

    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    // sort
    sort(A, A + n);
    sort(B, B + m);

    printArray(A, n);
    cout<<"  ";
    printArray(B, n);
    cout<<endl;
    Union(A, B, n, m);
    cout<<endl;
    interSection(A, B, n, m);
    return 0;
}

