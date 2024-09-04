#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

vector<pii> vec;

bool flag[NN][NN], vst[NN][NN], shut[NN][NN];
int n, m, pass_num;

using ppp = pair<pii, pii>;
vector<ppp> ship[NN][NN];

bool can_shoot(int x, int y) {
	for(ppp p : ship[x][y]) {
		bool ok = 1; int cnt = 0;
		for(int i = p.x.x; i <= p.x.y; i++) {
			for(int j = p.y.x; j <= p.y.y; j++) if(x != i || y != j) {
				if(vst[i][j]) ok = 0;
				if(flag[i][j] && shut[i][j]) cnt++;
			}
		}
		if(cnt == pass_num && ok) return 1;
	}
	return 0;
}

int calc() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			vst[i][j] = shut[i][j] = 0;
		}
	}
	
	int num = pass_num = 0;
	for(pii p : vec) {
		int x = p.x, y = p.y;
		if(flag[x][y]) {
			shut[x][y] = 1;
			num++, pass_num++;
		}
		else {
			if(can_shoot(x, y)) num++;
			vst[x][y] = 1;
		}
		
		if(pass_num == 4) return num;
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%d %d", &n, &m);
	for(int i = n * m; i--; ) {
		char a, b; scanf(" %c %c", &a, &b);
		vec.push_back({a - 'a' + 1, b - '0'});
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(i >= 4) {
				for(int k = 4; k--; ) {
					ship[i - k][j].push_back({{i - 3, i}, {j, j}});
				}
			}
			if(j >= 4) {
				for(int k = 4; k--; ) {
					ship[i][j - k].push_back({{i, i}, {j - 3, j}});
				}
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(i >= 4) {
				for(int k = 4; k--; ) flag[i - k][j] = 1;
				ans = max(ans, calc());
				for(int k = 4; k--; ) flag[i - k][j] = 0;
			}
			if(j >= 4) {
				for(int k = 4; k--; ) flag[i][j - k] = 1;
				ans = max(ans, calc());
				for(int k = 4; k--; ) flag[i][j - k] = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}