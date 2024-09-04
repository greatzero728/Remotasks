#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

int a[NN][NN], U[NN][NN], R[NN][NN], D[NN][NN], L[NN][NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) scanf("%d", a[i] + j);
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			U[i][j] = max(U[i][j], U[i - 1][j - 1] + a[i][j]);
			U[i][j] = max(U[i][j], U[i - 1][j] + a[i][j]);
			U[i][j] = max(U[i][j], U[i - 1][j + 1] + a[i][j]);
		}
	}
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= m; j++) {
			D[i][j] = max(D[i][j], D[i + 1][j - 1] + a[i][j]);
			D[i][j] = max(D[i][j], D[i + 1][j] + a[i][j]);
			D[i][j] = max(D[i][j], D[i + 1][j + 1] + a[i][j]);
		}
	}
	
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			L[i][j] = max(L[i][j], L[i - 1][j - 1] + a[i][j]);
			L[i][j] = max(L[i][j], L[i][j - 1] + a[i][j]);
			L[i][j] = max(L[i][j], L[i + 1][j - 1] + a[i][j]);
		}
	}
	for(int j = m; j >= 1; j--) {
		for(int i = 1; i <= n; i++) {
			R[i][j] = max(R[i][j], R[i - 1][j + 1] + a[i][j]);
			R[i][j] = max(R[i][j], R[i][j + 1] + a[i][j]);
			R[i][j] = max(R[i][j], R[i + 1][j + 1] + a[i][j]);
		}
	}
	
	int ans = 0;
	for(int i = min(n, m); i >= 1; i--) {
		ans = max(ans, U[i][i] + D[i][i] + L[i][i] + R[i][i] - 2 * a[i][i]);
	}
	printf("%d\n", ans);
}