#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 102, mod = 1e9 + 7;

int mat[NN][NN], ans[NN][NN], tmp[NN][NN], n;

void mul(int a[NN][NN], int b[NN][NN], int c[NN][NN]) {
	for(int i = n; i--; ) for(int j = n; j--; ) {
		tmp[i][j] = 0;
		for(int k = n; k--; ) {
			tmp[i][j] = (tmp[i][j] + (INT)a[i][k] * b[k][j]) % mod;
		}
	}
	for(int i = n; i--; ) for(int j = n; j--; ) c[i][j] = tmp[i][j];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int m, k; scanf("%d %d %d", &n, &m, &k);
	while(m--) {
		int u, v; scanf("%d %d", &u, &v);
		mat[u - 1][v - 1] = 1;
	}
	
	for(int i = n; i--; ) {
		for(int j = n; j--; ) ans[i][j] = i == j;
	}
	for(; k; k >>= 1, mul(mat, mat, mat)) {
		if(k & 1) mul(ans, mat, ans);
	}
	
	int s = 0;
	for(int i = n; i--; ) for(int j = n; j--; ) {
		s = (s + ans[i][j]) % mod;
	}
	printf("%d\n", s);
	return 0;
}
