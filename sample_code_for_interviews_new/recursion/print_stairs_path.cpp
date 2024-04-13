#include <iostream>
#include <vector>
using namespace std;

int max_steps = 3;

// BOTTOM UP APPROACH
// single level multiple choices
void printStairPaths(int n, string psf, vector<string> &all_paths){
    
    if(n == 0){
        // destination reached
        // append the path in vector
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


// single level mutliple choices -> levels and options
// storing the options and returning

class Solution {
    // top down code
    // write the code for 1, 2 steps taken from source -> 2 choices
    // will convert the code in 1, 2.. n any number of steps
    // -> multiple choices
public:
    // go from n to 0
    int climbStairs(int n) {
        
        if(n == 0){
            return 1;
        }
        
        
        return climb_stairs_helper(n);
    }
    
    int climb_stairs_helper(int n){
        if(n == 0){
            return 1;
        }
        
        if(n < 0){
            return 0;
        }
        
        // can take any number of steps from 1 to n
        // multiple choice at single level
        
        // at every recursion branch
        // this value will be initialised
        // for a for loop branch -> this value will contain the total sum
        // return to the previous branch in backtracking


        // small explanation of it notes
        
        int final_ans_curr_step = 0;
        
        
        for(int i = 1; i <= 2;  ++i){
            int n_copy = n;
            int curr_ans = climb_stairs_helper(n_copy-i);
            final_ans_curr_step  = final_ans_curr_step +  curr_ans;
        }
        
        return final_ans_curr_step;
        

        
    }
};
