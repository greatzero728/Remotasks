#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int n, m, k;

void input(int &i, int &h) {
	int x; scanf("%d", &x);
	x--, x /= k;
	i = x / m, h = x % m;
}

int calc_in_same_entrance(int a, int b) {
	return min(abs(a - b) * 5, 10 + abs(a - b));
}
int calc_dst(int x, int y) {
	if(x > y) swap(x, y);
	return min(y - x, n + x - y) * 15;
}
int calc_down(int h) {
	return min(5 * h, 10 + h);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	scanf("%d %d %d", &n, &m, &k);
	int ia, ha; input(ia, ha);
	int ib, hb; input(ib, hb);
	
	if(ia == ib) cout<<calc_in_same_entrance(ha, hb);
	else cout<<calc_dst(ia, ib) + calc_down(ha) + calc_down(hb);
	return 0;
}
