#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const INT inf = 1e17;

int n, m;
INT L;

INT calc(INT nn, INT mm, INT uv, INT ij) {
	if(uv > 2 * (n - 1)) return inf;
	if(ij > 2 * (m - 1)) return inf;
	nn--, mm--;
	INT v2 = nn + uv;
	if(v2 & 1) return inf;
	INT v = v2 >> 1;
	INT u = uv - v;
	
	INT j2 = mm + ij;
	if(j2 & 1) return inf;
	INT j = j2 >> 1;
	INT i = ij - j;
	
	return (v - u + 1) * (j - i + 1);
}

INT calc(INT nn, INT mm) {
	if(2 * L / nn < mm) return inf;
	if(2 * L % (nn * mm)) return inf;
	
	INT x = 2 * L / nn / mm;
	return min(calc(nn, mm, x / m, x % m), calc(nn, mm, (x - (x % m + m)) / m, x % m + m));
}

INT solve() {
	scanf("%d %d", &n, &m);
	scanf("%I64d", &L);
	
	vector<INT> vec_n, vec_m;
	for(int i = sqrt(2 * L) + 1; i; i--) if(2 * L % i == 0) {
		INT x = 2 * L / i;
		if(i <= n) vec_n.push_back(i);
		if(x <= n) vec_n.push_back(x);
		
		if(i <= m) vec_m.push_back(i);
		if(x <= m) vec_m.push_back(x);
	}
	sort(vec_m.begin(), vec_m.end());
	vec_m.resize(unique(vec_m.begin(), vec_m.end()) - vec_m.begin());
	
	INT ans = inf;
	for(INT nn : vec_n) {
		int id = upper_bound(vec_m.begin(), vec_m.end(), 2 * L / nn) - vec_m.begin();
		for(int i = 0; i < id; i++) {
			ans = min(ans, calc(nn, vec_m[i]));
		}
	}
	return ans < inf ? ans : -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%I64d\n", solve());
	return 0;
}