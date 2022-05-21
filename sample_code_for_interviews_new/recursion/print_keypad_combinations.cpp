#include <iostream>
# include<vector>
using namespace std;

vector<string> keypad = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string input, string output){
    
    if(input.size() == 0){
        cout << output << endl;
        return;
    }
    
    
    char digit = input[0];
    string rest_of_digits = input.substr(1);
    string curr_digit_letters = keypad[digit-'0'];
    
    for(int i = 0; i< curr_digit_letters.size(); ++i){
        printKPC(rest_of_digits, output+ curr_digit_letters[i]);
    }
    return;
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}
