// ex -> Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2 
// Output is index of 40 in given array

int searchInNearlySortedArray(vector<int> arr, int target){
  int n = arr.size();
 
  int low = 0;
  int high = n-1;
  int start = 0;
  int end = n-1;

  if(n == 1){
    if(arr[0] == target) {
      return 0;
    } else {
      -1;
    }
  }

  if(n == 2){
    if(arr[0] == target){
      return 0;
    } else if(arr[1] == target){
      return 1;
    } else {
      -1;
    }
  }

  // better way to structure code in Binary Search ques

  // Case 0 -> Cover the cases of input_size == 1 and input_size == 2
  // they can be done in constant time without any extra time addition
  // then go inside the while loop

  // Case 1 -> mid can be either of the middle element
  // in that case can compare with current and both left and right element

  // Case 2 -> mid can be the 0th element
  // in that case -> left boundary already reached, compare with current and right(i+1) element

  // Case 3 -> mid can be (n-1)th element
  // in that case -> right boudary already reached, compare with current and left(i-1) element

  // First write the code in this structure and then if needed minimize the code by combining conditions
  // in this way code will be clear and -> u will not miss an edgecase
  
  while(low<=high){
    int mid = low+(high-low)/2;

    if((mid-1) >= 0 && (mid+1) < n){
        if(arr[mid] == target){
            return mid;
        } else if(arr[mid-1] == target){
          return mid;
        } else if(arr[mid+1] == target){
          return mid;
        }
    } else if((mid-1) < 0 && (mid+1) < n) {
        if(arr[mid] == target){
              return mid;
         } else if(arr[mid+1] == target){
          return mid;
        }
    } else if((mid-1) >= 0 && (mid+1) > n) {
        if(arr[mid] == target){
            return mid;
        } else if(arr[mid-1] == target){
          return mid;
        }
    } else if(target > arr[mid]){
      low = mid+2;
    } else if(target < arr[mid]){
      high = mid-2;
    }
}
