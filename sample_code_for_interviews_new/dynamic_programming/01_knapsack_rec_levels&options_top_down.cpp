// Levels and Options top down is a simple approach
// At every level, explore all the options, but just don't compute the output
// when u reach the base case, return 0, then start computing output
// by adding current level results to output and then returning max of two
// because we need max profit


int 01_knapsack(vector<int> w, vector<int> val, int W, int n){
  if(n == 0 || W == 0){
    return 0;
  }
  
  //if wt < W
  if(w[n-1] < W){
    // two function calls
    
    // choose the output
    int output_1 = output;
    output_1 = val[n-1]+ 01_knapsack(w, val, W-w[n-1], n-1);
    
    // don't choose the output
    int output_2 = output;
    output_2 = 01_knapsack(w, val, W, n-1);
    
    return max(output_1, output_2);
  }else {
    // only one function call
    output = 01_knapsack(w, val, W, n-1);
    return output;
  }
  
}
