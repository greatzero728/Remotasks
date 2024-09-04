#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int n, p, x, y, z;

const int NN = 10101010, mod = 998244353;

int b[NN], A[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	scanf("%d %d %d %d %d %d", &n, &p, &x, &y, &z, b + 1);
	
	stack<pii> s;
	s.push({-mod, 0}), s.push({A[1] = b[1], 1});
	
	int ans = A[1];
	for(int i = 2; i <= n; i++) {
		b[i] = ((INT)x * A[i - 1] + (INT)y * b[i - 1] + z) % p;
		
		while(s.top().x >= b[i]) s.pop();
		int id = s.top().y;
		s.push({b[i], i});
		
		int pre_sum = A[id];
		if(id) pre_sum = (pre_sum - A[id - 1] + mod) % mod;
		A[i] = (A[i - 1] + (INT)b[i] * (i - id) + pre_sum) % mod;
		ans ^= A[i];
	}
	cout<<ans;
	return 0;
}