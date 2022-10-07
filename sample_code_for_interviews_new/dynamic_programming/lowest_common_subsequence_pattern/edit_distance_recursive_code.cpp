int editDistance(string str1, string str2){
  int n = str1.size();
  int m = str2.size();
  
  return editDistanceRecursiveHelper(n, m , str1, str2);
}

int editDistanceRecursiveHelper(int n, int m, string str1, string str2){
  if(n == 0 && m == 0){
    return 0;
  }else if(n == 0){
    return m;
  }else if (m == 0){
    return n;
  }
  
  if(str1[n-1]== str2[m-1]){
    int operations = editDistanceRecursiveHelper(n-1, m-1, str1, str2);
    return operations
  }else if(str1[n-1]!= str2[m-1]){){
    int op_1 = editDistanceRecursiveHelper(n-1, m, str1, str2);
    
    int op_2 = editDistanceRecursiveHelper(n, m-1, str1, str2);
    
    int op_3 = editDistanceRecursiveHelper(n-1, m-1, str1, str2);
     
    
    return 1 + min(min(op_1, op_2), op_3);
  }
  
  
}
