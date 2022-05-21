#include <iostream>
#include <vector>
using namespace std;

int max_steps = 3;

void printStairPaths(int n, string psf){
    
    if(n == 0){
        cout << psf << endl;
        return;
    }else if(n<0){
        return;
    }
    
    
    for(int i = 1; i<= max_steps; ++i){
        printStairPaths(n-i, psf+to_string(i));
    }
    
    return;
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}
