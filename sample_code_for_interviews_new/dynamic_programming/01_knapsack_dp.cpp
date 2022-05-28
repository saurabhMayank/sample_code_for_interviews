// constraints
// n = 100
// W = 1000

int dp[100][1000];
memset(dp, -1, sizeof(dp));

int 01_knapsack(vector<int> w, vector<int> val, int W, int n){
  if(n == 0 || W == 0){
    return 0;
  }
  
  if(dp[n][W] != -1){
    return dp[n][W];
  }
  
  //if wt < W
  if(w < W){
    // two function calls
    
    // choose the output
    int output_1 = output;
    output_1 = val[n]+ 01_knapsack(w, val, W-w[n], n-1);
    
    // don't choose the output
    int output_2 = output;
    output_2 = 01_knapsack(w, val, W, n-1);
    
    dp[n][W] = max(output_1, output_2);
    return dp[n][W] ;
  }else {
    // only one function call
    output = 01_knapsack(w, val, W, n-1);
    dp[n][W] = output;
    return dp[n][W];
  }
}
