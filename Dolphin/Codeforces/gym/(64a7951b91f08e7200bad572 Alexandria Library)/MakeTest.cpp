#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
	freopen("in.in", "w", stdout);
	
	srand(time(0));
	
	int t = 10;
	printf("%d\n", t);
	while(t--) {
		int n = 30000, q = 30000;
		printf("%d %d\n", n, q);
		for(int i = 2; i <= n; i++) {
			printf("%d %d\n", rnd % (i - 1) + 1, i);
		}
		while(q--) {
			int u = rnd % n + 1, v = rnd % n + 1;
			printf("%d %d\n", u, v);
		}
	}
	return 0;
}
