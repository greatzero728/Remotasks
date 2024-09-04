#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

int a[NN];
vector<int> vec;

int solve() {
	int ans = vec[0];
	for(int i = 1; i < vec.size(); i++) {
		ans = max(ans, vec[i] - vec[i - 1]);
		ans = min(ans, vec[i]);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	for(int i = 1; i <= m; i++) vec.push_back(a[i]);
	int ans = solve();
	
	vec.clear();
	for(int i = n; i >= m; i--) vec.push_back(a[i]);
	ans = min(ans, solve());
	
	printf("%d\n", ans);
	return 0;
}
