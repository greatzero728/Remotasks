#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char s[44][44];
int n, m, sz, vst[55][55];
bool out(int x, int y) {
	return x < 1 || y < 1 || x > n || y > m;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
	vst[x][y] = 1, sz++;
	for(int k = 4; k--; ) {
		int i = x + dx[k], j = y + dy[k];
		if(!out(i, j) && s[i][j] != 'C' && !vst[i][j]) dfs(i, j);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) if(s[i][j] ^ 'C' && !vst[i][j]) {
			vst[i][j] = 1, sz = 0, dfs(i, j);
			if(sz > 1) ans += sz;
		}
	}
	cout<<ans;
	return 0;
}
