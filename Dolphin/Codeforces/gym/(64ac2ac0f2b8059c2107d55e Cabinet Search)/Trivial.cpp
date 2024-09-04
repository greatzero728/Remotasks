#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

INT x[NN];
bool flag[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	int n, q; scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%I64d", x + i);
	
	while(q--) {
		int t, a, b; scanf("%d %d", &t, &a);
		if(t == 1) flag[a] = 1;
		else {
			scanf("%d", &b);
			if(t == 2) {
				if(flag[a] && flag[b]) swap(x[a], x[b]);
			}
			else if(t == 3) x[a] += b;
			else {
				if(flag[a] && flag[b]) x[b] += x[a], x[a] = 0;
			}
		}
		
		int mx = 0; INT ans = 0;
		for(int i = 1, j = 1; i <= n; i = j) {
			INT s = 0;
			for(; j <= n && flag[i] == flag[j]; j++) s += x[j];
			if(flag[i]) mx = max(mx, j - i), ans = max(ans, s);
		}
		printf("%d %I64d\n", mx, ans);
	}
	return 0;
}