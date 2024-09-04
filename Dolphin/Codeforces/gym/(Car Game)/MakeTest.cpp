#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
	freopen("test\\in.txt", "w", stdout);
	
	srand(time(0));
	int n = 5000, m = 10000;
	cout<<n<<' '<<m<<endl;
	while(n--) {
		int len = rnd % 100 + 1;
		while(len--) {
			putchar('a' + rnd % 26);
		}
		puts("");
	}
	while(m--) {
		for(int i = 3; i--; ) {
			putchar('A' + rnd % 26);
		}
		puts("");
	}
	return 0;
}
