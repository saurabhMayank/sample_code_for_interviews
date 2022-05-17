#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
  //Write your code here
  if(sr==dr && sc==dc){
      vector<string>path;
      path.push_back("");
      return path;
  }else if(sr > dr && sc > dc){
      vector<string>path;
      return path;
  }
  
  vector<string> total_paths;
  //horizontal movement
  // sc = starting column
  // jump can be made only after that
  for(int i=1; i+sc<=dc; ++i){
      vector<string>paths_1 = get_maze_paths(sr, sc+i, dr, dc);
      for(int j=0; j<paths_1.size(); ++j){
          string path = paths_1[j];
          string num = to_string(i);
          path = "h" + num + path;
          total_paths.push_back(path);
      }
  }
  
  //vertical movement
  for(int i=1; i+sr<=dr; ++i){
      vector<string>paths_2 = get_maze_paths(sr+i, sc, dr, dc);
      for(int j=0; j<paths_2.size(); ++j){
          string path = paths_2[j];
          string num = to_string(i);
          path = "v" + num + path;
          total_paths.push_back(path);
      }
  }
  
  //diagonal movement
    for(int i=1; i+sc<=dc && i+sr<=dr; ++i){
      vector<string>paths_3 = get_maze_paths(sr+i, sc+i, dr, dc);
      for(int j=0; j<paths_3.size(); ++j){
          string path = paths_3[j];
          string num = to_string(i);
          path = "d" + num + path;
          total_paths.push_back(path);
      }
  }
  
  return total_paths;
}

void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }

  cout << "]" << endl;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
  display(ans);

  return 0;
}
