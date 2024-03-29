#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess, int n, int r, int c, int upcomingMove) {
  
    if( r < 0 || c < 0 || r >= chess.size() || c>= chess.size() || chess[r][c] > 0){
        return;
    }else if(upcomingMove == chess.size()*chess.size() ){
       chess[r][c] = upcomingMove;
       display(chess);
       chess[r][c] = 0;
       return;
    }
    
    
    chess[r][c] = upcomingMove;
    printKnightsTour(chess, n, r-2, c+1 , upcomingMove+1);
    printKnightsTour(chess, n, r-1, c+2 , upcomingMove+1);
    printKnightsTour(chess, n, r+1, c+2 , upcomingMove+1);
    printKnightsTour(chess, n, r+2, c+1 , upcomingMove+1);
    printKnightsTour(chess, n, r+2, c-1 , upcomingMove+1);
    printKnightsTour(chess, n, r+1, c-2 , upcomingMove+1);
    printKnightsTour(chess, n, r-1, c-2 , upcomingMove+1);
    printKnightsTour(chess, n, r-2, c-1 , upcomingMove+1);
    chess[r][c] = 0;
}

int main() {
    
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> chess(n, vector<int> (n, 0));
    // 1 denotes move number 1st
    // after every function call -> move is incremented
    // number of moves to cover the whole matrix w/o repeating cells -> n*n
    printKnightsTour(chess, n, r, c, 1);
}
