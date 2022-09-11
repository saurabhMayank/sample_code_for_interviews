#include <iostream>
#include <vector>
using namespace std;

int max_steps = 3;

// BOTTOM UP APPROACH

void printStairPaths(int n, string psf, vector<string> &all_paths){
    
    if(n == 0){
        cout << psf << endl;
        all_paths.push_back(psf)
        return;
    }else if(n<0){
        return;
    }
    
    
    for(int i = 1; i<= max_steps; ++i){
        string paths_1 = psf+to_string(i);
        printStairPaths(n-i, paths_1, all_paths);
    }
    return;
}

int main(){

    int n;
    cin >> n;
    vector<string> all_paths
    printStairPaths(n, "", all_paths);
}
