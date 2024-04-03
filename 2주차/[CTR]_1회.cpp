//https://inha.codetree.ai/missions/5/problems/awkward-digits-2/description
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
	string input;
	cin >> input;
	int sum = 0;
	bool change=0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '0') {
			input[i] = '1';
			change=1;
			break;
		}
	}
	if(!change){
		input[input.length()-1]='0';
	}
	for (int i = 0; i < input.length(); i++) {
		int num = input.length() - i - 1;
		if (input[i] == '1') {
            sum += static_cast<int>(pow(2, num));
		}
	}
	cout << sum;
	return 0;
}