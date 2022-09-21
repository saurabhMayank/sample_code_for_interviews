
// n => array size
// knapsack aim to extract max profit from the within the weight that is mentioned

// Option to choose a ball
// apply levels and Options Method

// Implement top down recursion technique
// because either n== 0 or W == 0 => val of ball = 0 => profit also 0
// as then as it goes down in the Euler Tree
// take the max profit, out of the two choices and return
int 01_knapsack(vector<int> wts, vector<int> val, int wt_limit, int n){
  
  if( n==0 || wt_limit == 0){
    return 0;
  }
 
  // first to check if the wt of the current item 
  // is within the weights option, then only we can have the flexibility
  // to choose it or not
    if(wts[n-1]<= wt_limit){
      // decrement the index in the recursion calls
      // so that pointer is on the right ball
      // in this way, ball ko pop nahin karwaana padega
      // much better in terms of writing code
      
      //choose the option
      int output_1 = val[n-1];
      output_1 = output_1 + 01_knapsack(wt, val, wt_limit-wt[n-1], n-1);
      
      // not choose the current option
      int output_2 = 01_knapsack(wt, val, wt_limit, n-1);
      
      // return max of the two
      return max(output_1, output_2);
    }else {

      int output_3 = 01_knapsack(wt, val, wt_limit, n-1);
      return output_3;
    }
}



