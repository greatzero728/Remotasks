#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	INT sum = (1LL + n * n) * n * n >> 1;
	
	if(n == 2 || sum % n) puts("FAIL");
	else printf("%d\n", sum / n);
	return 0;
}
