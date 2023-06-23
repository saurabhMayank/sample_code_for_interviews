#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
  
    //constructor
    heap{
      arr[0] = -1;
      size = 0;
    }
  
    // max heap
    void insert(int val){
      // data needs to be inserted at last index
      // incrementing the size and then inserting that data at incremented index
      size++;
      int index = size;
      
      // step 1=> inserted at last
      
      arr[index] = val;
      
      // step 2 and step 3
      // comparison from parent and swapping
      while(index >1){
          int parent = index/2; // parent of a node is at (i/2)th index
          if(arr[parent] < arr[index]){
            swap(arr[parent], arr[index]);
            index = parent;
          }else {
            return;
          }
      }
    }
    
    
    //max heap => deletion => root node
    void deleteFromHeap(){
        if(size == 0){
            cout << "nothing to delete" << endl;
            return;
        }
        
        // put last element at index 1
        // instead of swapping the first element from last and deleting the last element
        // put the last element at the 1st index
        arr[1] = arr[size];
        // decrement the last index -> extra element is deleted
        size--;
        
        // move the current root node to its correct position
        // in the heap based on the heap order of Max heap by swapping
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            
            // 1 based indexing mein leftIndex can be equal of size, 0 based indexing mein less hona zaroori hain
            if(leftIndex <= size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }else if(rightIndex <= size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }else{
                return;
            }
        }
    }
    
    void build_maxheap (int Arr[ ]){
        for(int i = N/2 ; i >= 1 ; i-- ){
            heapify (Arr,n, i) ;
        }
    }
    
    void heap_sort(int Arr[ ]){
        int heap_size = N;
        build_maxheap(Arr);
        for(int i = N; i>=2 ; i-- ){
            swap(Arr[ 1 ], Arr[ i ]);
            heap_size = heap_size-1;
            max_heapify(Arr, heap_size, 1);
        }
    }
    
    
    
    // pass elements in this heapify function (n/2 to 0)
    // traverse array to right and pass values in this
    void heapify(int arr, int n, int i){
        //treat every element as largest of that immediate tree
        // aim is to shift this element in the right place
        // if this element is less than its child, we will swap
        int largest = i;

        
        int left = 2*i;
        int right = 2*i + 1;
        
        // 1 based indexing mein leftIndex can be equal of size, 0 based indexing mein less hona zaroori hain
        if(left <= n && arr[largest] < arr[left]){
            largest = left;
        }
        
        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }

        // largest != i -> Initially largest was set to i
        // means it is updated in the above ifs, largest is pointing to the correct position
        // so swap the element with the current ith element
        if(largest !=i){
            // swap elements at largest and i index
            // so element at i index -> goes to largest index
            // element at largest index -> goes to i index
            // now at i -> correct element has come
            // for ex -> In the array -> in the notes
            // swapping 54 and 55. 
            // 54 at index 1
            // 55 at index 3
            // now swapped -> 55 comes at 1, 54 goes at 3
            swap(arr[largest], arr[i]);
            
            // check now ki aur swaps ki zaroorat hain
            // check 54 which is at index 3 is at the right position or does it need more swaps
            // from its children
            heapify(arr, n, largest);
        }
        return;
    }
    
    
    // priority queue implementation below
    
    // max heap
    priority_queue<int> pq;
    
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    
    // it will rearrage elements internally
    // to put max element on top -> done through heap insertion code 
    // TC -> O(logn)
   
    
    
    // syntax for creating min_heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    min_heap.push(4);
    min_heap.push(2);
    min_heap.push(5);
    min_heap.push(3);
    
    // it will rearrage elements internally
    // to put minimum element on top -> done through heap insertion code 
    // TC -> O(logn)
}
