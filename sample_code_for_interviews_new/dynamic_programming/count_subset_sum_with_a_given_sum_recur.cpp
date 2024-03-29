// count subset sum with a given sum
// Top down recursion approach
// working code tested it



   
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int count_subsets_with_a_given_sum(vector<int>arr, int sum, int n){
  if(n==0){
    return 0;
  }
   
  if(sum == 0){
    return 1;
  }
  
  
  if(arr[n-1] > sum){
      
    int not_taken = count_subsets_with_a_given_sum(arr, sum, n-1);
    
    return not_taken;
  } else if(arr[n-1]<= sum){
      
      int taken = count_subsets_with_a_given_sum(arr, sum-arr[n-1], n-1);
      int not_taken = count_subsets_with_a_given_sum(arr, sum, n-1);
      return taken + not_taken; 
  }
  
}

// Driver code
int main()
{
    vector<int> arr = { 2, 3, 5, 6, 8, 10 };
    int n = sizeof(arr) / sizeof(int);
    int x = 10;
 
    cout << count_subsets_with_a_given_sum(arr, x, n);
 
    return 0;
}
