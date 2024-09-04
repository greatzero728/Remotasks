#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	string s; cin>>s;
	sort(s.begin(), s.end());
	if(s[0] == s.back()) printf("%d\n", s.size() - 1);
	else puts("0");
	return 0;
}
