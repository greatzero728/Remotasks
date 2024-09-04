#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 212;

char s[NN][NN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	for(int i = NN; i--; ) {
		for(int j = NN; j--; ) s[i][j] = '.';
	}
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, m, b, w; scanf("%d %d %d %d", &n, &m, &b, &w);
		n <<= 2, m <<= 2;
		
		for(int i = 2; i <= m && b; i += 2) {
			if(i > 2) s[2][i - 1] = 'W', w--;
			s[2][i] = 'B', b--;
		}
		for(int j = 2; j < m && b; j += 4) {
			for(int i = 4; i < n && b; i += 2) {
				s[i][j] = 'B', b--;
				s[i - 1][j] = 'W', w--;
			}
		}
		
		for(int i = 1; i < n && w; i++) {
			for(int j = 1; j < m && w; j++) if((i + j) & 1 && s[i][j] == '.') {
				for(int k = 4; k--; ) {
					int x = i + dx[k], y = j + dy[k];
					if(s[x][y] == 'B') {
						s[i][j] = 'W', w--;
						break;
					}
				}
			}
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) putchar(s[i][j]), s[i][j] = '.';
			puts("");
		}
	}
	return 0;
}