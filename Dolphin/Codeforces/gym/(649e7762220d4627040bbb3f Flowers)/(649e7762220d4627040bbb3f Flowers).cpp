#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 3030;

bitset<3001> s[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1, x; j <= n; j++) {
			scanf("%d", &x);
			if(x) s[j].set(i);
		}
	}
	
	INT ans = 0;
	for(int st = 1; st <= n; st++) {
		bitset<3001> bs = s[st];
		for(int ed = st; ed <= n; ed++) {
			if(ed > st) bs &= s[ed];
			int cnt = bs.count();
			ans += cnt * (cnt - 1) >> 1;
		}
	}
	cout<<ans;
	return 0;
}
