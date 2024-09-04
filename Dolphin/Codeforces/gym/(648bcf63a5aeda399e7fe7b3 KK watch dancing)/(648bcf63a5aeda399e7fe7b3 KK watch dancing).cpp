#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 20202;

int a[NN], b[NN];

bool solve(int n, int len) {
	for(int i = 1, j = 1; i < n; i = j) {
		for(; j < n && b[i] == b[j]; j++);
		if(j - i >= len) return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		for(int i = 1; i < n; i++) a[n + i] = a[i];
		
		for(int i = 2 * n; --i; ) b[i] = a[i] - i;
		if(solve(2 * n, n)) {puts("YES"); continue;}
		
		for(int i = 2 * n; --i; ) b[i] = a[i] + i;
		if(solve(2 * n, n)) puts("YES");
		else puts("NO");
	}
	return 0;
}
