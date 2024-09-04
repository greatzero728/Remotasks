#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7;

int a[10], N;
int mat[13][13], tmp[13][13], ans[13][13];

void mul(int a[13][13], int b[13][13], int c[13][13]) {
	for(int i = N; i--; ) for(int j = N; j--; ) {
		tmp[i][j] = 0;
		for(int k = N; k--; ) {
			tmp[i][j] = (tmp[i][j] + (INT)a[i][k] * b[k][j]) % mod;
		}
	}
	for(int i = N; i--; ) for(int j = N; j--; ) {
		c[i][j] = tmp[i][j];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; INT k;
	scanf("%d %I64d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	
	N = n + 3;
	for(int i = 0; i < N; i++) scanf("%d", mat[0] + i);
	int p = mat[0][n], q = mat[0][n + 1], r = mat[0][n + 2];
	
	for(int i = 1; i < n; i++) mat[i][i - 1] = 1;
	mat[n][n] = 1;
	mat[n + 1][n] = 1, mat[n + 1][n + 1] = 1;
	mat[n + 2][n] = 1, mat[n + 2][n + 1] = 2, mat[n + 2][n + 2] = 1;
	
	for(int i = N; i--; ) {
		for(int j = N; j--; ) ans[i][j] = i == j;
	}
	for(k -= n - 1; k; k >>= 1, mul(mat, mat, mat)) {
		if(k & 1) mul(ans, mat, ans);
	}
	
	int s = 0;
	for(int i = 0; i < n; i++) s = (s + (INT)ans[0][i] * a[n - 1 - i]) % mod;
	s = (s + ans[0][n]) % mod;
	s = (s + (INT)ans[0][n + 1] * n) % mod;
	s = (s + (INT)ans[0][n + 2] * n * n) % mod;
	printf("%d\n", s);
	return 0;
}