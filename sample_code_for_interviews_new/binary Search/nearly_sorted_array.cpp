// ex -> Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2 
// Output is index of 40 in given array

int searchInNearlySortedArray(vector<int> arr, int target){
  
  int low = 0;
  int high = n-1;
  int start = 0;
  int end = n-1;
  
  while(low<=high){
    int mid = low+(high-low)/2;
    
    if(arr[mid] == target){
      return mid;
    }else if((mid-1) > start && arr[mid-1] == target){
      return mid;
    }else if((mid+1) < end && arr[mid+1] == target){
      return mid;
    }else if(target > arr[mid]){
      low = mid+2;
    }else if(target < arr[mid]){
      high = mid-2;
  }
}
