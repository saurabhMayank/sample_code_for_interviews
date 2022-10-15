#include<iostream>
#include<vector>

using namespace std;
// asf -> answer so far
void floodfill((vector<vector<int>> &maze, int row, int col, string asf, vector<vector<bool>> &visited) {
   
   if(row < 0 || col < 0 || row == maze.size() || col == maze[0].size() 
        || maze[row][col] == 1)
    {
       return;
    }
   
    if(row == maze.size()-1 && col == maze.size()-1){
        cout << asf << endl;
        return;
    }
   
   
   // marking cell visiting now as true
   visited[row][col] = true;
   // top
   floodfill(maze, row-1, col, asf+"t", visited);
   // left
   floodfill(maze, row, col-1, asf+"l", visited);
   // down
   floodfill(maze, row+1, col, asf+"d", visited);
   // right
   floodfill(maze, row, col+1, asf+"r", visited);
   
   // marking cell retracing from as False
   visited[row][col] = false
   return;

}

int main() {
  int n, m;
  cin >> n >> m;
  vector < vector < int >> arr(n, vector < int > (m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  vector < vector < bool >> visited(n, vector < int > (m));
  floodfill(arr, 0, 0, "", visited);
}
