#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int a[1010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, ans = 0; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	
	for(int i = 0, j = 0; i < n; i = j) {
		for(; j < n && a[i] % 20 == a[j] %20; j++);
		ans = max(ans, j - i);
	}
	printf("%d\n", ans);
	return 0;
}
