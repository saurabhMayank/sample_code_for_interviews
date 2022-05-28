
// n => array size
// knapsack aim to extract max profit from the within the weight that is mentioned
int 01_knapsack(vector<int> wts, vector<int> val, int wt_limit, int n){
  
  // items taken from back of the array
  // Faith Expectation method => TOP DOWN APPROACH FOR THIS RECURSION PROBLEM
  // Results will start getting calculated when we come down in recursion tree
  
  // Expectation
  // Get a Max Profit value for the whole input
  
  // Faith
  // Two options
  // choose value
  // val[n-1] + (rest of the input, will give max val on its own)
  
  // Not choosing value
  // (rest of the input, will give max val on its own)
  
  // Expectation <-> Faith
  // return the max value of the two outputs that are there.
  
  if( n==0 || wt_limit == 0){
    return 0;
  }
 
  // first to check if the wt of the current item 
  // is within the weights option, then only we can have the flexibility
  // to choose it or not
    if(wts[n-1]<= wt_limit){
      //choose the option
      int output_1 = val[n-1];
//       wt_1 = wts;
//       wt_1.pop_back();
//       val_1 = val;
//       val_1,pop_back();
      // pop back karne ki zaroorat nahin hain coz i am taking size, wo hmesha kam kar rhe hain
      // toh usse wo particular element access ho jaaega
      // original array hi pass kar do, size decrease kar do
      // agar size nahin lia hota toh pop karwaana padta
      output_1 = output_1 + 01_knapsack(wt, val, wt_limit-wt[n-1], n-1);
      int output_2 = 01_knapsack(wt, val, wt_limit, n-1);
      return max(output_1, output_2);
    }else {
//       wt_1 = wts;
//       wt_1.pop_back();
//       val_1 = val;
//       val_1,pop_back();
      int output_3 = 01_knapsack(wt, val, wt_limit, n-1);
      return output_3;
    }
}



