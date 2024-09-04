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
	
	int n = rnd % 50 + 1, k = rnd % n + 1;
	n = 50, k = rnd % n + 1;
	cout<<n<<' '<<k<<endl;
	for(int i = 1; i <= n; i++, puts)
	for(int j = 1; j <= n; j++) {
		int x = rnd % 2001 - 1000;
		x = rnd % 1000 + 1;
		cout<<x<<' ';
	}
	return 0;
}
