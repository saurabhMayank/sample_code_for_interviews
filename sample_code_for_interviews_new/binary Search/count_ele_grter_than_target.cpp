// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> arr{2, 3, 5, 6, 6, 9, 10, 11, 13, 17, 19};
    int target = 6;
    
    // breakpoint concept
    // breakpoint -> last index of 6
    
    int low = 0;
    int high = arr.size()-1;
    
    int last_index = -1;
    
    
    while(low <= high){
        
        int mid = low + (high-low)/2;
        
        if(arr[mid] == target){
            last_index = mid;
            low = mid+1;
            
        } else if(arr[mid] > target){
            high = mid-1;
            
        } else if(arr[mid] < target){
            low = mid+1;
        }
        
    }
    
    int count_of_ele = (arr.size()-1)-last_index;
    
    cout << count_of_ele << endl;
    
    
    return count_of_ele;
    
  
}
