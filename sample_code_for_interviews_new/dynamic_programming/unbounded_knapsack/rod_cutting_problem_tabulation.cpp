// N = 8
// Mostly jis size ka rod hota hain => Uss size ka length array and price array hota hain

// If length array nahin dia => construct kar lo

// Length Arr []: [1, 2, 3, 4, 5, 6, 7, 8] => size = 8
// Pieces Arr []: [1, 5, 8, 9, 10, 17, 17, 20]


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        // len array of rod not given
        // construct length
       
        // int length[len];
        
        // size of Rod and length of price array same
        
        int len = n;
        int length[len];
        
        int price_size = sizeof(price)/sizeof(price[0]);
        cout << "---price_size----" << price_size << endl;
        
        for(int i = 0; i<len; ++i){
            length[i] = i+1;
        }
        
        // n => size of rod
        int dp[n+1][len+1];
        
        
        for(int i = 0; i<=n; ++i){
            for(int j = 0; j<=len; ++j){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=len; ++j){
                if(length[j-1] <= i){
                    
                    //taken
                    int taken = price[j-1] + dp[i-length[j-1]][j];
                    
                    
                    //not taken
                    // consider item processed, piece processed
                    int not_taken = dp[i][j-1];
                    
                    dp[i][j] = max(taken, not_taken);
                } else {
                   dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return dp[n][len];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
