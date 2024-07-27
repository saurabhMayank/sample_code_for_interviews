// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int ball_pass_helper(int& start, int curr_player,  int curr_moves, int& X, int& N) {
  
  if(curr_player == start && curr_moves > 0 && curr_moves <= X){
    
     
     // just doing this is not capturing all the possibilities
     return 1;
     
    
    
    // logic not working -> core dumped coming
    
    // if(curr_moves == X){
    //     return 1;
        
    // } else if(curr_moves <= X){
      
    //     // if curr_moves <= X
       
    //   // but this is an incomplete ans as it does not capture
    //   // 2 -> 1 -> 2  (ans) -> but can still move
    //   // as moves left
    //   // 2 -> 1 -> 2 (this is not captured)
    //   // How to capture that ?
       
       
    //   // game completed and again started from same player as moves left
       
    //   1 + ball_pass_helper(start, curr_player, curr_moves, X, N);
      
    // }
       
  }
  
  int total_ways = 0;
  
  for(int i = 1; i<=N; ++i) {
    

    
    if(i != curr_player && (curr_moves <= X) && (i%curr_player == 0 || curr_player% i == 0)){
      
          cout << curr_player << " " << i << endl;
      
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
    
    cout << endl;
    
    cout << "---------------------------" << endl;
    
    cout << ans << endl;

    return 0;
}
