#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        // write your code here
        if(sr == dr && sc == dc){
            cout << psf << endl;
            return;
        }else if(sr > dr || sc > dc){
            return;
        }
        
        
        
        // horizontal movement
        // sc => src point hain
        // uske aagese hi badhenge
        // toh utna offset le lete hain when looping
        // and max Step <= dc hona chahiye
        // wo hmaara dest hain
        // usse aage nahin badhna
         // i+sc can be just put i
        // as we handled in the base case
        // any cases where user goes out of the maze
        for(int i = 1; i+sc<= dc; ++i){
            string step = "h" + to_string(i);
            printMazePaths(sr, sc+i,dr, dc, psf+step);
        }
        
        // vertical movement
        // i+sr can be just put i
        // as we handled in the base case
        // any cases where user goes out of the maze
        for(int i = 1; i+sr<= dr; ++i){
            string step = "v" + to_string(i);
            printMazePaths(sr+i, sc, dr, dc, psf+step);
        }
        
        // diagonal movement
          // i+sr can be just put i
        // as we handled in the base case
        // any cases where user goes out of the maze
          // i+sc can be just put i
        // as we handled in the base case
        // any cases where user goes out of the maze
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
