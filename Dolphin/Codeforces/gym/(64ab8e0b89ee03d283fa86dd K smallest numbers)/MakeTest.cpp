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
	int t = 20;
	printf("%d\n", t);
	while(t--) {
		int n = rnd % 10000000 + 1;
		int k = min(rnd % n + 1, (INT)100);
		int s = rnd % 10000001;
		int c1 = rnd % 10000001;
		int c2 = rnd % 10000001;
		int m = rnd % 9999999 + 2;
		cout<<n<<' '<<k<<' '<<s<<' '<<c1<<' '<<c2<<' '<<m<<endl;
	}
	return 0;
}
