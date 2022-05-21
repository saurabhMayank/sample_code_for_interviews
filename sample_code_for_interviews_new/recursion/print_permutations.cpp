#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.size() == 0){
        cout << asf << endl;
        return;
    }
    
    for(int i =0; i< str.size(); ++i){
        char curr_char = str[i];
        string rest_of_string = str.substr(0,i)+ str.substr(i+1, str.size());
        printPermutations(rest_of_string, asf + curr_char);
    }

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}
