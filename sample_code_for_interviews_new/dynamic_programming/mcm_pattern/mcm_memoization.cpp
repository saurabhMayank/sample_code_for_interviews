
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // every grid of the DP matrix will store the cost
    // of matrix multiplication
    
    // changing variables in recursive code
    // are the variables i and j which represent array size
    // they will represent the size of dp matrix
    int dp[101][101];
    // int min_val = INT_MAX;
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));

        int i = 1;
        int j = N-1;
        return solve(arr, i, j);
    }
    
    int solve(int arr[], int i, int j){
        if(i>=j){ // 1
            return 0; //2
        } // 3
        
        if(dp[i][j] != -1){ // 4
            return dp[i][j]; // 5
        } // 6
        
        int min_val = INT_MAX; // 7
        
        // recursive concept explained in the recursive code
        
        for(int k=i; k<=j-1; ++k){ // 8
            int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]; // 9
            cout << solve(arr, i, k) <<","<<solve(arr, k+1, j)<<","<<arr[i-1]*arr[k]*arr[j] << ","; 
            cout << temp_ans << "=bc=";
            cout << min_val << "=ac="; 
            min_val = min(temp_ans, min_val); //10
            cout << min_val << endl;
        } // 11
        
        // dp matrix will store the min cost for a particular i and j value
        // for an specific array size => which contains the dimensions of matrices
        // min cost is given
        
        // When code will recursively go 
        // to solve a subproblem 
        // then after the subproblem is solved when loop ends
        // ans will stored in the dp matrix -> which is used further in the problem
        dp[i][j] = min_val; // 12
        return dp[i][j]; // 13
    }
};
