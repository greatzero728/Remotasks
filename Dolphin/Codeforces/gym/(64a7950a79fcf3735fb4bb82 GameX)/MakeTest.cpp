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
	int t = 4;
	printf("%d\n", t);
	while(t--) {
		int n = rnd % 100 + 1, k = rnd % 100 + 1;
		printf("%d %d\n", n, k);
		while(n--) {
			int x = rnd % 40;
			printf("%d ", x);
		}
		puts("");
	}
	return 0;
}
