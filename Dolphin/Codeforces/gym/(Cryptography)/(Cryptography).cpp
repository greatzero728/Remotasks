#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int mod, N;

const int NN = 30303;

int p[NN][2][2], pre[NN][2][2], tmp[2][2];

void init(int a[2][2]) {
	for(int i = 2; i--; ) {
		for(int j = 2; j--; ) a[i][j] = i == j;
	}
}
void mul(int a[2][2], int b[2][2], int c[2][2]) {
	for(int i = 2; i--; ) for(int j = 2; j--; ) {
		tmp[i][j] = 0;
		for(int k = 2; k--; ) tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
	}
	for(int i = 2; i--; ) for(int j = 2; j--; ) c[i][j] = tmp[i][j];
}

int ans[2][2];

void print(int a[2][2]) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) printf("%d ", a[i][j]);
		puts("");
	}
	puts("");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("crypto.in", "r", stdin);
	freopen("crypto.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d %d", &mod, &n, &m);
	for(int k = 1; k <= n; k++) {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) scanf("%d", p[k][i] + j);
		}
	}
	
	N = sqrt(n);
	for(int I = 1, J = 1; I <= n; I = J) {
		init(pre[I / N]);
		for(; J <= n && I / N == J / N; J++) mul(pre[I / N], p[J], pre[I / N]);
	}
	
	while(m--) {
		int L, R; scanf("%d %d", &L, &R);
		int st = L / N, ed = R / N;
		
		init(ans);
		if(st == ed) {
			for(int i = L; i <= R; i++) mul(ans, p[i], ans);
		}
		else {
			for(int i = L; i < (st + 1) * N; i++) mul(ans, p[i], ans);
			for(int i = st + 1; i < ed; i++) mul(ans, pre[i], ans);
			for(int i = ed * N; i <= R; i++) mul(ans, p[i], ans);
		}
		print(ans);
	}
	return 0;
}
