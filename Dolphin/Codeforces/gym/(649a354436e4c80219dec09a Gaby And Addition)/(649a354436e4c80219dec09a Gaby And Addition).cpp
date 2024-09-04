#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 19191919, MM = 19;

string mn = string(MM, '9'), mx = string(MM, '0');
string s, tmp = string(MM, 0);

struct trie {
	static const int CC = 10;
	int nxt[NN][CC], nc, rt;
	
	int make() {
		int i = CC; while(i--) nxt[nc][i] = 0;
		return nc++;
	}
	void insert() {
		int u = rt, c, i = -1;
		while(++i < MM) {
			c = s[i] - '0';
			if(!nxt[u][c]) nxt[u][c] = make();
			u = nxt[u][c];
		}
	}
	void calc() {
		int u = rt;
		for(int i = 0; i < MM; i++) {//mx
			int c = s[i] - '0', x = 0;
			for(int j = CC; j--; ) {
				if(nxt[u][j]) x = max(x, (c + j) % 10);
			}
			tmp[i] = '0' + x;
			u = nxt[u][(x - c + 10) % 10];
		}
		if(tmp > mx) mx = tmp;
		
		u = rt;
		for(int i = 0; i < MM; i++) {//mn
			int c = s[i] - '0', x = 9;
			for(int j = CC; j--; ) {
				if(nxt[u][j]) x = min(x, (c + j) % 10);
			}
			tmp[i] = '0' + x;
			u = nxt[u][(x - c + 10) % 10];
		}
		if(tmp < mn) mn = tmp;
	}
	void init() {
		nc = 0, rt = make();
	}
} tr;

void print(string s) {
	for(int i = 0; i < MM; i++) if(s[i] ^ '0') {
		for(int j = i; j < MM; j++) putchar(s[j]);
		return;
	}
	putchar('0');
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	tr.init();
	int n; scanf("%d", &n);
	while(n--) {
		INT x; scanf("%I64d", &x);
		s = string(MM, '0');
		for(int i = MM; i--; x /= 10) s[i] += x % 10;
		tr.calc(), tr.insert();
	}
	print(mn), putchar(' '), print(mx);
	return 0;
}
