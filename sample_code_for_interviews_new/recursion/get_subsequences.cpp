// get subsequence
vector<string> subsequences;

// idx => 0 at start
idx = 0;

getSubsequences(word, subsequences, idx);

string temp1 = ""
subsequences.push_back(temp1);

void getSubsequences(string word, vector<string> &subsequences, int idx){
    //base case - version -1
    
    if(idx == word.size()-1){
        subsequences.push_back(word[idx]);
        return;
    }
    
    
    // faith
    getSubsequences(word, subsequences, idx+1);
    subsequences.push_back()
    
    //link faith and expectation
    for(int i =0; i<subsequences.size(); ++i){
        string curr_word = subsequences[i];
        string front_char = word[idx];
        string temp = front_char + curr_word;
        subsequences.push_back(temp);
        subsequences.push_back(front_char);
    }
    
    return;
}
