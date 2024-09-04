#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

string s[1010];

int main() {
	freopen("in.txt", "w", stdout);
	
	srand(time(0));
	
	int n = 100, m = 1000;
	for(int i = 0; i < n; i++) {
		int len = rnd % 1000 + 1;
		for(int j = len; j--; ) s[i] += rnd % 26 + 'a';
		s[i][0] = rnd % 26 + 'A';
	}
	for(int i = n; i < m; i++) s[i] = s[rnd % n];
	random_shuffle(s, s + m);
	
	printf("%d %d\n", n, m);
	for(int i = 0; i < m; i++) {
		printf("%s %d\n", s[i].c_str(), rnd % 1000 + 1);
	}
	return 0;
}
