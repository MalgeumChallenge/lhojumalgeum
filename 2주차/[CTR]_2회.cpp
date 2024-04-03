#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> grid(n); 
    for (int i = 0; i < n; i++) {
        cin >> grid[i].first >> grid[i].second;
    }
    int result = INT_MAX;
    int sum1 = 0;
    for (int i = 0; i < n - 1; i++) {
        sum1 += abs(grid[i].first - grid[i + 1].first) + abs(grid[i].second - grid[i + 1].second);
    }
    for (int i = 1; i < n - 1; i++) {
        int original = abs(grid[i].first - grid[i - 1].first) + abs(grid[i].second - grid[i - 1].second) + abs(grid[i].first - grid[i + 1].first) + abs(grid[i].second - grid[i + 1].second);
        int shortcut = abs(grid[i - 1].first - grid[i + 1].first) + abs(grid[i - 1].second - grid[i + 1].second);
        int currentResult = sum1 - original + shortcut;
        result = min(result, currentResult);
    }
    cout << result;
    return 0;
}
