#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m, t; scanf("%d %d %d", &n, &m, &t);
	int x = 0, xmn = 0, xmx = 0;
	int y = 0, ymn = 0, ymx = 0;
	while(t--) {
		char c; scanf(" %c", &c);
		if(c == 'C') xmx = max(xmx, ++x);
		if(c == 'D') ymx = max(ymx, ++y);
		if(c == 'B') xmn = min(xmn, --x);
		if(c == 'E') ymn = min(ymn, --y);
	}
	int xst = x - xmn + 1, xed = x - xmx + n;
	int yst = y - ymn + 1, yed = y - ymx + m;
	
	printf("%d\n", (xed - xst + 1) * (yed - yst + 1));
	for(int x = xst; x <= xed; x++) {
		for(int y = yst; y <= yed; y++) {
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}
