#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 100000000;

int flag[NN], runs = 1;
vector<int> vec(5761456);

void init() {
	vec[0] = 0;
	for(int i = 2, nn = 1; i < NN; i++) if(!flag[i]) {
		vec[nn++] = i;
		if((INT)i * i >= NN) continue;
		for(int j = i * i; j < NN; j += i) flag[j] = 1;
	}
}

int solve() {
	int n, L, R; scanf("%d %d %d", &n, &L, &R);
	int ans = R, id = upper_bound(vec.begin(), vec.end(), R) - vec.begin() - 1;
	runs++;
	while(n--) {
		int x; scanf("%d", &x);
		flag[x] = runs;
	}
	for(int i = id; i >= 0 && vec[i] >= L; i--) if(flag[vec[i]] != runs) {
		ans = vec[i]; break;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	init();
	
	int t; scanf("%d", &t);
	while(t--) printf("%d\n", solve());
	return 0;
}
