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
	int n = 10, m = 10, k = 14;
	puts("1");
	printf("%d %d %d\n", n, m, k);
	for(int i = n; i--; ) {
		for(int j = m; j--; ) {
			printf("%d ", rnd % 1001);
		}
		puts("");
	}
	return 0;
}
