#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 212;

char s[NN][NN], a[NN][NN];

int n, m;

void init() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) a[i][j] = '.';
	}
}

bool same() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i][j] ^ a[i][j]) return 0;
		}
	}
	return 1;
}

int vst[NN][NN], runs;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int xmn, xmx, ymn, ymx, sz;

bool out(int x, int y) {
	return x < 1 || y < 1 || x > n || y > m;
}

void dfs(int x, int y) {
	sz++;
	xmn = min(xmn, x), xmx = max(xmx, x);
	ymn = min(ymn, y), ymx = max(ymx, y);
	for(int k = 4; k--; ) {
		int X = x + dx[k], Y = y + dy[k];
		if(!out(X, Y) && s[X][Y] == '#' && vst[X][Y] != runs) {
			vst[X][Y] = runs, dfs(X, Y);
		}
	}
}

void update(int xmn, int xmx, int ymn, int ymx, char c = '#') {
	for(int i = xmn; i <= xmx; i++) {
		for(int j = ymn; j <= ymx; j++) {
			if(a[i][j] == '#') c = 0;
			a[i][j] = c;
		}
	}
}

void print() {
	puts("YES");
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) putchar(a[i][j]);
		puts("");
	}
}

bool is_full(int xmn, int xmx, int ymn, int ymx) {
	for(int i = xmn; i <= xmx; i++) {
		for(int j = ymn; j <= ymx; j++) {
			if(s[i][j] ^ '#') return 0;
		}
	}
	return 1;
}

void get_y_st_ed(int xmn, int xmx, int y, int &st, int &ed) {
	for(int i = xmn, j = xmn; i <= xmx; i = j) {
		for(; j <= xmx && s[i][y] == s[j][y]; j++);
		if(s[i][y] == '#') {
			st = i, ed = j - 1; return;
		}
	}
	st = ymn, ed = ymx;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout);
#endif
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	
	runs++;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) if(s[i][j] == '#' && vst[i][j] != runs) {
			vst[i][j] = runs, dfs(i, j), cnt++;
		}
	}
	if(cnt > 2) puts("NO"), exit(0);
	
	if(cnt == 2) {
		init(), runs++;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) if(s[i][j] == '#' && vst[i][j] != runs) {
				xmn = n, xmx = 1, ymn = m, ymx = 1;
				vst[i][j] = runs, dfs(i, j);
				update(xmn, xmx, ymn, ymx);
			}
		}
		
		if(same()) {
			char c = 'a';
			init(), runs++;
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) if(s[i][j] == '#' && vst[i][j] != runs) {
					xmn = n, xmx = 1, ymn = m, ymx = 1;
					vst[i][j] = runs, dfs(i, j);
					update(xmn, xmx, ymn, ymx, c++);
				}
			}
			print();
		}
		else puts("NO");
		return 0;
	}
	
	if(cnt == 0) puts("NO"), exit(0);
	
	runs++;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) if(s[i][j] == '#' && vst[i][j] != runs) {
			xmn = n, xmx = 1, ymn = m, ymx = 1;
			sz = 0, vst[i][j] = runs, dfs(i, j);
			break;
		}
	}
	if((xmx - xmn + 1) * (ymx - ymn + 1) == sz) {
		init();
		if(xmn < xmx) {
			update(xmn, xmn, ymn, ymx, 'a');
			update(xmn + 1, xmx, ymn, ymx, 'b');
			print();
		}
		else if(ymn < ymx) {
			update(xmn, xmx, ymn, ymn, 'a');
			update(xmn, xmx, ymn + 1, ymx, 'b');
			print();
		}
		else puts("NO");
		return 0;
	}
	
	if(is_full(xmn, xmx, ymn, ymn)) {
		for(int j = ymn + 1; j <= ymx; j++) if(!is_full(xmn, xmx, j, j)) {
			init();
			update(xmn, xmx, ymn, j - 1);
			
			int st, ed;
			get_y_st_ed(xmn, xmx, j, st, ed);
			update(st, ed, j, ymx);
			
			if(same()) {
				init();
				update(xmn, xmx, ymn, j - 1, 'a');
				update(st, ed, j, ymx, 'b');
				print();
			}
			else puts("NO");
			return 0;
		}
	}
	
	for(int j = ymn + 1; j <= ymx; j++) if(is_full(xmn, xmx, j, j)) {
		init();
		
		int st, ed;
		get_y_st_ed(xmn, xmx, ymn, st, ed);
		update(st, ed, ymn, j - 1);
		
		update(xmn, xmx, j, ymx);
		
		if(same()) {
			init();
			update(st, ed, ymn, j - 1, 'a');
			update(xmn, xmx, j, ymx, 'b');
			print();
			return 0;
		}
		
		for(int k = j + 1; k <= ymx; k++) if(!is_full(xmn, xmx, k, k)) {
			init();
			
			update(st, ed, ymn, k - 1);
			
			int sst, eed;
			get_y_st_ed(xmn, xmx, k, sst, eed);
			update(sst, eed, j, ymx);
			
			if(same()) {
				init();
				update(st, ed, ymn, k - 1, 'a');
				update(sst, eed, j, ymx, 'b');
				print();
				return 0;
			}
			
			
			init();
			
			update(st, ed, ymn, ymx);
			
			sst = xmn, eed = xmx;
			if(st == xmn) sst = ed + 1;
			else eed = st - 1;
			update(sst, eed, j, k - 1);
			
			if(same()) {
				init();
				update(st, ed, ymn, ymx, 'a');
				update(sst, eed, j, k - 1, 'b');
				print();
				return 0;
			}
			break;
		}
		puts("NO"), exit(0);
	}
	
	int st, ed;
	get_y_st_ed(xmn, xmx, ymn, st, ed);
	for(int j = ymn + 1; j <= ymx; j++) if(!is_full(st, ed, j, j)) {
		init();
		update(st, ed, ymn, j - 1);
		
		int sst, eed;
		get_y_st_ed(xmn, xmx, j, sst, eed);
		update(sst, eed, j, ymx);
		
		if(same()) {
			init();
			update(st, ed, ymn, j - 1, 'a');
			update(sst, eed, j, ymx, 'b');
			print();
		}
		else puts("NO");
		return 0;
	}
	return 0;
}