#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 3030;

int n, m, imn, imx, jmn, jmx;
int x, y, z, d;

char s[NN][NN], a[NN][NN];

void init() {
	x = y = z = d = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) a[i][j] = '.';
	}
	return;
}

void fill(int imn, int jmn, int in, int jn) {
	for(int i = in; i--; ) for(int j = jn; j--; ) {
		if(imn + i > n) return;
		if(jmn + j > m) return;
		a[imn + i][jmn + j] = 'x';
	}
	return;
}

bool check() {
	for(int i = imn; i <= imx; i++) for(int j = jmn; j <= jmx; j++) {
		if(s[i][j] ^ a[i][j]) return 0;
	}
	return 1;
}

bool H() {
	init();
	for(int i = jmn, j = i; i <= jmx; i = j) {
		for(; j <= jmx && s[imn][i] == s[imn][j]; j++);
		if(s[imn][i] == 'x') d = j - i;
		else z = j - i;
	}
	if(!d || !z) return 0;
	
	for(int i = imn, j = i; i <= imx; i = j) {
		for(; j <= imx && s[i][jmn + d] == s[j][jmn + d]; j++);
		if(s[i][jmn + d] == '.') y = j - i;
	}
	if(!y) return 0;
	x = imx - imn + 1 - d - y;
	if(x <= 0) return 0;
	
	fill(imn, jmn, x + d + y, d);
	fill(imn, jmx - d + 1, x + d + y, d);
	fill(imn + x, jmn  + d, d, z);
	
	return check();
}

bool S() {
	init();
	int nn = 0;
	for(int i = imn, j = i; i <= imx; i = j) {
		for(; j <= imx && s[i][jmn] == s[j][jmn]; j++);
		if(s[i][jmn] == 'x') d = j - i;
		else y = j - i;
	}
	if(!d || !y) return 0;
	
	x = imx - imn + 1 - 3 * d - y;
	if(x <= 0) return 0;
	
	z = jmx - jmn + 1 - d;
	if(z <= 0) return 0;
	
	fill(imn, jmn, d, d + z);
	fill(imn + d, jmn, x, d);
	fill(imn + d + x, jmn, d, d + z);
	fill(imx - d - y + 1, jmn + z, y, d);
	fill(imx - d + 1, jmn, d, z + d);
	
	return check();
}

bool U() {
	init();
	for(int i = jmn, j = i; i <= jmx; i = j) {
		for(; j <= jmx && s[imn][i] == s[imn][j]; j++);
		if(s[imn][i] == 'x') d = j - i;
		else y = j - i;
	}
	if(!d || !y) return 0;
	
	x = imx - imn + 1 - d;
	if(x <= 0) return 0;
	
	fill(imn, jmn, x + d, d);
	fill(imn, jmx - d + 1, x + d, d);
	fill(imn + x, jmn + d, d, y);
	
	return check();
}

bool T() {
	init();
	for(int i = imn, j = i; i <= imx; i = j) {
		for(; j <= imx && s[i][jmn] == s[j][jmn]; j++);
		if(s[i][jmn] == 'x') d = j - i;
		else z = j - i;
	}
	if(!d || !z) return 0;
	
	for(int i = jmn, j = i; i <= jmx; i = j) {
		for(; j <= jmx && s[imx][i] == s[imx][j]; j++);
		if(s[imx][i] == '.') y = j - i;
	}
	if(!y) return 0;
	
	x = jmx - jmn + 1 - d - y;
	if(x <= 0) return 0;
	
	fill(imn, jmn, d, x + d + y);
	fill(imn + d, jmn + x, z, d);
	
	return check();
}

int solve() {
	scanf("%d %d", &n, &m);
	imn = jmn = NN, imx = jmx = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; j++) if(s[i][j] == 'x') {
			imn = min(imn, i), jmn = min(jmn, j);
			imx = max(imx, i), jmx = max(jmx, j);
		}
	}
	
	if(!imx) return puts("OOPS!");
	if(H()) return puts("H");
	if(S()) return puts("S");
	if(U()) return puts("U");
	if(T()) return puts("T");
	return puts("OOPS!");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}