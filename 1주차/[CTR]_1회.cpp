// https://inha.codetree.ai/missions/5/problems/snail-alphabet-square/description
#include <iostream>
using namespace std;

char grid[101][101] = {};
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int n, m;
bool range(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}
int main() {
    cin >> n >> m;
    int dir = 0;
    int r = 0;
    int c = 0;
    char C = 'A';

    for (int i = 0; i < n * m; i++) {
        // next 위치 확인
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (!range(nr, nc) || grid[nr][nc] != 0) {
            // 확인 후 방향 바꾸기
            dir = (dir + 1) % 4;
        }
        grid[r][c] = C;
        C++;
        if (C > 'Z') {
            C = 'A';
        }
        r += dr[dir];
        c += dc[dir];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}