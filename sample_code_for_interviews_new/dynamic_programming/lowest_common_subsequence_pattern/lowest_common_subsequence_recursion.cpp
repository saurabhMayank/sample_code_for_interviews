// recursion code
// LCS
// return the length of longest common

int LCS(string X, string Y, int n, int m){
  // base case
  if(n == 0 || m == 0){
    return 0; // Length of LCS will be 0 when both strings empty
  }
  
  if(X[n-1] == Y[m-1]){ // MATCH FOUND
    int count = LCS(X, Y, n-1, m-1); // retreving the count => calling it on n-1, m-1 as match found => both characters considered processed
    count = count + 1; // added to current count to increment it, as match found, LCS count increases
    return count;
    
  } else if(X[n-1] != Y[m-1]) {// AS match not found
    //=>  A small concept explained here => to demonstrate how to shorten inputs
    // let's say X => abcdf, Y => abefg => Here f != g => But if we discard last chars of both strings => and call LCS on n-1, m-1
    // => f matching is missed => So in reality LCS = abf but if we discard both last chars on match not found => then LCS = ab (which is wrong)
    //=> So to avoid that corner case
   // => If X[n-1] != Y[m-1]
   // => call 1 = LCS(X, Y, n, m-1) and call 2 = LCS(X, Y, n-1, m) => In this way => all corner cases covered.
   // => max(call 1 , call 2) => because Longest common sub sequence needed => max of both choices
    
    int count_1 = LCS(X, Y, n, m-1); 
    int count_2 = LCS(X, Y, n-1, m);
    
    return max(count_1, count_2);
  }
  
  
}
