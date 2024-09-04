#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

vector<int> vec = {3, 15, 120, 528, 4095, 17955, 139128, 609960, 4726275, 20720703, 160554240, 703893960};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int L, R, nn = 0;
	while(scanf("%d %d", &L, &R), L) {
		printf("Case %d: %d\n", ++nn, upper_bound(vec.begin(), vec.end(), --R - 1) - lower_bound(vec.begin(), vec.end(), ++L - 1));
	}
	return 0;
}