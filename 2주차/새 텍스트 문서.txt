//https://inha.codetree.ai/problems/O-mok/description
#include<iostream>
using namespace std;
int grid[19][19];
bool isRange(int x, int y) {
	return (0 <= x && x < 19 && 0 <= y && y < 19);
}
int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (grid[i][j] == 0) {
				// 만일 1이나 2가 아니면 할 필요 없음
				continue;
			}
			int count = 0;
			for (int k = 1; k < 5; k++) {
				// i / j를 기준으로 1 ~ 4까지 진행
				// 가로 파악
				if (!isRange(i, j + k) || grid[i][j] != grid[i][j + k]) {
					// 하려는 대상이 범위에 없고 같지 않다면 비교 필요 없음
					break;
				}
				count++;
			}
			if (count == 4) {
				cout << grid[i][j] << endl;
				cout << i + 1 << ' ' << j + 3;
				return 0;
			}
			count = 0;
			for (int k = 1; k < 5; k++) {
				// i / j를 기준으로 1 ~ 4까지 진행
				// 세로 파악
				if (!isRange(i + k, j) || grid[i][j] != grid[i + k][j]) {
					// 하려는 대상이 범위에 없고 같지 않다면 비교 필요 없음
					break;
				}
				count++;
			}
			if (count == 4) {
				cout << grid[i][j] << endl;
				cout << i + 3 << ' ' << j + 1;
				return 0;
			}
			count = 0;
			for (int k = 1; k < 5; k++) {
				// i / j를 기준으로 1 ~ 4까지 진행
				// 대각선 파악
				if (!isRange(i + k, j + k) || grid[i][j] != grid[i + k][j + k]) {
					// 하려는 대상이 범위에 없고 같지 않다면 비교 필요 없음
					break;
				}
				count++;
			}
			if (count == 4) {
				cout << grid[i][j] << endl;
				cout << i + 3 << ' ' << j + 3;
				return 0;
			}
			count = 0;
			for (int k = 1; k < 5; k++) {
				// i / j를 기준으로 1 ~ 4까지 진행
				// 대각선 파악
				if (!isRange(i-k, j + k) || grid[i][j] != grid[i-k][j + k]) {
					// 하려는 대상이 범위에 없고 같지 않다면 비교 필요 없음
					break;
				}
				count++;
			}
			if (count == 4) {
				cout << grid[i][j] << endl;
				cout << i-1 << ' ' << j + 3;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}