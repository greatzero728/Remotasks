#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

char c[NN];
int x[NN], B[NN], nn = 1, nb;
int L[NN], R[NN], pos[NN];

void update(int u, int x) {
	for(; u <= nb; u += u & -u) B[u] += x;
}
int calc(int u) {
	int ans = 0;
	for(; u; u ^= u & -u) ans += B[u];
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int n; scanf("%d %*c", &n);
	R[0] = 1, R[1] = n + 1;
	L[1] = 0, R[n + 1] = 1;
	int st = 1;
	for(int i = 2; i <= n; i++) {
		scanf(" %c", c + i);
		if(c[i] == 'O') {
			scanf("%d", x + i);
			if(R[x[i]] > n) st = R[0];
			else st = R[x[i]];
		}
		else {
			int a = L[st], b = st;
			R[a] = ++nn, R[nn] = b;
			L[nn] = a, L[b] = nn;
			if(c[i] == 'F') st = nn;
		}
	}
	
	nn = 0;
	for(int u = R[0]; u <= n; u = R[u]) {
		pos[u] = ++nn;
	}
	nb = nn;
	
	update(pos[1], 1), nn = st = 1;
	R[0] = 1, R[1] = n + 1;
	L[1] = 0, R[n + 1] = 1;
	for(int i = 2, num = 1; i <= n; i++) {
		if(c[i] == 'O') {
			update(pos[x[i]], -1), num--;
			
			int Lnum;
			if(pos[st] < pos[x[i]]) Lnum = calc(pos[x[i]] - 1) - calc(pos[st] - 1);
			else Lnum = num - calc(pos[st] - 1) + calc(pos[x[i]] - 1);
			
			printf("%d\n", min(Lnum, num - Lnum));
			
			if(R[x[i]] > n) st = R[0];
			else st = R[x[i]];
		}
		else {
			int a = L[st], b = st;
			R[a] = ++nn, R[nn] = b;
			L[nn] = a, L[b] = nn;
			if(c[i] == 'F') st = nn;
			update(pos[nn], 1), num++;
		}
	}
	return 0;
}