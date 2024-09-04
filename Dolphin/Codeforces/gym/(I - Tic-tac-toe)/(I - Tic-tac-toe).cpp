#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int n, m;
char table[maxn][maxn];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
    freopen("tic-tac-toe.in", "r", stdin);
    freopen("tic-tac-toe.out", "w", stdout);
#endif
	
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", table[i]);
    bool found = false;
    for (int sx = 0; sx < n && !found; sx++)
    for (int sy = 0; sy < m && !found; sy++) {
        if (table[sx][sy] == '.')
            continue;
        for (int it = 0; it < 8; it++) {
            int cnt = 0;
            int x = sx, y = sy;
            while (table[x][y] == table[sx][sy]) {
                ++cnt;
                x += dx[it];
                y += dy[it];
                if (x < 0 || x >= n || y < 0 || y >= m)
                    break;
            }
            if (cnt >= 5) {
                found = true;
            }    
        }
    }
    printf("%s\n", found ? "Yes" : "No");
    return 0;
}