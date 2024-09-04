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
	int t = 200000;
	printf("%d\n", t);
	while(t--) {
		cout<<rnd % 100 + 10<<' '<<rnd % 100 + 10<<' '<<rnd % 1000 + 100<<' '<<rnd % 1000 + 1000000<<endl;
	}
	return 0;
}
