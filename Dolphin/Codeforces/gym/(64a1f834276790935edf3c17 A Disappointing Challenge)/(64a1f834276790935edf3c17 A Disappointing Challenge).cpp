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
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	if(n >= 3776) puts("1");
	else if(n > m) printf("%d\n", (3776 - n + (n - m - 1)) / (n - m) + 1);
	else puts("NEVER");
	return 0;
}
