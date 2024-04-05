//https://inha.codetree.ai/missions/5/problems/escaping-carry-2/submissions
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasCarry(int a, int b, int c) {
    while (a > 0 || b > 0 || c > 0) {
        int lastDigitA = a % 10;
        int lastDigitB = b % 10;
        int lastDigitC = c % 10;
        if (lastDigitA + lastDigitB + lastDigitC >= 10) {
            return true;
        }
        a /= 10;
        b /= 10;
        c /= 10;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int result = -1;
    for (int f = 0; f < n; f++) {
        for (int s = f + 1; s < n; s++) {
            for (int t = s + 1; t < n; t++) {
                if (!hasCarry(grid[f], grid[s], grid[t])) {
                    int sum = grid[f] + grid[s] + grid[t];
                    result = max(result, sum);
                }
            }
        }
    }

    cout << result << endl;
    return 0;
}
