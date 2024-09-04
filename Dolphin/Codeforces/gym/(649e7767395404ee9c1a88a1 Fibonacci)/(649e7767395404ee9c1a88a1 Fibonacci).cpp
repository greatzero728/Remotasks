#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7;

pii Mul(pii a, pii b) {
	return {((INT)a.y * b.y + (INT)a.x * b.x) % mod, ((INT)a.y * (b.x + b.y) + (INT)a.x * b.y) % mod};
}
int calc_fibo(INT n) {
	pii ans = {1, 0}, b = {0, 1};
	for(; n; n >>= 1, b = Mul(b, b)) if(n & 1) ans = Mul(ans, b);
	return ans.y;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	INT n; cin>>n;
	cout<<calc_fibo(n);
	return 0;
}
