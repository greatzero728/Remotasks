#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int a[NN], n;
INT t;

bool can(INT x) {
	INT ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += x / a[i];
		if(ans >= t) return 1;
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %I64d", &n, &t);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	INT st = 0, ed = 1e18;
	while(ed - st > 1) {
		INT md = st + ed >> 1;
		if(can(md)) ed = md;
		else st = md;
	}
	printf("%I64d\n", ed);
	return 0;
}
