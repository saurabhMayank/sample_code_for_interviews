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
        // int len = sizeof(price)/sizeof(price[0]);
        // int length[len];
        
        // size of Rod and length of price array same
        
        int len = n;
        int length[len];
        
        for(int i = 0; i<len; ++i){
            length[i] = i+1;
        }
        
         int t[n + 1][len + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < len + 1; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }
    
        // Step 2: Iterative code
        for (int i = 1; i < n + 1; i++){
            for (int j = 1; j < len + 1; j++){
                if(length[i - 1] <= j){
                    // taken
                    int op1 = price[i - 1] + t[i][j - length[i - 1]];
                    // not taken
                    int op2 = t[i - 1][j];
                    t[i][j] = max(op1, op2);
                    
                }else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
    
        // Step 3: Return
        return t[n][len];
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
