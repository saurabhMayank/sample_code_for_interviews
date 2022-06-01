
// Give sum
// size n given
// arr given

// return bool stating 
// if there are subsets of the array that can sum upto
// given sum


int dp[n+1][sum+1];

int subset_sum_problem_dp(int n, int sum, vector<int> arr){
  
  for(int i = 0;i<n+1; ++i){
    for(int j = 0; j<sum+1; ++j){
      if (i == 0){
        dp[i][j]= True;
      } else if (j == 0){
        dp[i][j]= False;
      }
  }
    
  for(int i = 1; i<n+1; ++i){
    for(int j = 1; j<sum+1; ++j){
      if(arr[i-1] <= j){
        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
      }
    }
  }
    
  return dp[n][sum];
    
}
