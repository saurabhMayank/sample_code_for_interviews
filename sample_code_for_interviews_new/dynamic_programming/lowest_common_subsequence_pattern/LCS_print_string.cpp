// TWO strings X(size n) and Y(size m)
// Instead of length of LCS
// 


int dp[n+1][m+1];


int LCS(string X, string Y, int n, int m){

        for(int i =0; i< n+1; ++i){
            for(int j = 0; j < m+1; ++j){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n+1; ++i){
            for(int j = 1; j<m+1; ++j){
                if(X[i-1] == Y[j-1]){
                    int count = dp[i-1][j-1];
                    dp[i][j] = 1 + count;
                    
                } else if(X[i-1] != Y[j-1]){
                    int count_1 =  dp[i-1][j];
                    int count_2 = dp[i][j-1];
                    dp[i][j] = max(count_1, count_2);
                }
            }
        }
  
       string res = "";
        
        while(i > 0 && j > 0){
          if(X[i-1] == Y[j-1]){
             // move to diagonal cell
            res.push_back(X[i-1]);
            i--;
              j--;
          } else if(X[i-1]!= Y[j-1]){
            // move to max of top cell and left cell
            if(dp[i-1][j] > dp[i][j-1]){
              i--;
            } else{
              j--;
            }
          } 
        }
  
       reverse(res.begin(), res.end());
       return res;
       
    }
