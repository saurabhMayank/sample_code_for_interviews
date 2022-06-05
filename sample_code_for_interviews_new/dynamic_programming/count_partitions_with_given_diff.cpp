
int count_subsets_with_a_given_sum_dp(vector<int> arr, int sum, int n);

int countPartitionsWithGivenDiff(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i<n; ++i){
        sum = sum + arr[i];
    }
    
    // Let two subset sums be S1 and S2
    // S1 + S2 = sum
    // S1 - S2 = d
    // 2*S1 = d+sum
    // S1 = (d+sum)/2
    
    int subset_sum = (d+sum)/2;
    
    int count = count_subsets_with_a_given_sum_dp(arr, subset_sum, n);
    return count;
}


int count_subsets_with_a_given_sum_dp(vector<int> arr, int sum, int n){
    
    int dp[n+1][sum+1];

   for(int i = 0; i< n+1; ++i){
      for(int j = 0; j< sum+1; ++j){
         if(j == 0){
            dp[i][j] = 1;
         } else if(i == 0){
            dp[i][j] = 0;
         }
      }
   }
   
   
   for(int i = 1; i< n+1; ++i){
     for(int j = 1; j< sum+1; ++j){
         if(arr[i-1] > j){
            dp[i][j] = dp[i-1][j];
         } else if(arr[i-1] <= j){
           int taken = dp[i-1][j-arr[i-1]];
           int not_taken = dp[i-1][j];
           dp[i][j] = taken + not_taken;
         }
     }
   }

   return dp[n][sum];
}


