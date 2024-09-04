#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int num[44];
multiset<pii> s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	while(n--) {
		int x; scanf("%d", &x);
		for(int i = 0; x; i++, x >>= 1) {
			if(x & 1) num[i]++;
		}
	}
	while(m--) {
		int x; scanf("%d", &x);
		s.insert({__builtin_ctz(x), -1});
	}
	
	int ans = 0;
	while(!s.empty()) {
		pii p = *s.begin();
		int j = p.x, cnt = p.y;
		if(num[j]) num[j]--, s.erase(s.begin()), ans -= cnt;
		else {
			s.erase(s.begin());
			if(!s.empty()) {
				pii q = *s.begin();
				int j2 = q.x, cnt2 = q.y;
				if(j == j2) {
					s.erase(s.begin());
					s.insert({j + 1, cnt + cnt2});
				}
				else if(j < 33) {
					s.insert({j + 1, cnt});
				}
			}
			else if(j < 33) {
				s.insert({j + 1, cnt});
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
