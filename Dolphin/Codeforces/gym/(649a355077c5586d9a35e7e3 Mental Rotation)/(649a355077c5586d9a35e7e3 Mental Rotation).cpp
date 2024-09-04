#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int n;
const int NN = 1010;

char s[121], a[NN][NN], b[NN][NN];

void left() {
	int I = 1, J = 1;
	for(int j = n; j >= 1; j--) {
		for(int i = 1; i <= n; i++) {
			if(J == n + 1) I++, J = 1;
			b[I][J++] = a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(b[i][j] == '^') a[i][j] = '<';
			if(b[i][j] == '<') a[i][j] = 'v';
			if(b[i][j] == 'v') a[i][j] = '>';
			if(b[i][j] == '>') a[i][j] = '^';
			if(b[i][j] == '.') a[i][j] = '.';
		}
	}
}

void right() {
	int I = 1, J = 1;
	for(int j = 1; j <= n; j++) {
		for(int i = n; i >= 1; i--) {
			if(J == n + 1) I++, J = 1;
			b[I][J++] = a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(b[i][j] == '^') a[i][j] = '>';
			if(b[i][j] == '>') a[i][j] = 'v';
			if(b[i][j] == 'v') a[i][j] = '<';
			if(b[i][j] == '<') a[i][j] = '^';
			if(b[i][j] == '.') a[i][j] = '.';
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %s", &n, s);
	int nl = 0, nr = 0;
	for(int i = 0; s[i]; i++) {
		if(s[i] == 'L') nl++;
		else nr++;
	}
	int mn = min(nl, nr);
	nl -= mn, nr -= mn;
	
	for(int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	
	while(nl--) left();
	while(nr--) right();
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) putchar(a[i][j]);
		puts("");
	}
	return 0;
}