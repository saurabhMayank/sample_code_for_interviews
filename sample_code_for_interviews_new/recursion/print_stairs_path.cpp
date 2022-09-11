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
        printStairPaths(n-i, psf+to_string(i), all_paths);
    }
    return;
}

int main(){

    int n;
    cin >> n;
    vector<string> all_paths
    printStairPaths(n, "");
}
