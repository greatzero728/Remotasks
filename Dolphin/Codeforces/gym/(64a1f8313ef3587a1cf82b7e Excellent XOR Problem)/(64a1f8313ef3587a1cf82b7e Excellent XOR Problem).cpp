#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int a[NN];

void solve() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	int x = 0;
	for(int i = 1; i <= n; i++) x ^= a[i];
	if(x) {
		puts("YES");
		puts("2");
		puts("1 1");
		printf("%d %d\n", 2, n);
		return;
	}
	
	for(int i = 1; i <= n; i++) if(a[i]) {
		x = 0;
		for(int j = i + 1; j < n; j++) {
			x ^= a[j];
			if(x && x != a[i]) {
				puts("YES");
				puts("3");
				printf("1 %d\n", i);
				printf("%d %d\n", i + 1, j);
				printf("%d %d\n", j + 1, n);
				return;
			}
		}
		break;
	}
	puts("NO");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}
