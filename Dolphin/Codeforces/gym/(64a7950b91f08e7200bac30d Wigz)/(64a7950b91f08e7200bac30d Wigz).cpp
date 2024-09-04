#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

int a[NN][NN], b[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#else
	freopen("wigz.in", "r", stdin);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		bool flag = n > m;
		if(flag) {
			swap(n, m);
			for(int j = m; j--; ) {
				for(int i = n; i--; ) scanf("%d", a[i] + j);
			}
		}
		else {
			for(int i = n; i--; ) {
				for(int j = m; j--; ) scanf("%d", a[i] + j);
			}
		}
		
		int ans = 0;
		for(int s = 1 << n; s--; ) if(__builtin_popcount(s) <= k) {
			int sum = 0;
			for(int j = m; j--; ) b[j] = 0;
			for(int i = n; i--; ) {
				if((s >> i) & 1) {
					for(int j = m; j--; ) sum += a[i][j];
				}
				else {
					for(int j = m; j--; ) b[j] += a[i][j];
				}
			}
			sort(b, b + m, [&](int u, int v) {return u > v;});
			for(int i = min(m, k - __builtin_popcount(s)); i--; ) sum += b[i];
			ans = max(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}