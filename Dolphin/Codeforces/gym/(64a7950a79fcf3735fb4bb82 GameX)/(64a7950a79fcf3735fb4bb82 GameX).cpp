#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d %d", &n, &k);
		set<int> s;
		while(n--) {
			int x; scanf("%d", &x);
			s.insert(x);
		}
		for(int num = k, i = 1; num; i += 2) {
			if(s.find(i) == s.end()) s.insert(i), num--;
		}
		for(int num = k, i = 0; num; i += 2) {
			if(s.find(i) == s.end()) s.insert(i), num--;
		}
		for(int i = 0; ; i++) if(s.find(i) == s.end()) {
			if(i & 1) puts("Bob");
			else puts("Alice");
			break;
		}
	}
	return 0;
}
