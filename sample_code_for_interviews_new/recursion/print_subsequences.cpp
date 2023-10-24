//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string> res;
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    if(s.size() == 0){
		        return res;
		    }
		    
		    if(s.size() == 1){
		       res.push_back(s);
		       return res;
		    }
		    
		    int index = 0;
		    string curr = "";
		    substring_helper(s, curr, index);
		    
		    // sorting because sorted order required
		    sort(res.begin(), res.end());
		    
		    return res;
		    
		}
		
		void substring_helper(string s, string curr, int index){
		    if(index == s.size()){
		        if(curr.size() > 0){
		           res.push_back(curr); 
		        }
		        
		        return;
		    }
		    
		    // index points to the character
		    // on which the option is decided whether to choose or not

        // No need to copy s string as index used
		    char curr_char = s[index];
		    
		    // choice 1
		    //choose the curr_char
		    string curr_copy_1 = curr;
		    curr_copy_1.push_back(curr_char);
		    int index_copy = index;
		    
		    // index_copy+1 => move to the next level
		    substring_helper(s, curr_copy_1, index_copy+1);
		    
		    // choice 2
		    // not choose
		    //choose the curr_char
		    string curr_copy_2 = curr;
		    int index_copy_1 = index;
		    
		    // index_copy+1 => move to the next level
		    substring_helper(s, curr_copy_2, index_copy_1+1);
		    
		    return;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
