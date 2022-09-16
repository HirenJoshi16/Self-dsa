#include <iostream>
#include <unordered_set>
using namespace std;

// Finds row with maximum number of ones in matrix ~ Optimal Approach - O(n+m) & O(1) 
// Does not work for 1st row/starting row
int findmaxOnes(int A[3][3]){
    int row=3;
    int col=3;
    int i=0;
    int j=col-1;
        
        int maxReach=-1;
        while(i<row && j>=0){
            if(A[i][j]==1){
                maxReach = i;
                j--;
            }
            else{
                i++;
            }
        }
    return maxReach;
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

    if(int maxReach = findmaxOnes(A)){
        cout<<"row with maximum one's is : "<<maxReach;
    }
    else{
        cout<<"zerod matrix exist";
    }
    
    return 0;
}