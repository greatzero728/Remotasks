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
	
	int t = 500;
	cout<<t<<endl;
	while(t--) {
		int n = rnd % 1000000000 + 1;
		int k = rnd % min(n, 10) + 1;
		cout<<n<<' '<<k<<endl;
	}
	return 0;
}
