#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
	freopen("in.txt", "w", stdout);
	srand(time(0));
	int n = 100000, m = 300000;
	cout<<n<<' '<<m<<endl;
	
	while(m--) {
		int u = rnd % (n - 1) + 1;
		int v = rnd % u;
		printf("%d %d\n", u, v);
	}
	return 0;
}
