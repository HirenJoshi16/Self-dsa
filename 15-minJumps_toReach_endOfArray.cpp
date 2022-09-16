#include <iostream>
using namespace std;

// Finds minimum no of jumps to reach end of the array ~ T.C - O(n), S.C - O(1)
int minJumps(int *A, int n){
    // When array have single element, no of jumps taken is 0 bcz that single element is the last element hence its the end point and bcz having a single element there is 0 jumps
    if(n<=1){
        return 0;
    }

    // When starting element is 0 can't reach the end 
    if(A[0] == 0){
        return -1;
    }
    
    int maxReach = A[0]; // Stores maximum reaches of first value
    int steps = A[0]; // Stores maximum steps can be taken by first value
    int jumps = 1; // Everytime there can be single jump is needed to reach indeces/positions

        // Iterating from A[1] to A[n-1]
        for(int i=1; i<n; i++){
            // If end point is reached return no. of jumps
            if(i == n-1){
                return jumps;
            }

            // Will update maximum reaches of current value in the array  
            maxReach = max(maxReach, A[i]+i); // Where A[i]+i is the maximum reach point of current index value, hence we have to insure too that is current indeces max reach is maximum or previous's maximum thus max from both will find
            steps--; // As we move further we will decrease the steps bcz as we used up a step to get to the current index hence it has to be decreased 

                // If no further steps are left
                if(steps == 0){// When there is no step is left hence we must have used a jump then, thus increase jumps
                jumps++;
                    // Check in case current index value is negative or zero, if then we cant move further
                    if(i >= maxReach){
                        return -1;
                    }
                    steps = maxReach-i; // When steps is 0, we have to find no of steps to reach maximum reach from the ith position hence re-initialize steps
            }
        }
    return -1;
}

// Drive code
int main(){
    int A[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(A) / sizeof(A[0]);
    cout<<"Minimum no of jumps are : "<<minJumps(A, n);
    return 0;
}