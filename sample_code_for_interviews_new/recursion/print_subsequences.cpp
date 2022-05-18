void printSubsequences(string input, string output){
  
  // whole input string traversed
  if(input.size() == 0){
    cout << output << endl;
    return;
  }
  
  string s1 = input[0];
  string ros = input.substr(1);
  
  string output_1 = output + s1;
  // yes choice for appending the char
  printSubsequences(ros, output_1);
  // no choice for appending the char
  printSubsequences(ros, output);
  
}
