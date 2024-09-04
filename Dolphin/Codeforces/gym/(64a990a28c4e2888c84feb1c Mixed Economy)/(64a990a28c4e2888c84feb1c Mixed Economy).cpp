#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

pii p[NN];
char str[1010];
int ans[121];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int n; scanf("%*d %d", &n);
	map<string, int> mp;
	int nn = 0;
	for(int i = 0; i < n; i++) {
		scanf("%s %d", str, &p[i].y);
		if(mp.find(str) == mp.end()) mp[str] = nn++;
		p[i].x = mp[str];
	}
	
	for(int i = nn; i--; ) ans[i] = 100;
	
	int len = 0, id;
	for(int i = 0, j = 0; i < n; i = j) {
		for(; j < n && p[i].x == p[j].x; j++) ans[p[j].x] -= p[j].y;
		if(j - i > len) len = j - i, id = p[i].x;
	}
	
	for(int i = nn; i--; ) {
		if(i == id) ans[i] -= len * (nn - 1);
		else ans[i] += len;
	}
	
	int mn = ans[0], mx = mn;
	for(int i = 1; i < nn; i++) {
		if(ans[i] < mn) mn = ans[i];
		if(ans[i] > mx) mx = ans[i];
	}
	cout<<mx - mn<<endl;
	return 0;
}
