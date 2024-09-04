#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 121;

char s[NN][NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, m, q; scanf("%d %d %d", &n, &m, &q);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) s[i][j] = '.';
		}
		while(q--) {
			int imn, jmn; scanf("%d %d", &imn, &jmn);
			int imx, jmx; scanf("%d %d", &imx, &jmx);
			char c; scanf(" %c", &c);
			for(int i = imn; i <= imx; i++) {
				for(int j = jmn; j <= jmx; j++) s[i][j] = c;
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) putchar(s[i][j]);
			puts("");
		}
	}
	return 0;
}
