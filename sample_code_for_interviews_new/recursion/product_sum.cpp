#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)

int productSum(vector<any> array, int multiplier = 1) {
  // Write your code here.
	int sum = 0;
	for(auto el: array) {
		if(el.type() == typeid(vector<any>)){
			sum = sum + productSum(any_cast<vector<any>>(el), multiplier+1);
		} else {
			sum = sum + any_cast<int>(el);
		}
	}
	return sum*multiplier;
}
