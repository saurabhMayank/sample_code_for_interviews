// mcm recursive code

// input -> i and j pointers
// arr => elements containing matrix sizes

arr = [40, 20, 30, 10, 30]

int i = 1;
int j = n-1;

int mcm_recursive(int i , int j , vector<int> arr){
  
  if(i>=j){
    return 0;
  }
   // min value is initialized here rather than globally because 
   // if u carefully observe the recursion code
   // Line 20 is the recursion logic
   // So we will start from valid recursion parameters and keep going into recursion logic till
   // base case is hit
   // So first for mcm_recursive(arr, i, k) -> base case will hit and flow of control will come back to line number 26
   // then for mcm_recursive(arr, k + 1, j) -> base case will hit and flow of control will come back to line number 26
   // after that temp_ans will be calculated -> this temp ans will be compared to min and then returned
   // now the recursive flow of control will again come back to line number 26 in one of the recursion calls
   // So now min will not be initialized again, just its value will keep getting updated
  
  
   int min = Integer.MAX_VALUE;
  for(int k =i; k<=j-1; ++k){
    int temp_ans = mcm_recursive(arr, i, k) + mcm_recursive(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
    if (min > tempAns)
        min = tempAns;
     }
     return min;
  }
}

