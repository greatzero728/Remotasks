#include <bits/stdc++.h>

using namespace std;

const int di[] = {0, 0, 1,-1};
const int dj[] = {1,-1, 0, 0};

int n, m, t, ans;
bool tried[100][100];
vector<pair<int, int>> now;

void solve(int t) {
	if(t == 0) {
		ans++;
		return;
	}
	vector<pair<int, int>> mem;
	for(int it = 0; it < now.size(); it++)
		for(int w = 0; w < 4; w++) {
			int i = now[it].first + di[w], j = now[it].second + dj[w];
			if(i >= 0 && i < n && j >= 0 && j < m && !tried[i][j]) {
				tried[i][j] = true;
				now.push_back({i, j});
				solve(t - 1);
				now.pop_back();
				mem.push_back({i, j});
			}
		}
	for(pair<int, int> cell : mem)
		tried[cell.first][cell.second] = false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("virus.in", "r", stdin);
	freopen("virus.out", "w", stdout);
#endif
	
	cin >> n >> m >> t;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if(ch == '*') {
				now.push_back({i, j});
				tried[i][j] = true;
			}
		}
	solve(t);
	cout << ans;
}