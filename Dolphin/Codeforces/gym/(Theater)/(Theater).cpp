#include<bits/stdc++.h>	

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define inf 1e99
#define m 15
#define mm (1 << m)

double w, h, v1, v2, x[m], y[m], ans = inf, d[m + 2][m + 2], g[mm][2][2], f[mm][m + 2][2];
int n, k, o[mm][m];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("theater.in", "r", stdin);
	freopen("theater.out", "w", stdout);
#endif
	
	scanf("%lf%lf%lf%lf%d", &h, &w, &v1, &v2, &n);
	forn (i, n){
		scanf("%lf%lf", &x[i], &y[i]);
	}
	memset(o, 0, sizeof(o));
	scanf("%d", &k);
	forn (i, k) {
		int a, b;
		scanf("%d", &a);
		while (a--) {
			scanf("%d", &b);
			assert(1 <= b && b <= n);
			o[i][b - 1] = 1;
		}
	}
	memset(d, 0, sizeof(d));
	forn (i, n) forn (j, n)
	d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	forn (i, n)
	d[i][n] = d[n][i] = x[i], d[i][n + 1] = d[n + 1][i] = w - x[i];
	d[n][n + 1] = d[n + 1][n] = w;
	forn (i, (1 << n)) forn (j, n + 2) forn (q, 2){
		f[i][j][q] = inf;
		if (i == 0) f[i][j][q] = d[j][q + n];
		else forn (e, n) if ((i >> e) & 1) f[i][j][q] = min(f[i][j][q], f[i ^ (1 << e)][e][q] + d[j][e]);
	}
	forn (i, k) forn (a, 2) forn (b, 2)
	g[i][a][b] = inf;
	g[0][0][1] = 0;
	forn (i, k - 1) {
		int p1 = 0, p2 = 0;
		forn (j, n)
		if (!o[i][j] && o[i + 1][j]) p1 |= 1 << j;
		else if (o[i][j] && !o[i + 1][j]) p2 |= 1 << j;
		forn (a, 2) forn (b, 2) forn (c, 2) forn (d, 2)
		g[i + 1][c][d] = min(g[i + 1][c][d], g[i][a][b] + max(f[p1][a + n][c] / v1, f[p2][b + n][d] / v2));
	}
	forn (a, 2) forn (b, 2)
	ans = min(ans, g[k - 1][a][b]);
	printf("%.9lf\n", ans);
	return 0;
}