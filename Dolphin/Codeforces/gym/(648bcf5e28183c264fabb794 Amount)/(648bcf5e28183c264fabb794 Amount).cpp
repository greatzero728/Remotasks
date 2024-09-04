#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int n, k;
int q[22], qb;

int dfs(int x, int sum, int step) {
	q[qb++] = x;
	if(step == k) {
		if(sum == n) {
			for(int i = 0; i < qb; i++) {
				if(i && q[i] >= 0) putchar('+');
				printf("%d", q[i]);
			}
			puts("");
		}
		return qb--;
	}
	int mn = (x - 1 + x - k + step) * (k - step) >> 1;
	int mx = (x + 1 + x + k - step) * (k - step) >> 1;
	if(sum + mn <= n && n <= sum + mx) {
		dfs(x - 1, sum + x - 1, step + 1);
		dfs(x, sum + x, step + 1);
		dfs(x + 1, sum + x + 1, step + 1);
	}
	return qb--;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d", &n, &k);
	for(int i = -20; i <= 20; i++) dfs(i, i, 1);
	return 0;
}
