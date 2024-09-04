#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 505;

char s[NN][NN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) if(s[i][j] == 'C') {
			for(int k = 4; k--; ) {
				int x = i + dx[k], y = j + dy[k];
				if(s[x][y] == 'R') puts("No"), exit(0);
			}
		}
	}
	puts("Yes");
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == '.') s[i][j] = '#';
			putchar(s[i][j]);
		}
		puts("");
	}
	return 0;
}
