
// // r => row size
// // c => col size
// int binaryMedian(int m[][], int r, int c){
//   // find the range
//   // on which binary search is applied
//   // min max values of matrix
//   int min_val = INT_MAX;
//   int max_val = INT_MIN;
  
//   for(int i = 0; i<r; ++i){
//     // min value of all 1st elements of row
//     if(m[i][0] < min_val){
//       min_val = m[i][0];
//     }
//     // max value of all last elements of row
//     if(m[i][c-1] > max_val){
//       max_val = m[i][c-1];
//     }
    
//   }
  
//   // r*c is odd so half => r*c+1/2
//   int half_cnt = ((r*c)+1)/2;
 
  
//   // Binary Search on the range
//   while(min_val < max_val){
//     int mid = min_val + (max_val - min_val)/2;
    
//     // now check count of elements less than mid
//     // as all the rows are sorted in ascending
//     // apply binary search on each row to check
//     // elements less than current mid
//      int count = 0;
//     for(int i = 0; i< r; ++i){
//       // nested binary search and count addition
//       count = count + findEleCountLessThanMid(m[i], mid, c);
//     }
    
//     if(count == half_cnt){
//       return mid;
//     }else if(count > half_cnt){
//       max_val = mid-1;
//     }else if(count < half_cnt){
//       min_val = mid+1;
//     }
// }
  

// int findEleCountLessThanMid(int arr[], int target, int c){
//   int low = 0;
//   int high = c-1;
  
//   while(low <= high){
//     int mid = low + (high-low)/2;
    
//     if(arr[mid] == target){
//       // have to return count;
//       // elements less than
//       // but return element less than current element
//       if(mid >= 0){
//         return mid;
//       }else{
//         return 0;
//       }
//     }
//     else if(arr[mid] < target){
//       low = mid+1;
//     }else if(arr[mid] > target){
//       high = mid-1;
//     }
//   }
  
//   // at last high will be at the element
//   // just before mid
//   if(high >= 0){
//     // high is index
//     // so count is index+1 as index starts from 0
//     // but return element less than current element
//     return high;
//   }else {
//     return 0;
//   }
// }


// int main() {
//     int r = 3, c = 3;
//     int m[][]= { {1,3,5}, {2,6,9}, {3,6,9} };
//     cout << "Median is " << binaryMedian(m, r, c) << endl;
//     return 0;
// }

// my above code will break if the median value has duplicate value

// This code works => Dry run this code for multiple cases => 
// Sample test case , duplicate median and other test cases
// duplicate median test case => vector<vector<int>>m= { {1,3,5}{2,6,9}, {3,6,9}, {4, 7, 8}, {5, 8, 10}};

int lessEqual(vector<vector<int> > &A, int num) {
  int n = A.size();
  int m = A[0].size();
  int cnt=0;
  for(int i=0;i<n;i++) {
      int lo=0,hi=m-1;
      // low < high is done because
      // if low <=high is the condition
      // ye code agar likhenege toh inn dono cases mein aisa ho sakta hain
     // ki high comes before 0
      // mujhe element toh search pe nahin rukna 
      // mujhe toh count karna hain
      // mujhe low and high valid index chahiye
      // at last
      // So conditions like
      // low <=high likhunga => toh low can cross array size
      // uss case mein index out of bounds aa jaayea
      
      while(lo<=hi)
      {
          int middle = lo+(hi-lo)/2;
          if(A[i][middle] <= num)
              lo = middle+1;
          else if(A[i][middle] > num)
              hi = middle-1;
      }
      if(A[i][high] <= num)
          cnt += lo+1;
      else
          cnt += lo;
  }
  return cnt;
}

int findMedian(vector<vector<int> > &A) {
int n = A.size();
int m = A[0].size();
int k = (n*m)/2;
int l=INT_MAX,r=INT_MIN;
for(int i=0;i<n;i++)
{
    l = min(l, A[i][0]);
    r = max(r, A[i][m-1]);
}
  while(l<=r)
  {
      int mid = l+(r-l)/2;
      int cnt = lessEqual(A,mid);
      if (cnt == k){
        return mid;
      }
      else if(cnt > k)
          r = mid-1;
      else if(cnt < k)
          l = mid+1;
  }
  
}ˇ
