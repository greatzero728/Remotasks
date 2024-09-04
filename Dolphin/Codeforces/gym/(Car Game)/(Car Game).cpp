#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

#define pc _putchar_nolock
static char fjf[1010], so[44];
char gc() {
	static char *L = fjf, *R = L;
	if(L == R) {
		int n = fread(fjf, 1, 1010, stdin);
		if(!n) return -1; L = fjf, R = L + n;
	}
	return *L++;
}
bool gn(int &x) {
	char c; while(c = gc(), (c < 48 || 57 < c) && ~c);
	for(x = c - 48; c = gc(), 48 <= c && c <= 57; x = 10 * x + c - 48);
	return 1;
}
bool gn(char &c) {while(c = gc(), ~c && isspace(c)); return ~c;}
bool gn(char *s) {
	char c; while(c = gc(), ~c && isspace(c)); if(!~c) return 0;
	for(*s++ = c; c = gc(), ~c && !isspace(c); *s++ = c); return *s = 0, 1;
}

const int NN = 5050, MM = 18181;

char s[NN][121];
int val[MM], ans[MM];
vector<int> vec[NN][26];

bool is_in(int a, int b, int c, vector<int> vec[26]) {
	if(vec[a].empty()) return 0;
	int id = upper_bound(vec[b].begin(), vec[b].end(), vec[a][0]) - vec[b].begin();
	if(id == vec[b].size()) return 0;
	id = upper_bound(vec[c].begin(), vec[c].end(), vec[b][id]) - vec[c].begin();
	return id < vec[c].size();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int n, m; gn(n), gn(m);
	for(int i = 1; i <= n; i++) {
		gn(s[i]);
		for(int j = 0; s[i][j]; j++) vec[i][s[i][j] - 'a'].push_back(j);
	}
	
	set<int> se;
	set<int> :: iterator it, th;
	for(int i = 1; i <= m; i++) {
		gn(s[0]);
		se.insert(val[i] = ((s[0][0] - 'A') * 26 + s[0][1] - 'A') * 26 + s[0][2] - 'A');
	}
	
	for(int k = 1; k <= n; k++) {
		int len = strlen(s[k]);
		for(it = se.begin(); it != se.end(); it = th) {
			th = it; th++;
			int x = *it, c = x % 26, b = (x / 26) % 26, a = (x / 26 / 26);
			if(is_in(a, b, c, vec[k])) ans[x] = k, se.erase(it);
		}
	}
	for(int i = 1; i <= m; i++) {
		if(ans[val[i]]) puts(s[ans[val[i]]]);
		else puts("No valid word");
	}
	return 0;
}
