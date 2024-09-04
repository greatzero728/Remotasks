#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int a[10101];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("playlist.in", "r", stdin);
	freopen("playlist.out", "w", stdout);
#endif
	
	int n, t; scanf("%d %d", &n, &t);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
//	sort(a + 1, a + n + 1);
	
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += a[i];
		if(sum == t) puts("Yes"), exit(0);
	}
	puts("No");
	return 0;
}