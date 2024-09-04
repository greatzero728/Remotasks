#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F(i,l,r) for(int i = l; i < r; i++)
#define f(i,n) F(i, 0, n)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
bool u[500][500];
int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
	freopen("gazmyas.in","r",stdin);
	freopen("gazmyas.out","w",stdout);
#endif
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> q;
	int n;
	cin >> n;
	ll ans = 0;
	vector<int> buf;
	f(i,n)
	{
		int x;
		cin >> x;
		if (x & 1) {
			for (int h : buf)
				q.insert(h);
			buf.clear();
		} else {
			ans += (int) q.order_of_key(x);
			buf.push_back(x);
		}
	}
	cout << ans;
	return 0;
}