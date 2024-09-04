#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int n;
INT m;

const int NN = 101010;

int a[NN];

bool can(int x) {
	INT ans = 0;
	for(int i = n; i--; ) ans += min(a[i], x);
	return ans <= m;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %I64d", &n, &m);
	for(int i = n; i--; ) scanf("%d", a + i);
	
	int st = 0, ed = 1e9 + 1;
	while(ed - st > 1) {
		int md = st + ed >> 1;
		if(can(md)) st = md;
		else ed = md;
	}
	printf("%d\n", st);
	return 0;
}
