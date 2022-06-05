class Solution {
    
    // this code will only work when all the values are positive
    // for negative values it does not work
public:
    int minimumDifference(vector<int>& arr) {
        
    
        // sum all the elements in the array
        int total_sum = 0;
        for(int i = 0; i<arr.size(); ++i){
            total_sum = total_sum + arr[i];
        }
        
        // Final AIM -> Minimize S1 - S2
        
        // assuming two parititons sums S1 and S2
        // S2 = total_sum -S1
        
        // Minimize ((total_sum-S1)-S1) => total_sum - 2*S1
        
        // finding possible values of S1 and
        // then minimizing the total equations
        int sum = total_sum/2;
        int n = arr.size();
        vector<int> subset_sum_possible_vals = subset_sum_problem(arr, sum, n);
        
        int min_diff = INT_MAX;
        
        for(int i = 0; i<subset_sum_possible_vals.size(); ++i){
            int first = subset_sum_possible_vals[i];
            int second = total_sum - subset_sum_possible_vals[i];
            // abs kare ya na kare fark nahin padega
            // because second always > first according to our previous assumption
            int diff = abs(second - first);
            if(diff < min_diff){
                min_diff = diff;
            }
        }
         
      return min_diff;  
           
    }
    
    // modified form of subset sum problem
    // instead of returning the last grid
    // returning the possible sum values 
    // which have True value in the last grid
    
    vector<int>subset_sum_problem(vector<int> arr, int sum, int n){
        
          bool dp[n+1][sum+1]; 
            
          for(int i = 0;i<n+1; ++i){
                for(int j = 0; j<sum+1; ++j){
                    // array is empty
                    // jab array empty and subset sum nahin mila
                    // return false
                  if (i == 0){
                    dp[i][j]=  false;
                  } else if (j == 0){
                      // jab sum = 0 ho gya
                      // toh iska matlab subset mil gya
                      // jiska sum given sum ke equal hain
                      // sum is 0
                    dp[i][j] = true;
                  }
              }
          }

          for(int i = 1; i<n+1; ++i){
            for(int j = 1; j<sum+1; ++j){
              if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
              }else {
                  dp[i][j] =  dp[i-1][j];
              }
            }
          }
        
        
        vector<int> subset_sum_possible_vals;
        
        for(int i=0; i<sum+1; ++i){
            if(dp[n][i] == true){
                subset_sum_possible_vals.push_back(i);
            }
        }
        
        return subset_sum_possible_vals;
    }
};
