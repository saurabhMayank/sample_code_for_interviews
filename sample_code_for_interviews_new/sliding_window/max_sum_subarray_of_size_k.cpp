/**
 * How to calculate size of the window ?
 * Let's say 2 pointer le lete hain (start and end pointer).
 * Calculating the window size (end - start +1)
 * start = i and end = j
**/

// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
int findMaxSumForSubarrayOfSizeK(vector<int> input, int k);

int findMaxSumForSubarrayOfSizeK(vector<int> input, int k){
    int start = 0;
    int end = 0;
    int currCount = 0;
    int maxCount = 0;

    while (end < input.size()){
        // cout << "---window size-----" << (end-start+1) << endl;
        if((end-start+1) <k){
            currCount = currCount + input[end];
            // cout << "----currCount------" << currCount << endl;
            end++;
        } else if((end-start+1) == k){
            if(maxCount < currCount){
                cout << "-----start and end -----" << input[start] << " " << input[end] << " ";
                cout << " curr count=====" << currCount << endl;
                maxCount = currCount;
            }
            currCount = currCount - input[start];
            start++;
            end++;
            currCount = currCount + input[end];
        }
    }

    if(maxCount < currCount){
        maxCount = currCount;
    }
    cout << "----currCount and maxCount-------" << currCount << " " << maxCount;
    cout << endl;
    return maxCount;

}


int main(){
    vector<int>input{2,5,1,8,2,9,1};
    int k = 3;
    int res = findMaxSumForSubarrayOfSizeK(input, k);
    cout << res << endl;
}