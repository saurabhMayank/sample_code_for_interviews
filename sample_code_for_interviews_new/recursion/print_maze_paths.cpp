#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf){
    if(sr == dr && sc == dc){
        cout << psf << endl;
        return;
    } else if(sr > dr || sc > dc){
        return;
    }
    
    // if calls mein hm boundary lagaa de 
    // ki agar sc <= dc tak hi horizontal movement
    // ki calls lage => uske baad na lage => toh kaafi extra recursion calls
    // bach jaaenge negative basecases waale
    printMazePaths(sr, sc+1, dr, dc, psf+"h");
    printMazePaths(sr+1, sc, dr, dc, psf+"v");
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}
