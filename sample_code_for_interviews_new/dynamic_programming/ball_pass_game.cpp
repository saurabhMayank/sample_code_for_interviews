// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int ball_pass_helper(int& start, int curr_player,  int curr_moves, int& X, int& N) {
  
  if(curr_player == start && curr_moves > 0 && curr_moves <= X){
    return 1;
  }
  
  int total_ways = 0;
  
  for(int i = 1; i<=N; ++i) {
    
    if(i != curr_player && (curr_moves <= X) && (i%curr_player == 0 || curr_player% i == 0)){
      
      total_ways = total_ways + ball_pass_helper(start, i, curr_moves+1, X, N);
    }
    
  }
  
  return total_ways;
    
}

int main() {
    // Write C++ code here

    int start = 2;
    int N = 3;
    int X = 4;

    int curr_moves = 0;
    
    

    int ans = ball_pass_helper(start, start, curr_moves, X, N);
    
    cout << ans << endl;

    return 0;
}
