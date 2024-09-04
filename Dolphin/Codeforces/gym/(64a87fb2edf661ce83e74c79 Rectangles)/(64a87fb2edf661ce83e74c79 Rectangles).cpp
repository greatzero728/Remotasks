#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, INT>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	
	vector<pii> ans;
	for(int i = 1, st = 2 * n + 2, a; i <= 121500000; i++) {
		a = st + i;
		INT b = 2LL * n * a;
		if(b % i == 0) {
			b = b / i;
			if(a <= b) ans.push_back({a, b + 2});
		}
	}
	
	printf("%d\n", ans.size());
	for(pii p : ans) printf("%d %I64d\n", p.x, p.y);
	return 0;
}
