#include<iostream>
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
      // data is inserted from 1st index
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
        arr[1] = arr[size];
        size--;
        
        // move the current root node to its correct position
        // in the heap based on the heap order of Max heap by swapping
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }else{
                return;
            }
        }
        
    }
}
