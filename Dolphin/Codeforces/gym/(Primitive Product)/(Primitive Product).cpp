#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

INT N, ori;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("product.in", "r", stdin);
	freopen("product.out", "w", stdout);
#endif
	
	cin>>N, ori = N;
	vector<INT> vec, a;
	for(INT i = 2; i * i <= ori; i++) {
		while(N % i == 0) vec.push_back(i), N /= i;
	}
	if(N > 1) vec.push_back(N);
	int n; a.resize(n = vec.size());
	
	vector<vector<INT> > ans;
	for(int k = 1 << n; k--; ) if(__builtin_popcount(k) % 2 == 0) {
		for(int i = n; i--; ) {
			a[i] = vec[i];
			if(k & (1 << i)) a[i] = -a[i];
		}
		sort(a.begin(), a.end()), ans.push_back(a);
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	
	printf("%d\n", ans.size());
	for(vector<INT> vec : ans) {
		for(INT x : vec) printf("%I64d ", x);
		puts("");
	}
	return 0;
}