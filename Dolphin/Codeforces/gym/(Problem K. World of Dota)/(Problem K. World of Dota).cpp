#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int NN = 19;

//#define NR 273
//#define NC 1093

#define NR 101010
#define NC 1010101

char s[NN][NN];
int id[NN][NN], n, mn = NC;
pii pos[NR];

struct Dl {
	bool h[NC];
	int L[NC], R[NC], U[NC], D[NC], sz;
	int C[NC], X[NC], S[NC], H[NR], O[NR], ans, I[NR];
	int c() {
		int s = 0, c = R[0], i, j;
		while(c) h[c] = 1, c = R[c];
		for(c = R[0]; c; c = R[c]) if(h[c])
		for(h[c] = 0, s++, i = D[c]; i ^ c; i = D[i])
		for(j = R[i]; j ^ i; j = R[j]) h[C[j]] = 0;
		return s;
	}
	void d(int c) {
		int i = D[c];
		while(i ^ c) R[L[R[i]] = L[i]] = R[i], S[C[i]]--, i = D[i];
	}
	void g(int c) {
		int i = U[c];
		while(i ^ c) S[C[L[R[i]] = R[L[i]] = i]]++, i = U[i];
	}
	int dfs(int k = 0) {
		if(k + c() >= ans) return 0;
		if(!R[0]) {
			if(k < mn) {
				for(int i = k; i--; ) I[i] = O[i];
				mn = k;
			}
			return ans = k;
		}
		int c = R[0], i = c, j;
		for(; i; i = R[i]) if(S[i] < S[c]) c = i;
		for(i = D[c]; i ^ c; i = D[i]) {
			for(d(i), O[k] = X[i], j = R[i]; j ^ i; j = R[j]) d(j); dfs(k + 1);
			for(j = L[i]; j ^ i; j = L[j]) g(j); g(i);
		}
		return 0;
	}
	void insert(int x, int y) {
		S[C[sz] = y]++;
		X[U[D[sz] = D[y]] = sz] = x, U[D[y] = sz] = y;
		if(~(y = H[x])) R[L[sz] = L[y]] = sz, R[L[y] = sz] = y;
		else H[x] = L[sz] = R[sz] = sz; sz++;
	}
	void init(int n, int m) {
		while(H[n] = -1, --n);
		while(n <= m) L[n] = n - 1, R[U[n] = D[n] = n] = n + 1, S[n++] = 0;
		L[R[m] = 0] = m, sz = m + 1, ans = NR;
	}
} dl;

void print() {
	for(int i = 1; i <= n; i++) puts(s[i] + 1);
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	
	int nr = 0, nc = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) if(s[i][j] == '.') {
			int cnt = 0;
			for(int k = 4; k--; ) {
				int x = i + dx[k], y = j + dy[k];
				if(s[x][y] == '.') cnt++;
			}
			id[i][j] = ++nr, pos[nr] = {i, j};
			if(cnt == 4) nc++;
		}
	}
	if(!nc) print();
	
	dl.init(nr, nc), nc = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) if(s[i][j] == '.') {
			int cnt = 0;
			for(int k = 4; k--; ) {
				int x = i + dx[k], y = j + dy[k];
				if(s[x][y] == '.') cnt++;
			}
			if(cnt == 4) {
				dl.insert(id[i][j], ++nc);
				for(int k = 4; k--; ) {
					int x = i + dx[k], y = j + dy[k];
					dl.insert(id[x][y], nc);
				}
			}
		}
	}
	dl.dfs();
	while(mn--) {
		int i = dl.I[mn];
		s[pos[i].x][pos[i].y] = '+';
	}
	
	print();
	return 0;
}