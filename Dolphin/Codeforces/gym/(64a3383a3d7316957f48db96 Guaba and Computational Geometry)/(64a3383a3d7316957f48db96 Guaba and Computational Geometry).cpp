#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

const int NN = 303030;

int xmn[NN], ymn[NN];
int xmx[NN], ymx[NN];
int w[NN], ans, n;

ppi p[NN];
set<pii> mx;
set<pii> :: iterator it;

void update() {
	sort(p + 1, p + n + 1, [&](ppi a, ppi b) {
		return a.x.y < b.x.y;
	});
	
	mx.clear();
	for(int i = 1; i <= n; i++) mx.insert({p[i].x.y, p[i].y});
	
	vector<pii> vec;
	int Mx = 0;
	for(it = mx.begin(); it != mx.end(); it++) {
		Mx = max(it->y, Mx);
		vec.push_back({it->x, Mx});
	}
	mx.clear();
	for(pii p : vec) mx.insert(p);
	
	sort(p + 1, p + n + 1, [&](ppi a, ppi b) {
		return a.x.x < b.x.x;
	});
	for(int i = 2; i <= n; i++) {
		it = mx.lower_bound({p[i].x.x, 1});
		if(it != mx.begin()) {
			it--;
			ans = max(ans, it->y + p[i].y);
		}
	}
}

int solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", xmn + i, ymn + i);
		scanf("%d %d", xmx + i, ymx + i);
	}
	for(int i = 1; i <= n; i++) scanf("%d", w + i);
	
	ans = -1;
	for(int i = 1; i <= n; i++) p[i] = {{xmn[i], xmx[i]}, w[i]};
	update();
	for(int i = 1; i <= n; i++) p[i] = {{ymn[i], ymx[i]}, w[i]};
	update();
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%d\n", solve());
	return 0;
}