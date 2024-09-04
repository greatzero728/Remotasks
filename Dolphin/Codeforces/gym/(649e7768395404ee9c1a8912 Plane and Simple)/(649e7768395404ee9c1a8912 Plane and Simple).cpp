#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202;

char s[NN][NN];
bool flag[NN][NN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, k;

vector<pii> vec;

void dfs(int x, int y) {
	vec.push_back({x, y});
	for(int k = 4; k--; ) {
		int u = x + dx[k], v = y + dy[k];
		if(1 <= u && u <= n && 1 <= v && v <= n) {
			if(s[u][v] == 'x' && !flag[u][v]) {
				flag[u][v] = 1, dfs(u, v);
				return;
			}
		}
	}
	return;
}

int calc_dst(pii a, pii b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int solve(int x, int y) {
	flag[x][y] = 1, dfs(x, y);
	int len = vec.size(), d = len / k, ans = 0;
	
	for(; d; d--) {
		int mn = n + n;
		for(int i = len; i--; ) {
			mn = min(mn, calc_dst(vec[i], vec[(i + d) % len]));
		}
		ans = max(ans, mn);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) if(s[i][j] == 'x') {
			printf("%d\n", solve(i, j));
			return 0;
		}
	}
	return 0;
}