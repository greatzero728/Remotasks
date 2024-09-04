#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 5050;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	int ans = 0;
	for(int l = 1; l <= n; l++) {
		bool flag = 0;
		for(int i = 1; i <= l; i++) {
			for(int j = i; j <= l; j++) {
				for(int k = j; k <= l; k++) if(a[i] + a[j] + a[k] == a[l]) {
					flag = 1; break;
				}
			}
		}
		if(flag) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
