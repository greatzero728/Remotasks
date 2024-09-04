#include<bits/stdc++.h>
#define mid (L + R >> 1)
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 100010, MM = NN << 1, CC = 10, mod = 4001;

int ls[MM], rs[MM], l, r, nn;
int st[MM][2], ed[MM][2], ans[MM];
bool s[NN], cnt[MM];

void push_up(int u) {
	ans[u] = (ans[ls[u]] + ans[rs[u]]) % mod;
	for(int i = 2; i--; ) {
		st[u][i] = (st[ls[u]][i] + st[rs[u]][i ^ cnt[ls[u]]]) % mod;
		ed[u][i] = (ed[rs[u]][i] + ed[ls[u]][i ^ cnt[rs[u]]]) % mod;
		ans[u] = (ans[u] + ed[ls[u]][i] * st[rs[u]][i ^ 1]) % mod;
	}
	cnt[u] = cnt[ls[u]] ^ cnt[rs[u]];
}

int insert(int u, int L) {
	st[u][0] = st[u][1] = ed[u][0] = ed[u][1] = cnt[u] = ans[u] = 0;
	st[u][s[L]] = ed[u][s[L]] = 1;
	cnt[u] = ans[u] = s[L];
	return 0;
}

int build(int L, int R) {
	int u = nn++;
	if(R - L > 1) {
		ls[u] = build(L, mid);
		rs[u] = build(mid, R);
		push_up(u);
	}
	else insert(u, L);
	return u;
}

int update(int u, int L, int R) {
	if(l <= L && R <= r) return insert(u, L);
	if(l < mid) update(ls[u], L, mid);
	if(mid < r) update(rs[u], mid, R);
	push_up(u);
	return 0;
}

int St[2][2], Ed[2][2], Ans[2];
bool Cnt[2];

void calc(int u, int L, int R) {
	if(l <= L && R <= r) {
		St[1][0] = St[1][1] = Ed[1][0] = Ed[1][1] = Cnt[1] = Ans[1] = 0;
		
		Ans[1] = (Ans[0] + ans[u]) % mod;
		for(int i = 2; i--; ) {
			St[1][i] = (St[0][i] + st[u][i ^ Cnt[0]]) % mod;
			Ed[1][i] = (ed[u][i] + Ed[0][i ^ cnt[u]]) % mod;
			Ans[1] = (Ans[1] + Ed[0][i] * st[u][i ^ 1]) % mod;
		}
		Cnt[1] = Cnt[0] ^ cnt[u];
		
		St[0][0] = St[1][0], St[0][1] = St[1][1];
		Ed[0][0] = Ed[1][0], Ed[0][1] = Ed[1][1];
		Cnt[0] = Cnt[1];
		Ans[0] = Ans[1];
		return;
	}
	if(l < mid) calc(ls[u], L, mid);
	if(mid < r) calc(rs[u], mid, R);
}

int n, m, A[NN];
int t[NN], a[NN], b[NN];
int result[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", A + i);
	for(int i = m; i--; ) scanf("%d %d %d", t + i, a + i, b + i);
	
	for(int k = CC; k--; ) {
		for(int i = 1; i <= n; i++) s[i] = (A[i] >> k) & 1;
		
		nn = 0, build(1, n + 1);
		for(int i = m; i--; ) {
			if(t[i] == 1) {
				l = a[i], r = l + 1, s[l] = (b[i] >> k) & 1;
				update(0, 1, n + 1);
			}
			else {
				St[0][0] = St[0][1] = Ed[0][0] = Ed[0][1] = Cnt[0] = Ans[0] = 0;
				l = a[i], r = b[i] + 1, calc(0, 1, n + 1);
				result[i] = (result[i] + (1 << k) * Ans[0]) % mod;
			}
		}
	}
	while(m--) if(t[m] == 2) printf("%d\n", result[m]);
	return 0;
}
