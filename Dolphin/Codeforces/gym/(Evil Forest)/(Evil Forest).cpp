#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int solve() {
	int n, sum = 0; scanf("%d", &n);
	while(n--) {
		int x; scanf("%d", &x);
		sum += x + (x + 9) / 10;
	}
	return sum;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	for(int i = 1; i <= t; i++) printf("Case #%d: %d\n", i, solve());
	return 0;
}
