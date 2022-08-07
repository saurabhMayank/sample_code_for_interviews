// failing for test cases
// {{1,1,3,3,3,3,3}}

int countOfElementsLessEqual(vector<int> &arr, int x);
int countOfElementsLessEqual(vector<int> &arr, int x) {
     int n = arr.size();
     int low = 0;
     int high = n-1;
     
     while(low <= high){
         int mid = low + (high -low)/2;
         if(arr[mid] <= x){
             low = mid+1;
         }else if(arr[mid] > x){
             high = mid-1;
         }
     }
     
     if(high >= 0){
         return high+1;
     }else if(arr[low] <= x){
         return low+1;
     } else {
         return 0;
     }
    
}

int Solution::findMedian(vector<vector<int> > &A) {
  int n = A.size(); // row size
  int m = A[0].size(); // col size
  
  int min = INT_MAX;
  int max = INT_MIN;
  
  // updating min and max with min and max in the 
  // matrix
  for(int i = 0; i<n; ++i){
    if(min > A[i][0]){
      min = A[i][0];
    }
    if(max < A[i][m-1]){
      max = A[i][m-1];
    }
  }
  
  int k = (n*m+1)/2;
  cout << min << "----->" << max << "------->" << k << endl;
  cout << "----start of while loop" << endl;
  cout << "\n";
  
  while(min <= max){
    int mid = min + (max-min)/2;
    
    int countLessEqual = 0;
    for(int i = 0; i< n; ++i){
      countLessEqual = countLessEqual + countOfElementsLessEqual(A[i], mid);
    }
    
    cout << mid << "------>" << countLessEqual << endl;
    
    cout << "-----end if iteration-----" << endl;
    if(countLessEqual == k){
      cout << "--mid to be returned---" << mid << endl;
      return mid;
    } else if(countLessEqual > k){
      max = mid-1;
    } else if (countLessEqual < k){
      min = mid+1;
    }
  
  }
  
}
