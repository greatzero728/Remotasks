#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;
const pii P = {29, 998244353}, mod = {1000000009, 1000000007};

char p[121], s[NN];
pii f[NN], hp[121], hs[NN];

void init_hash(char *s, int n, pii *h) {
	for(int i = 1; i <= n; i++) {
		int c = max(s[i] - 'a' + 1, 1);
		h[i].x = ((INT)P.x * h[i - 1].x + c) % mod.x;
		h[i].y = ((INT)P.y * h[i - 1].y + c) % mod.y;
	}
}

pii calc_hash(pii *h, int st, int ed) {
	int x = (h[ed].x - (INT)h[st - 1].x * f[ed - st + 1].x % mod.x + mod.x) % mod.x;
	int y = (h[ed].y - (INT)h[st - 1].y * f[ed - st + 1].y % mod.y + mod.y) % mod.y;
	return {x, y};
}
bool same(pii ha, pii *hb, int stb, int edb) {
	return ha == calc_hash(hb, stb, edb);
}

int Lnum, Rnum;
pii Lh, Rh;

using ppp = pair<pii, pii>;
vector<ppp> vec;

bool can(int L, int R) {
	if(Lnum) {
		if(!same(Lh, hs, L, L + Lnum - 1)) return 0;
		L += Lnum;
	}
	if(Rnum) {
		if(!same(Rh, hs, R - Rnum + 1, R)) return 0;
		R -= Rnum;
	}
	
	int i = 0, id = L - 1;
	while(id <= R && i < vec.size()) {
		int len = vec[i].x.y - vec[i].x.x + 1;
		if(same(vec[i].y, hs, id + 1, id + len)) i++, id += len;
		else id++;
	}
	return i == vec.size();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("pattern.in", "r", stdin);
	freopen("pattern.out", "w", stdout);
#endif
	
	for(int i = f[0].x = f[0].y = 1; i < NN; i++) {
		f[i].x = (INT)P.x * f[i - 1].x % mod.x;
		f[i].y = (INT)P.y * f[i - 1].y % mod.y;
	}
	
	scanf("%s %s", p + 1, s + 1);
	int np = strlen(p + 1); init_hash(p, np, hp);
	
	int ns = strlen(s + 1);
	for(int i = 1; i < ns; i++) s[ns + i] = s[i];
	init_hash(s, ns * 2 - 1, hs);
	
	bool is_in = 0;
	for(int i = 1; i <= np; i++) if(p[i] == '*') {
		Lnum = i - 1, is_in = 1; break;
	}
	
	if(!is_in) {
		if(np != ns) puts("0"), exit(0);
		int ans = 0;
		for(int i = 2 * ns; i-- > ns; ) {
			if(same(hp[np], hs, i - np + 1, i)) ans++;
		}
		printf("%d\n", ans);
		return 0;
	}
	Lh = calc_hash(hp, 1, Lnum);
	
	for(int i = np; i; i--) if(p[i] == '*') {
		Rnum = np - i; break;
	}
	Rh = calc_hash(hp, np - Rnum + 1, np);
	
	for(int i = 1 + Lnum, j = i; i < np - Rnum; i = j) {
		for(; j < np - Rnum && (p[i] == '*') == (p[j] == '*'); j++);
		if(p[i] != '*') {
			vec.push_back({{i, j - 1}, calc_hash(hp, i, j - 1)});
		}
	}
	
	int ans = 0;
	for(int i = 2 * ns; i-- > ns; ) {
		if(can(i - ns + 1, i)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}