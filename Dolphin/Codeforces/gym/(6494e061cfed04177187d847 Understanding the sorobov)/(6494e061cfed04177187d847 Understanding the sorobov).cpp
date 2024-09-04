#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char s[8][9], tmp[] = "10-01111";

int update(int J, int x) {
	if(x > 4) {
		swap(s[0][J], s[1][J]);
		return update(J, x - 5);
	}
	swap(s[3][J], s[3 + x][J]);
	return 0;
}

void solve() {
	int n; scanf("%d", &n);
	for(int i = 8; i--; ) s[i][0] = tmp[i];
	for(int j = 1; j < 9; j++) {
		for(int i = 8; i--; ) s[i][j] = s[i][j - 1];
	}
	for(int j = 9; j--; n /= 10) update(j, n % 10);
	
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 9; j++) putchar(s[i][j]);
		puts("");
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		solve();
		puts("");
	}
	return 0;
}
