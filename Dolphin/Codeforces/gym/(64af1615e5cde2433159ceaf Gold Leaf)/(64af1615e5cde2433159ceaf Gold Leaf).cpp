#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

char s[NN][NN];
int n, m;

bool out(int x, int y) {
	return x < 1 || y < 1 || x > n || y > m;
}

bool fold_row(int sum) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int I = sum - i, J = j, cnt = s[i][j] == '#';
			if(!out(I, J) && s[I][J] == '#') cnt++;
			if(cnt != 1) return 0;
		}
	}
	return 1;
}

bool fold_col(int sum) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int I = i, J = sum - j, cnt = s[i][j] == '#';
			if(!out(I, J) && s[I][J] == '#') cnt++;
			if(cnt != 1) return 0;
		}
	}
	return 1;
}

bool fold_dia(int sum) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(i + j == sum) {
				if(s[i][j] == '.') return 0;
			}
			else {
				int I_and_J = sum + sum - (i + j), I_sub_J = i - j;
				int I = I_and_J + I_sub_J >> 1, J = I_and_J - I_sub_J >> 1, cnt = s[i][j] == '#';
				if(!out(I, J) && s[I][J] == '#') cnt++;
				if(cnt != 1) return 0;
			}
		}
	}
	return 1;
}

bool fold_un_dia(int sub) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(j - i == sub) {
				if(s[i][j] == '.') return 0;
			}
			else {
				int I = j - sub, J = sub + i, cnt = s[i][j] == '#';
				if(!out(I, J) && s[I][J] == '#') cnt++;
				if(cnt != 1) return 0;
			}
		}
	}
	return 1;
}

using ppp = pair<pii, pii>;

vector<ppp> ans;

void solve() {
	ans.clear();
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	for(int k = 1; k < n; k++) {
		if(fold_row(k + k + 1)) {
			ans.push_back({{k, 1}, {k, m}});
		}
	}
	for(int k = 1; k < m; k++) {
		if(fold_col(k + k + 1)) {
			ans.push_back({{1, k}, {n, k}});
		}
	}
	for(int k = 2; k <= n + m - 2; k++) {
		if(fold_dia(k + 1)) {
			ans.push_back({{0, 0}, {0, 0}});
			if(k <= n) ans.back().x = {k, 1};
			else ans.back().x = {n, k - n + 1};
			
			if(k <= m) ans.back().y = {1, k};
			else ans.back().y = {k - m + 1, m};
		}
	}
	for(int sub = 1 - (n - 1); sub <= (m - 1) - 1; sub++) {
		if(fold_un_dia(sub)) {
			ans.push_back({{0, 0}, {0, 0}});
			if(sub <= 0) ans.back().x = {1 - sub, 1};
			else ans.back().x = {1, 1 + sub};
			
			if(sub <= 0) ans.back().y = {n, n + sub};
			else ans.back().y = {m - sub, m};
		}
	}
	sort(ans.begin(), ans.end());
	if(ans.empty()) printf("%d %d %d %d\n", 1, 1, 1, m);
	else printf("%d %d %d %d\n", ans[0].x.x, ans[0].x.y, ans[0].y.x, ans[0].y.y);
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}
