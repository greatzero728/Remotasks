#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, b; scanf("%d %d", &n, &b);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	
	for(int i = n; i; i--) if(32 - __builtin_clz(a[i]) <= b / i) {
		printf("%d\n", i); return 0;
	}
	puts("0");
	return 0;
}