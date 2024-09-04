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
	
	int t = 1000;
	printf("%d\n", t);
	while(t--) {
		int x = rnd % 100 + 1;
		printf("%d ", x);
	}
	return 0;
}
