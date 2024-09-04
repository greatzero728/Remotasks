#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020, inf = 0x3f3f3f3f;

int a[NN], b[NN], n, k;
bool flag[NN];
vector<vector<int> > ans;

void solve(int x) {
	memset(flag, 0, sizeof flag);
	for(int i = 1; i <= n; i++) if(a[i] == x) {
		flag[i] = 1; break;
	}
	
	int smaller_num = 0, larger_num = 0, same_num = 0;
	for(int i = 1; i <= n; i++) if(!flag[i]) {
		if(a[i] < x) smaller_num++;
		else if(a[i] > x) larger_num++;
		else same_num++;
	}
	
	int na = smaller_num, nb = larger_num;
	while(na < nb && same_num) same_num--, na++;
	while(na > nb && same_num) same_num--, nb++;
	if(na > nb) na = nb;
	if(nb > na + 1) nb = na + 1;
	
	while(same_num >= 2) same_num -= 2, na++, nb++;
	if(same_num) nb++;
	
	for(int i = 1; i <= n; i++) if(!flag[i]) {
		if(a[i] < x && na) flag[i] = 1, na--;
		if(a[i] > x && nb) flag[i] = 1, nb--;
	}
	for(int i = 1; i <= n; i++) if(!flag[i]) {
		if(a[i] <= x && na) flag[i] = 1, na--;
		if(a[i] >= x && nb) flag[i] = 1, nb--;
	}
	
	vector<int> vec;
	for(int i = 1; i <= n; i++) if(flag[i]) {
		vec.push_back(i);
	}
	ans.push_back(vec);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	int x, mn = inf;
	for(int i = 1; i <= n; i++) {
		int tmp = abs(a[i] - k);
		if(tmp < mn) mn = tmp, x = a[i];
		else if(tmp == mn && a[i] < x) x = a[i];
	}
	
	for(int i = 1; i <= n; i++) b[i] = a[i];
	sort(b + 1, b + n + 1);
	int m = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= m; i++) if(b[i] == x) {
		if(i > 1) solve(b[i - 1]);
		if(i < m) solve(b[i + 1]);
		solve(b[i]);
		break;
	}
	
	mn = inf; int sz = 0;
	vector<int> s;
	for(vector<int> vec : ans) {
		n = 0;
		for(int x : vec) b[++n] = a[x];
		sort(b + 1, b + n + 1);
		int y = b[n + 1 >> 1];
		int tmp = abs(k - y);
		if(tmp < mn) s = vec, mn = tmp, sz = vec.size();
		else if(tmp == mn && vec.size() > sz) {
			s = vec, sz = vec.size();
		}
	}
	printf("%d\n", s.size());
	for(int x : s) printf("%d ", x);
	
	return 0;
}
