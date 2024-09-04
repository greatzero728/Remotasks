#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int r; cin>>r;
	
	if(r <= 1600) r = 3;
	else if (r <= 1900) r = 2;
	else r = 1;
	string s; cin>>s;
	for(int i = 0; i < s.size(); i++) if(s[i] - '0' == r) {
		cout<<r<<endl; return 0;
	}
	
	for(int i = 0; i < s.size(); i++) {
		if(s[i] - '0' < r) cout<<s[i]<<endl;
		else cout<<s[i]<<"*"<<endl;
	}
	return 0;
}