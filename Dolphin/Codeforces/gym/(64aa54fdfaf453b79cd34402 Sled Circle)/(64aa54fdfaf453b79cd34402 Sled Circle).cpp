#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

int v[NN], p[NN];

bool same(int n) {
	for(int i = n; i--; ) if(p[i] ^ p[0]) {
		return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", v + i);
	
	if(n == 1) puts("0 0"), exit(0);
	for(int t = 1; t <= 1001; t++) {
		for(int i = n; i--; ) p[i] = (i + v[i] * t) % n;
		if(same(n)) {
			printf("%d %d\n", t, p[0]);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
