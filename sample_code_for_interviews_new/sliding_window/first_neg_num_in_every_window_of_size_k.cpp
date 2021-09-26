#include <bits/stdc++.h>
using namespace std;

vector<int> first_negative_every_window(vector<int> input, int k, vector<int> res);

vector<int> first_negative_every_window(vector<int> input, int k, vector<int> res) {
    int start = 0;
    int end = 0;
    list<int> temp;
    while(end < input.size()){
        if(input[end] < 0){
            temp.push_back(input[end]);
        }

        if((end-start + 1)< k){
            end++;
        } else if((end-start + 1) == k) {
            if(temp.size() == 0){
                res.push_back(0);
            } else {
                res.push_back(temp.front());
                if(input[start] == temp.front()){
                    temp.pop_front();
                }
            }
           start++;
           end++;
        }
    }
    return res;
}


int main() {
    vector<int>input{12, -1, -7, 8, -15, 30, 18, 28};
    int k = 3;
    vector<int> res;
    // cout << k << endl;
    res = first_negative_every_window(input, k, res);

    for(auto ele:res){
        cout << ele << " ";
    }
    cout << endl;
}