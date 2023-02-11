// Rod cutting recursive same as unbounded knapsack

// wt array -> length of pieces array
// W -> Rod length
// val array => price array

int unbounded_knapsack(vector<int> len_arr, vector<int> price, int rod_length, int n){
    if( n == 0 || rod_length == 0){
      return 0;
    }
    if(len_arr[n-1]<= rod_length){
      //choose the option
      int output_1 = price[n-1]+ unbounded_knapsack(len_arr, price, rod_length-len_arr[n-1], n);
      
      // not choosing the option
      int output_2 = unbounded_knapsack(len_arr, price, rod_length, n-1);
      return max(output_1, output_2);
    }else {
      int output_3 = unbounded_knapsack(len_arr, price, rod_length, n-1);
      return output_3;
    }
}
