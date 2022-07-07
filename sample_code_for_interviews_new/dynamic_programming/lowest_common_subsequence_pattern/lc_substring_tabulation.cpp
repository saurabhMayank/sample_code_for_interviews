// LC substring
// String X => length m
// String Y => length n 

int dp[n+1][m+1];

int lc_substring(string X, string Y, int n, int m) {
  
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<m; ++j){
      if(n == 0 || m == 0){
        dp[i][j] = 0;
      }
    }
  }
  
  int count = 0;
  
  
  for(int i = 1; i<m; ++i){
    for(int j = 1; j<n; ++j){
      
      if(X[i-1] == Y[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
      } else if(X[i-1] != Y[j-1]){
        dp[i][j] = 0;
      }
      
      // store the longest substring count at this point
      // in the count
      count = max(dp[i][j], count);
    }
  }
  
  return count;
}
