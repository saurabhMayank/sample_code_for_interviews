
// Give sum
// size n given
// arr given

// return bool stating 
// if there are subsets of the array that can sum upto
// given sum


  bool is_subset_sum(vector<int> arr, int sum, int n){
        
         int dp[n+1][sum+1]; 
            
          for(int i = 0;i<n+1; ++i){
                for(int j = 0; j<sum+1; ++j){
                    // array is empty
                    // jab array empty and subset sum nahin mila
                    // return false
                  if (i == 0){
                    dp[i][j]=  false;
                  } else if (j == 0){
                      // jab sum = 0 ho gya
                      // toh iska matlab subset mil gya
                      // jiska sum given sum ke equal hain
                      // sum is 0
                    dp[i][j] = true;
                  }
              }
          }

          for(int i = 1; i<n+1; ++i){
            for(int j = 1; j<sum+1; ++j){
              if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
              }else {
                  dp[i][j] =  dp[i-1][j];
              }
            }
          }
        return dp[n][sum];
    }
