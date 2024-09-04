#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, x; scanf("%d %d", &n, &x);
		INT ans = (INT)(x + 1) * x >> 1;
		while(n--) {
			int k; scanf("%d", &k);
			if(k <= x) ans -= k << 1;
		}
		printf("%I64d\n", ans);
	}
}
