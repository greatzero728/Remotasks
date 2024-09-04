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
	
	int n = rnd % 1000 + 1;
	printf("%d\n", n);
	while(n--) {
		int k = 100;
		int x = rnd % (2 * k + 1) - k;
		printf("%d ", x);
	}
	return 0;
}
