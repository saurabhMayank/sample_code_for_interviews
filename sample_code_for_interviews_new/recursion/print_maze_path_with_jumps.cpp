#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        // write your code here
        if(sr == dr && sc == dc){
            cout << psf << endl;
            return;
        }else if(sr > dr || sc > dc){
            // case not allowed
            // sr and sc always be less then dr and dc
            return;
        }
        
        
        
        // horizontal movement
        // sc => src point hain
        // uske aagese hi badhenge
        // toh utna offset le lete hain when looping
        // and max Step <= dc hona chahiye
        // wo hmaara dest hain
        // usse aage nahin badhna
   
        for(int i = 1; i+sc<= dc; ++i){
            string step = "h" + to_string(i);
            printMazePaths(sr, sc+i,dr, dc, psf+step);
        }
        
        // vertical movement
        for(int i = 1; i+sr<= dr; ++i){
            string step = "v" + to_string(i);
            printMazePaths(sr+i, sc, dr, dc, psf+step);
        }
        
        // diagonal movement
        for(int i = 1; i+sc<= dc && i+sr<=dr; ++i){
            string step = "d" + to_string(i);
            printMazePaths(sr+i, sc+i, dr, dc, psf+step);
        }
        
    }

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }
