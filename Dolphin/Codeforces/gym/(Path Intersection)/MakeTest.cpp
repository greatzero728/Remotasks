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
	
	int t = 50;
	cout<<t<<endl;
	while(t--) {
		int n = 10000;
		cout<<n<<endl;
		for(int i = 1; i < n; i++) {
			int x = rnd % i;
			printf("%d %d\n", x + 1, i + 1);
		}
		int q = 5000;
		cout<<q<<endl;
		while(q--) {
			int k = 2;
			cout<<k<<endl;
			while(k--) {
				int a = rnd % n + 1, b = rnd % n + 1;
				printf("%d %d\n", a, b);
			}
		}
	}
	return 0;
}
