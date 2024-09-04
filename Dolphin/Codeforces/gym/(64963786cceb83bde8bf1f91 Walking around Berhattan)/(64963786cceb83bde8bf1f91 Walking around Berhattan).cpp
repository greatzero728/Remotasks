#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 212;

int b[NN][NN];
bool flag[NN][NN];
char s[505];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 2; i <= 2 * n; i += 2) {
		for(int j = 2; j <= 2 * m; j += 2) {
			scanf("%1d", b[i] + j), flag[i][j] = 0;
		}
	}
	scanf("%s", s);
	
	int x = 1, y = 1, dir = 0, ans = 0;
	for(int i = 0; s[i]; i++) {
		if(s[i] == 'M') {
			x += dx[dir], y += dy[dir];
			for(int k = 4, X, Y; k--; ) {
				X = x + dx[k], Y = y + dy[k];
				if(flag[X][Y]) ans += b[X][Y] >> 1;
				else ans += b[X][Y], flag[X][Y] = 1;
			}
			x += dx[dir], y += dy[dir];
		}
		else if(s[i] == 'L') dir = (dir + 1) & 3;
		else dir = (dir + 3) & 3;
	}
	printf("%d\n", ans);
	return 0;
}