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
	
	for(int i = 1000; i--; ) {
		int R = rnd % 999999999 + 2, L = rnd % (R - 1) + 1;
		cout<<L<<' '<<R<<endl;
	}
	puts("0 0");
	return 0;
}
