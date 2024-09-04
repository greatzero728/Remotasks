#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, c; scanf("%d %d", &n, &c);
	int ans = 1;
	for(int i = n; i--; ) ans = 6LL * ans % mod;
	for(int i = 0; i < n; i++) ans = (INT)ans * (c - 2 * n - i) % mod;
	printf("%d\n", ans);
	return 0;
}
