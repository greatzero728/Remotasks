#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int n = nxt();
	map<int, vector<int>, greater<int>> M;
	for (int i = 0; i < n; ++i) {
		M[nxt()].push_back(i);
	}
	set<int> S;
	S.insert(-1);
	S.insert(n);

	long long ans = 0;
	for (const auto& p : M) {
		auto it = S.begin();
		long long left_segs = 0;
		int prv = -1;
		long long to_flush = 0;
		long long to_exclude = 0;
		for (int pos : p.second) {
			if (*it < pos) {
				left_segs = left_segs + to_flush;
				if (left_segs >= mod) {
					left_segs -= mod;
				}
				to_flush = 0;
				it = S.lower_bound(pos);
				prv = *prev(it);
				to_exclude = 0;
			}

			int cit = *it;
			int pit = *prev(it);
			long long tmp = 1ll * (cit - pos) * (pos - prv) % mod;
			ans += tmp * left_segs % mod;
			ans += 1ll * (pos - prv) * (pos - prv + 1) / 2 % mod * (cit - pos) % mod * (prv - pit) % mod;
			ans += (1ll * (prv - pit) * (prv - pit - 1) / 2 - to_exclude) % mod * tmp % mod;
			to_exclude += 1ll * (pos - prv) * (pos - prv - 1) / 2;
			to_flush += tmp;
			if (to_flush >= mod) {
				to_flush -= mod;
			}

			prv = pos;
		}
		for (int pos : p.second) {
			S.insert(pos);
		}
	}
	cout << ans % mod << "\n";

	return 0;
}
