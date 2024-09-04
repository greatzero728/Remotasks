#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

char s[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int n, a, b; scanf("%d %d %d %s", &n, &a, &b, s + 1);
	
	vector<pii> two;
	vector<int> one;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			if(two.empty() || two.back().y) two.push_back({i, 0});
			else two.back().y = i;
		}
		else one.push_back(i);
	}
	while(two.size() > b) {
		pii p = two.back(); two.pop_back();
		if(p.x) one.push_back(p.x);
		if(p.y) one.push_back(p.y);
	}
	while(two.size() < b) two.push_back({0, 0});
	
	while(one.size() < a) one.push_back(0);
	
	reverse(two.begin(), two.end());
	int id = 0;
	while(one.size() > a) {
		int u = one.back(); one.pop_back();
		if(id < two.size() && !two[id].x) two[id++] = {u, 0};
		else {one.push_back(u); break;}
	}
	
	if(one.size() == a) {
		puts("YES");
		for(int x : one) printf("%d\n", x);
		for(pii p : two) printf("%d %d\n", p.x, p.y);
	}
	else puts("NO");
	return 0;
}