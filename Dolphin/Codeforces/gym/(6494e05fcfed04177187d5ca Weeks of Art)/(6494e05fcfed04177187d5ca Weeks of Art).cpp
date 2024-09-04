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
	
	INT n; scanf("%I64d", &n);
	
	int ans = 0;
	for(INT i = cbrt(n); i; i--) {
		INT x = n - i * i * i;
		INT y = sqrt(x);
		if(y && y * y == x) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
