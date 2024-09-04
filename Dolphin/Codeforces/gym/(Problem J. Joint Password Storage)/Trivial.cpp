#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char ans[11];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("test.txt", "w", stdout);
#endif
	
	for(int j = 3; j--; ) {
		for(int i = 0; i < 10; i++) {
			char c; scanf(" %c", &c);
			ans[i] ^= c;
		}
	}
	for(int i = 0; i < 10; i++) cerr<<ans[i]<<' ';
	return 0;
}
