#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101;

int a[NN][NN], n, H, h;
int vst[NN][NN], runs;
bool flag[NN][NN], ok;
INT sum;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool out(int x, int y) {
	return x < 1 || y < 1 || x > n || y > n;
}

void dfs(int x, int y) {
	sum += h - a[x][y], vst[x][y] = runs;
	for(int k = 4; k--; ) {
		int X = x + dx[k], Y = y + dy[k];
		if(out(X, Y)) ok = 0;
		else if(a[X][Y] < h && vst[X][Y] != runs) dfs(X, Y);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d", &n);
	vector<pii> vec(n * n);
	for(int i = 1, nn = 0; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", a[i] + j);
			vec[nn++]= {i, j};
		}
	}
	sort(vec.begin(), vec.end(), [&](pii u, pii v) {
		return a[u.x][u.y] < a[v.x][v.y];
	});
	
	INT ans = 0;
	for(int i = vec.size() - 1, j = i; i >= 0; i = j) {
		for(h = a[vec[i].x][vec[i].y]; j >= 0 && a[vec[j].x][vec[j].y] == h; j--);
		
		INT s = 0; runs++;
		for(int k = j; k >= 0; k--) {
			int x = vec[k].x, y = vec[k].y;
			if(vst[x][y] != runs) {
				ok = 1, sum = 0, dfs(x, y);
				if(ok) s += sum;
			}
		}
		if(s > ans) ans = s, H = h;
//		cerr<<"h = "<<h<<endl;
//		for(int i = 1; i <= n; i++, puts("")) for(int j = 1; j <= n; j++) cout<<flag[i][j];
	}
	cout<<H<<' '<<ans<<endl;
	return 0;
}