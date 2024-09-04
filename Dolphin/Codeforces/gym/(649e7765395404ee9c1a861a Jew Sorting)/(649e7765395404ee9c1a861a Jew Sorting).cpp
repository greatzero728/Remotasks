#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

#define mid (L + R >> 1)

const int MM = 1 << 21;

int ls[MM], rs[MM], nn;
int mn[MM], mx[MM], mx_len;

int build(int L, int R) {
	int u = nn++;
	if(R - L > 1) {
		ls[u] = build(L, mid);
		rs[u] = build(mid, R);
		if(mn[ls[u]] <= mx[ls[u]] && mx[ls[u]] <= mn[rs[u]] && mn[rs[u]] <= mx[rs[u]]) mn[u] = mn[ls[u]], mx[u] = mx[rs[u]];
		else mn[u] = mx[u] + 1;
	}
	else scanf("%d", mn + u), mx[u] = mn[u];
	if(mn[u] <= mx[u]) mx_len = max(mx_len, R - L);
	return u;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n), n = 1 << n;
	build(0, n);
	printf("%d\n", __builtin_ctz(n / mx_len));
	return 0;
}