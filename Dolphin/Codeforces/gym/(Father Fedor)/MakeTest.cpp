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
	int n = 100;
	cout<<n<<' '<<1<<' '<<n<<endl;
	cout<<300<<' '<<300<<endl;
	cout<<2<<endl;
	cout<<1<<' '<<2<<endl;
	return 0;
}
