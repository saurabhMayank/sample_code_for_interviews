#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr == dr && sc == dc){
        vector<string> base;
        base.push_back("");
        return base;
    }else if(sr > dr || sc > dc){
        vector<string> base;
        return base;
    }
  
    vector<string> myAns;
  
    vector<string> Horizontal = getMazePaths(sr,sc+1,dr,dc);
    // Horizontal se jitna raste aaye hain
    // uske saamne h lagaa do
    // Euler tree se draw karke dekh lia
    // Tree ke iss node inorder part mein jo Horizontal mein ans aaya hain
    // uske saamne "h" lagaa do
  
    // iss code ko postorder waale portion mein likh sakte the
    // value stored toh thi hi apne pass, iss node ke post order mein bhi
    // h add kar sakte the jo results aaye hain usme
    for(string s : Horizontal){
        myAns.push_back("h" + s);
    }
  
    vector<string> Vertical = getMazePaths(sr + 1,sc,dr,dc);
    // Vertical se jitna raste aaye hain
    // uske saamne v lagaa do
    // Euler tree se draw karke dekh lia
    // Tree ke postorder part mein jo Vertical mein ans aaya hain
    // uske saamne "v" lagaa do
    for(string s : Vertical){
        myAns.push_back("v" + s);
    }
    
    
    return myAns;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
                        
                        
                        
                                
