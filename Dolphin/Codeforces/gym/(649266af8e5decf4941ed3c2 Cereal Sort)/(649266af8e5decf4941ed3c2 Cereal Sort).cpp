#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010101;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1, [&](int u, int v) {
		return u > v;
	});
	
	INT ans = 0;
	for(int i = 1, j = 1; i <= n; i = j) {
		for(; j <= n && a[i] == a[j]; j++);
		ans += j - 1;
	}
	printf("%I64d\n", ans);
	return 0;
}
