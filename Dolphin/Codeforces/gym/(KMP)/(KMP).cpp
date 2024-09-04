#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7, NN = 101010;

int num[NN], ans[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	while(n--) {
		int x; scanf("%d", &x);
		num[x]++;
	}
	
	int s = 0;
	for(int i = 1; i < NN; i++) {
		ans[i] = ((INT)ans[i - 1] * num[i] + num[i]) % mod;
		s = (s + ans[i]) % mod;
	}
	cout<<s;
	return 0;
}
