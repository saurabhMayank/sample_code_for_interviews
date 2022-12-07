
// operators => &, ^, |
int find(string &s,int i ,int j , int istrue){

  if(i>j) return 0;

  if(i ==j )
  {
      if(istrue == 1) return s[i] == 'T';
      else return s[i] == 'F';
  }

  int ans =0;
  for(int k=i+1; k<j;k+=2)
  {
      int lt = find(s,i,k-1,1,dp);
      int lf = find(s,i,k-1,0,dp);
      int rt = find(s,k+1,j,1,dp);
      int rf = find(s,k+1,j,0,dp);


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
  return ans;

}
