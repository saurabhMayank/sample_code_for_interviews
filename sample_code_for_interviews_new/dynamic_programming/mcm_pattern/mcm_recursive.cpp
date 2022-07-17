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
   int min = Integer.MAX_VALUE;
  for(int k =i; k<=j-1; ++k){
    int temp_ans = mcm_recursive(arr, i, k) + mcm_recursive(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
    if (min > tempAns)
        min = tempAns;
     }
     return min;
  }
}

