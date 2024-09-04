#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int a[22], flag[22];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	
	int ans = 0;
	for(int k = 3; k <= n; k++) {
		bool find = 0;
		for(int i = 1; i < k && !find; i++) if(!flag[i]) {
			for(int j = i + 1; j < k; j++) if(!flag[j]) {
				if(a[i] + a[j] > a[k]) {
					flag[i] = flag[j] = flag[k] = 1;
					ans++, find = 1;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
