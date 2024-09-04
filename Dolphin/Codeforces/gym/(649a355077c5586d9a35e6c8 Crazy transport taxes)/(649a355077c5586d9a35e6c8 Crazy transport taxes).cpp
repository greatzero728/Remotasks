#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

int a[NN], b[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d %d", a + i, b + i);
	
	int m; scanf("%d", &m);
	while(m--) {
		int x; scanf("%d", &x);
		int id = lower_bound(a + 1, a + n + 1, x) - a - 1;
		printf("%I64d\n", (INT)b[id] * x);
	}
	return 0;
}