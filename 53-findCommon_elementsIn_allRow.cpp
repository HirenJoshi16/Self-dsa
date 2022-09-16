// Program to find common elements from all rows in matrix - coded by vHiren
#include <iostream>
using namespace std;

// Finds element in matrix ~ Optimal Approach - O(r*c) where r - rows and c - columns & O(1) S.C
int findCommon(int A[3][3]){
    int k=0; // Indicates first row 
    int commonVal=-1;

        int rowOneVal = A[0][k]; 
        // Iterate from second row
        for(int i=1; i<3; i++){
            for(int j=0; j<3; j++){
                if(A[i][j] == A[0][k]){
                    commonVal = A[i][j];
                }
            }
            // If current common value is equal to first row's first value hence initialize k again to 0
            if(commonVal = A[0][k]){
                k=0;
            }
            // If its not equal to first row's first hence increament k
            else{
                k++;
            }
        }
    return commonVal;
}

// Driver code
int main(){
    int A[3][3];
    // Input matrix
    cout<<"Enter Matrix : "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>A[i][j];
        }
    }

    if(int commonVal = findCommon(A)){
        cout<<"common value found : "<<commonVal;
    }
    else{
        cout<<"no common found";
    }
    return 0;
}