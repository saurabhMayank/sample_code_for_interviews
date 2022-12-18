//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> mp;
    int countWays(int N, string S){
        int i = 0;
        int j = N-1;
        int isTrue = 1;
        return count_ways_helper(S, i, j, isTrue);
    }
    
    // passing string by reference or it will throw 
    // TLE
    int count_ways_helper(string &s, int i, int j, int istrue){
      if(i>j) return 0;

      if(i ==j)
      {
          if(istrue == 1) return s[i] == 'T';
          else return s[i] == 'F';
      }
      // constructing temp string
      string temp = to_string(i);
      temp.push_back(' ');
      temp = temp +to_string(j);
    //   temp.push_back(to_string(j));
      temp.push_back(' ');
       temp = temp +to_string(istrue);
    //   temp.push_back(to_string(istrue));
      
      if(mp.find(temp)!= mp.end()){
        return mp[temp];
      }
      
      int ans = 0;
      for(int k=i+1; k<j;k+=2)
      {
          int lt = count_ways_helper(s,i,k-1,1);
          int lf = count_ways_helper(s,i,k-1,0);
          int rt = count_ways_helper(s,k+1,j,1);
          int rf = count_ways_helper(s,k+1,j,0);
    
    
          if(s[k] == '&')
          {
              if(istrue == 1) ans = ans + (lt* rt);
              else ans = ans + (lt*rf) + (lf*rt) + (lf*rf);
    
          }
          else if(s[k] == '^')
          {
              if(istrue == 1) ans = ans +  (lt*rf) + (lf*rt);
              else ans = ans +  (lt*rt) + (lf*rf);
    
          }
    
          else if(s[k] == '|')
          {
              if(istrue == 1) ans = ans +  (lt*rt) + (lt*rf) + (lf*rt);
              else ans = ans + (lf*rf);
          }
    
    
      }
      // taking modulo is mentioned in the question
      mp[temp] = ans%1003;
      return mp[temp];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
