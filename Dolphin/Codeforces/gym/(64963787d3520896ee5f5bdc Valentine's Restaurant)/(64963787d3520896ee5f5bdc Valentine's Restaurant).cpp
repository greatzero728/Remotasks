#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char s[1010];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%s", s);
	int ans = 0, nn = 0;
	for(int i = 0; s[i]; i++) {
		if(s[i] == '[') nn++;
		else ans = max(ans, nn--);
	}
	printf("%d\n", ans);
	return 0;
}
