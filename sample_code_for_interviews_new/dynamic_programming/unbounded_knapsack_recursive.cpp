

int unbounded_knapsack(vector<int> wts, vector<int> val, int wt_limit, int n){
    if( n==0 || wt_limit == 0){
      return 0;
    }
    if(wts[n-1]<= wt_limit){
      //choose the option
      int output_1 = val[n-1];
      output_1 = output_1 + unbounded_knapsack(wt, val, wt_limit-wt[n-1], n);
      
      // not choosing the option
      int output_2 = unbounded_knapsack(wt, val, wt_limit, n-1);
      return max(output_1, output_2);
    }else {
      int output_3 = unbounded_knapsack(wt, val, wt_limit, n-1);
      return output_3;
    }
}
