#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using psi = pair<string, int>;

const int NN = 17, inf = 0x3f3f3f3f;

string s;
vector<string> vec[NN];
vector<int> dp[NN], mx_dp[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int id = 0; id < n; id++) {
		cin>>s;
		for(int k = 1 << s.size(); --k; ) {
			vec[id].push_back("");
			for(int j = 0; j < s.size(); j++) if(k & (1 << j)) {
				vec[id].back() += s[j];
			}
		}
		sort(vec[id].begin(), vec[id].end());
		dp[id] = mx_dp[id] = vector<int>(vec[id].size(), 0);
	}
	
	for(int i = 0; i < vec[0].size(); i++) {
		dp[0][i] = mx_dp[0][i] = vec[0][i].size();
		if(i) mx_dp[0][i] = max(mx_dp[0][i], mx_dp[0][i - 1]);
	}
	
	for(int id = 1; id < n; id++) {
		for(int i = 0, j = -1; i < vec[id].size(); i++) {
			while(j + 1 < vec[id - 1].size() && vec[id - 1][j + 1] < vec[id][i]) j++;
			if(~j && j < vec[id - 1].size() && vec[id - 1][j] < vec[id][i]) {
				dp[id][i] = mx_dp[id][i] = mx_dp[id - 1][j] + vec[id][i].size();
			}
			else dp[id][i] = mx_dp[id][i] = -inf;
			if(i) mx_dp[id][i] = max(mx_dp[id][i], mx_dp[id][i - 1]);
		}
	}
	if(mx_dp[n - 1].back() > 0) printf("%d\n", mx_dp[n - 1].back());
	else puts("-1");
	return 0;
}