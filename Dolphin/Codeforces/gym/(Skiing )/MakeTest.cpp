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
	int n = 250;
	int vy = 1;
	int amax = 2;
	cout<<n<<' '<<vy<<' '<<amax<<endl;
	while(n--) {
		int x = rnd % 200001 - 100000;
		int y = rnd % 200001 - 100000;
		cout<<x<< ' '<<y<<endl;
	}
	return 0;
}
