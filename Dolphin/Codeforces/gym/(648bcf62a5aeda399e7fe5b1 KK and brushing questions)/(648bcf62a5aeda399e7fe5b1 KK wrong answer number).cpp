#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

int B[NN], a[NN];

int calc(int u) {
	int ans = 0;
	for(; u; u ^= u & -u) ans += B[u];
	return ans;
}
void update(int u) {
	for(; u < NN; u += u & -u) B[u]++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	int mx = 0, x = 0;
	for(int i = 1; i <= n; i++) {
		x += calc(a[i] - 1) - (i - 1 - calc(a[i]));
		update(a[i]);
		mx = max(mx, x);
	}
	printf("%d %d\n", mx, x);
	return 0;
}
