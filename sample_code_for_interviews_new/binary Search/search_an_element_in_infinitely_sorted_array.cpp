// infinitely sorted arr



// find the bounds
int findPos(vector<int> arr, int target){
  
  int low = 0;
  // smallest possible high
  int high = 1;
  
  int high_val = arr[high];
  
  // increasing the bound
  // making it 2 times in every loop iteration
  
  while(high_val < target){
    // updating low because
    // we want the maximum possible low
    // taaki kam area mein binary search lagaane pade
    // to find target
    low = high;
    // high ko 2(multiplier) times kar rhe hain
    // zyaada bhi kar sakte hain
    // kam bhi kar sakte hain
    // zyaada karenge multiplier toh bound jaldi milega
    // but bada sorted space hoga search karne ke lie
    // agar kam karenge multiplier toh sorted search space
    // ke bounds milne mein time lagega
    // but sorted search space chota hoga
    // That is the tradeoff
    high = 2* high;
    high_val = arr[high]
  }
  
  // normal binary search ka code hoga iss func mein
  return binarySearch(arr, low, high, target);
}

int main(){
  int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                               140, 160, 170.......INF};
    int ans = findPos(arr, 10);
}
