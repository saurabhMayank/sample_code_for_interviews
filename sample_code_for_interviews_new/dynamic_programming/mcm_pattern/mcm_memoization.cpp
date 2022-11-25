//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // every grid of the DP matrix will store the cost
    // of matrix multiplication
    
    // changing variables in recursive code
    // are the variables i and j which represent array size
    // they will represent the size of dp matrix
    int dp[101][101];
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));

        int i = 1;
        int j = N-1;
        return solve(arr, i, j);
    }
    
    int solve(int arr[], int i, int j){
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int min_val = INT_MAX;
        
        for(int k=i; k<=j-1; ++k){
            int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            min_val = min(temp_ans, min_val);
        }
        
        // dp matrix will store the min cost for a particular i and j value
        // for an specific array size => which contains the dimensions of matrices
        // min cost is given
        
        // recursion concepts will be same here as in the recursive code
        // Just the DP matrix is added here
        
        // For Example Input => arr = [40, 20, 30, 10, 30]
        
        // When recursion call is for arr, i =3 and j = 4 
        // temp_ans calculated
        // min set
        // so for dp[3][4] = min stored
        // Now again if dp[3][4] is called => directly ans be returned
        
        
        dp[i][j] = min_val;
        return dp[i][j];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
