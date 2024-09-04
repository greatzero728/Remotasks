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
	
	int n = 100000;
	cout<<n<<endl;
	while(n--) {
		cout<<rnd % 1000 + 1<<' ';
	}
	
	return 0;
}
