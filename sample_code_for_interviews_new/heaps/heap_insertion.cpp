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
}
