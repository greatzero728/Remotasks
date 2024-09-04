#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using DO = long double;

const DO eps = 1e-7;

void in(int &x) {
	string s;
	cin>>s;
	x = 0;
	for(int i = 0; i < s.size(); i++) if(s[i] ^ '.') {
		x = x * 10 + s[i] - '0';
	}
}
void calc(int a, int b, int A, int B) {
	if(a <= A && b <= B) puts("YES"), exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("bricks.in", "r", stdin);
	freopen("bricks.out", "w", stdout);
#endif
	
	int A, B, C; in(A), in(B), in(C);
	int D, E; in(D), in(E);
	
	calc(A, B, D, E);
	calc(A, C, D, E);
	calc(B, A, D, E);
	calc(B, C, D, E);
	calc(C, A, D, E);
	calc(C, B, D, E);
	puts("NO");
	
	return 0;
}
