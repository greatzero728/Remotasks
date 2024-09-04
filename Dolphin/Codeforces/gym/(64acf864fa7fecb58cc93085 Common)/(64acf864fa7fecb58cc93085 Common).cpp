#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char mp[] = "nhrxkeyoqmjbduvapwgzficstl";

char s[101010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	scanf("%s", s);
	for(int i = 0; s[i]; i++) putchar(mp[s[i] - 'a']);
	return 0;
}
