#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	string s;
	map<string, int> mp;
	int n; scanf("%d", &n);
	while(n--) {
		scanf("%*s");
		cin>>s;
		mp[s]++;
	}
	int num = 0;
	for(auto p : mp) {
		if(p.y >= 3) printf("%s\n", p.x.c_str()), num++;
	}
	if(!num) puts("NONE");
	return 0;
}
