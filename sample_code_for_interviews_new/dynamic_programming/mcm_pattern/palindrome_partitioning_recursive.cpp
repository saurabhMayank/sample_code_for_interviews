// find the minimum number of cuts
// to paritition the string so that each partition 
// is a palindrome

// whole agenda is to find the cuts in the string that will form a palindromic partition

// i and j represent the left and right boundary of string s here


// Intution in the notes

int palindrome_partitioning(string s, int i, int j){
  
  // if string is empty => No cut needed => (i>j)
  // or if string size == 1 (i==j) => It is itself a palindrome => No cut needed to make a palindrome.
  
  if(i>=j){
    return 0;
  }
  
  // if the string s is palindrome then also
  // no cuts needed in it to make it a palindrome
  if(is_palindrome(s, i, j)){
    return 0;
  }
  
  int min_cut = INT_MAX;
  for(int k = i; k<=j-1; ++k){
    // partition the string from (i to k) and (k+1 to j)
    // each partition mein find karo kitne minimum cuts chahiye
    // that will make each parition a palindrome
    
    // temp_ans will contain min number of cuts for the paritition K = i
    // in one iteration of all the loop
    
    // This loop will find temp_ans for partition K = i to j-1
    // Usme se jo min temp_ans hoga wahi min cuts hoga
    
    // Now hmne jab current string mein paritition kia current string ka ek cut hua
    // so current partition ka ek cut => Last mein add kar denge
    
    
    int temp_ans = palindrome_partitioning(s, i , k) + palindrome_partitioning(s, k+1, j) + 1;
    
    min_cut = min(min_cut, temp_ans);
     
  }
  
  return min_cut;
  
  
}
     
bool is_palindrome(string s, int i, int j){
  int start = i;
  int end = j;

  while(start <= end){
      if(s[start] == s[end]){
          start++;
          end--;
      }else{
          return false;
      }
  }

  return true;
}
