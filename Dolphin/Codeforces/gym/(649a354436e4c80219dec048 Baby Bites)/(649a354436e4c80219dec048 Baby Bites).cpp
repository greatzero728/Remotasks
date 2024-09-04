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
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		string s; cin>>s;
		if(s[0] == 'm') continue;
		int x = 0;
		for(char c : s) x = 10 * x + c - '0';
		if(i ^ x) puts("something is fishy"), exit(0);
	}
	puts("makes sense");
	return 0;
}