//https://inha.codetree.ai/problems/interesting-numbers/description
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	int result = 0;
	for (int i = x; i < y + 1; i++) {
		int count = 0;
		vector<char> arr;
		string input = to_string(i);
		for (int k = 0; k < input.size(); k++) {
			// change arr to vector
			arr.push_back(input[k]);
		}
		sort(arr.begin(), arr.end());
		for (int k = 0; k < input.size()-1; k++) {
			if (arr[k] != arr[k + 1]) {
				count++;
			}
		}
		if (count == 1) {
			if (arr[0] != arr[1]) {
				result++;
			}
			else if (arr[input.size() - 2] != arr[input.size() - 1]) {
				result++;
			}
		}
		

		
	}
	cout << result;
	return 0;
}