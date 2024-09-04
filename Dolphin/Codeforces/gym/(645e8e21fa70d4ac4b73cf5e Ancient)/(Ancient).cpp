#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 22;

char s[NN][NN];
int vst[NN][NN], runs;

bool f;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
	vst[x][y] = runs;
	for(int i = 4; i--; ) {
		int X = x + dx[i], Y = y + dy[i];
		if(X < 0 || X > 8) continue;
		if(Y < 0 || Y > 8) continue;
		if(s[X][Y] == '.') f = 1;
		if(s[X][Y] == 'o' && vst[X][Y] ^ runs) dfs(X, Y);
	}
}

bool die_o() {
	runs++;
	for(int i = 9; i--; ) {
		for(int j = 9; j--; ) if(s[i][j] == 'o') {
			if(vst[i][j] ^ runs) {
				f = 0, dfs(i, j);
				if(!f) return true;
			}
		}
	}
	return false;
}

bool can_catch() {
	for(int i = 9; i--; ) scanf("%s", s + i);
	for(int i = 9; i--; ) {
		for(int j = 9; j--; ) if(s[i][j] == '.') {
			s[i][j] = 'x';
			if(die_o()) return true;
			s[i][j] = '.';
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int t; scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		if(can_catch()) puts("Can kill in one move!!!");
		else puts("Can not kill in one move!!!");
	}
	return 0;
}