// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    
    vector<int> arr{2, 5, 10, 12, 15};
    int target = 8;
    
    // return the element which has minimum absolute difference
    
    // constraints
    // array is sorted -> yes
    // target may or may not exist in the input
    int low = 0;
    int high = arr.size()-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(arr[mid] == target){
            // min absolute difference will be 0
            return arr[mid];
            
        } else if(arr[mid] > target){
            // shrink to left part
            high = mid-1;
            
        } else if(arr[mid] < target){
            // shrink to right part
            low = mid+1;
            
        }
    }
    
    // at last
    
    // high will point to element just before
    // where actual element could have existed
    // as array is sorted -> this element is a candidate of min
    // absolute difference

    
    pair<int, int>prev_val_diff;
    prev_val_diff.first = abs(arr[high] - target);
    prev_val_diff.second = arr[high];
    
    
    // low will point to element just after where actual element existed
    // this is also candidate of min absolute difference
    pair<int, int> next_val_diff;
    
    next_val_diff.first = abs(arr[low] - target);
    next_val_diff.second = arr[low];
    

    int ans = prev_val_diff.first < next_val_diff.first ? prev_val_diff.second: next_val_diff.second;
    
    cout << ans << endl;

    return ans;
}
