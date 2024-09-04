#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

#define mid (L + R >> 1)

const int NN = 10101, MM = NN << 2, MMM = MM << 1;

vector<ppi> vec[NN];
int arr[MM + NN], nn;
int flag[MMM], mx[MMM], m;
int ls[MMM], rs[MMM], l, r, x;

int build(int L, int R) {
	int u = m++;
	if(R - L > 1) {
		ls[u] = build(L, mid);
		rs[u] = build(mid, R);
	}
	return u;
}

void update(int u, int x) {
	mx[u] += x, flag[u] += x;
	return;
}

void push_down(int u) {
	if(flag[u]) {
		update(ls[u], flag[u]);
		update(rs[u], flag[u]);
		flag[u] = 0;
	}
	return;
}

void update(int u, int L, int R) {
	if(l <= L && R <= r) update(u, x);
	else {
		push_down(u);
		if(l < mid) update(ls[u], L, mid);
		if(mid < r) update(rs[u], mid, R);
		mx[u] = max(mx[ls[u]], mx[rs[u]]);
	}
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	while(n--) {
		int Y1, X1; scanf("%d %d", &Y1, &X1);
		int Y2, X2; scanf("%d %d", &Y2, &X2);
		int A; scanf("%d", &A);
		if(!A) continue;
		vec[X1].push_back({{Y1, Y2}, A});
		vec[X2 + 1].push_back({{Y1, Y2}, -A});
		if(Y1 > 1) arr[nn++] = Y1 - 1;
		arr[nn++] = Y1, arr[nn++] = Y2;
	}
	int R, ed; scanf("%d %d", &R, &ed);
	for(int i = 1; i <= ed; i++) {
		for(ppi p : vec[i]) if(p.x.y < R) {
			arr[nn++] = p.x.y + 1;
		}
	}
	arr[nn++] = 1, arr[nn++] = R;
	
	sort(arr, arr + nn);
	nn = unique(arr, arr + nn) - arr;
	
	int ans = -1e9;
	build(0, nn);
	for(int i = 1; i <= ed; i++) {
		for(ppi p : vec[i]) {
			l = lower_bound(arr, arr + nn, p.x.x) - arr;
			r = upper_bound(arr, arr + nn, p.x.y) - arr;
			x = p.y, update(0, 0, nn);
		}
		ans = max(ans, mx[0]);
	}
	printf("%d\n", ans);
	return 0;
}
