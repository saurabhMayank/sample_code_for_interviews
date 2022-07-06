// LCS memoization code
// INPUT => Two Strings X, Y => sizeof(X) == n, sizeof(Y) ==  m

int dp[n+1][m+1]
int main(){
  memset(dp, -1, sizeof(dp));
  LCS(X, Y, n, m);
}

int LCS(int X, int Y, int n, int m){
   if(n == 0 || m == 0){
       return 0;
   }
   
   if(dp[n][m] != -1){
   return dp[n][m];
   }
   
   if(X[n-1] == Y[m-1]){
     int count = LCS(X,Y, n-1, m-1);
     dp[n][m] = 1 + count;
   }else if(X[n-1] != Y[m-1]){
     int count_1 = LCS(X, Y, n, m-1);
     int count_2 = LCS(X, Y, n-1, m);
     dp[n][m] = max(count_1, count_2);
   }
   return dp[n][m];
}
