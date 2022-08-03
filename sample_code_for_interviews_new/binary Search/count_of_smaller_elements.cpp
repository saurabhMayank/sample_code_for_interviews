int countOfElements(int arr[], int n, int x) {
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
