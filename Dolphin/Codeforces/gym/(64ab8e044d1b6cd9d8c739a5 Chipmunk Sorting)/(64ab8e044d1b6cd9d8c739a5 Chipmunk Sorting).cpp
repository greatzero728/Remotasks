#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int B[NN], n;
int a[NN], pos[NN];

int calc(int u) {
	int ans = 0;
	for(; u <= n; u += u & -u) ans += B[u];
	return ans;
}
void update(int u) {
	for(; u; u ^= u & -u) B[u]++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int t; scanf("%d %d", &n, &t);
	if(t < 0) puts("0"), exit(0);
	
	INT ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i), pos[a[i]] = i;
		ans += calc(a[i] + 1), update(a[i]);
	}
	for(int i = 1; i <= n; i++) if(a[i] ^ i) {
		int L = i, R = pos[i];
		swap(a[L], a[R]);
		pos[a[L]] = L, pos[a[R]] = R;
		ans--;
	}
	cout<<ans/2;
	return 0;
}
