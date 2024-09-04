#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

unsigned long long f[101] = {0, 1};

bool can(int x) {
	while(x) {
		int c = x % 10;
		if(c == 4 || c == 6 || c == 9) return 1;
		x /= 10;
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int ans = 0;
	for(int i = 0; i <= 2019; i++) if(can(i)) {
		ans++;
	}
	cerr<<ans<<endl;
	return 0;
}
