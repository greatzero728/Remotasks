#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long double f(long long x) {
	if (x == 0) {return 0;}
	if (x <= 60) {return (long double)2 - (long double)1/(1ll << (x - 1));}
	return (long double)2;
}

void solve() {
	int n;
	cin >> n;
	long long a;
	long double res = 0.0;
	for (int i = 0; i < n; i++) {
	    cin >> a;
	    res += f(a);
	}
	cout << fixed << setprecision(17) << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
}