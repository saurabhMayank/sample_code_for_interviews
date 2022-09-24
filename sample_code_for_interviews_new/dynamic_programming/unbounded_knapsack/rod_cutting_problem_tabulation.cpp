// N = 8
// Length Arr []: [1, 2, 3, 4, 5, 6, 7, 8] => size = 9
// Pieces Arr []: [1, 5, 8, 9, 10, 17, 17, 20]


int len_arr_size = length.size();

int dp[N+1][len_arr_size+1];

int rod_cutting_problem_tabulation(vector<int> length, vector<int> pieces, int N){
  
  // Base case
  // if N = 0 => profit of Pieces will be 0 as length asked is 0
  // if len_arr_size = 0 => As there will be no pieces of rod => So no pieces to sell => Profit 0.
  
  
  for(int i = 0; i< N+1; ++i){
    for(int j = 0; j< len_arr_size+1; ++j){
      if( i == 0 || j == 0){
          dp[i][j] = 0;
      }
    }
  }
  
   for(int i = 1; i < N+1; ++i){
    for(int j = 1; j< len_arr_size+1; ++j){
       if(length[i-1] <= j){
         dp[i][j] = max((pieces[i-1] + dp[i][j-length[i-1]]), dp[i-1][j]);
       } else if(length[i-1] > j){
         dp[i][j] = dp[i-1][j];
       }
    }
  }
  
  return dp[n][len_arr_size];
  
}
