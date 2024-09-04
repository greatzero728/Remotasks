#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

map<string, int> mp;
vector<string> s;
string c;
int ans[22];

void solve() {
	int n; scanf("%d", &n);
	s.clear();
	for(int i = 1; i <= n; i++) {
		cin>>c, s.push_back(c);
		mp[c] = i, ans[i] = 0;
	}
	
	for(int i = n; i--; ) {
		cin>>c;
		int x, len; scanf("%d %d", &x, &len);
		if(len) x /= len;
		
		int u = mp[c];
		while(len--) {
			cin>>c;
			int v = mp[c];
			ans[v] += x, ans[u] -= x;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		printf("%s %d\n", s[i - 1].c_str(), ans[i]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		solve();
		if(t) puts("");
	}
	return 0;
}
