#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

int num[NN];
char s[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%*d %s", s);
	for(int i = 0; s[i]; i++) num[s[i] - 'a']++;
	for(int i = 26; i--; ) if(num[i] > 1) {
		puts("NO"); exit(0);
	}
	puts("YES");
	return 0;
}
